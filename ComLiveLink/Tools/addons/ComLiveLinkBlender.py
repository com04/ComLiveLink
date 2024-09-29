bl_info = {
    "name": "ComLiveLinkBlender",
    "author": "com04",
    "version": (0, 1, 1),
    "blender": (4, 1, 0),
    "location": "View3D > LiveLink",
    "description": "",
    "doc_url": "",
    "category": "LiveLink",
}

import bpy
import math
import mathutils
import struct
import json
from socket import *
from enum import Enum


class ECLLControlType(Enum):
	# ポーズ
	Pose = 1

class ECLLAxisType(Enum):
	Plus_X  = 0
	Minus_X = 1
	Plus_Y  = 2
	Minus_Y = 3
	Plus_Z  = 4
	Minus_Z = 5


class CLBVariables:
	# 更新間隔。パケットの送信間隔
	link_interval = 0.1
	# 現在 LiveLinkを実行中か
	run_livelink = False
clb_var = CLBVariables()


# プロパティ。設定類
#
class CLBProperty(bpy.types.PropertyGroup):
	
	axis_items = [
			(ECLLAxisType.Plus_X.name,  '+X', ''),
			(ECLLAxisType.Minus_X.name, '-X', ''),
			(ECLLAxisType.Plus_Y.name,  '+Y', ''),
			(ECLLAxisType.Minus_Y.name, '-Y', ''),
			(ECLLAxisType.Plus_Z.name,  '+Z', ''),
			(ECLLAxisType.Minus_Z.name, '-Z', ''),
		]

	# 固有の識別名
	subject : bpy.props.StringProperty(name = 'Subject', default = 'Animation')
	# LiveLink種類
	type : bpy.props.EnumProperty(name = 'Type', default=ECLLControlType.Pose.name, items =
		[
			(ECLLControlType.Pose.name, ECLLControlType.Pose.name, ''),
		])

	# Pose Option設定
	pose_option : bpy.props.BoolProperty(default = True)
	# Pose Option/対象のArmature名
	pose_armature_name : bpy.props.StringProperty(name = bpy.app.translations.pgettext('Target Armature Name'), default = '')
	# Pose Option/パケットの分割。最大ボーン数
	pose_packet_max_bones_per_frame : bpy.props.IntProperty(name = bpy.app.translations.pgettext('Send max bones per frame'), default = 20)
	
	# 詳細設定
	advanced : bpy.props.BoolProperty(default = False)
	# Advanced/パケットオプション設定
	packet_option : bpy.props.BoolProperty(default = False)
	# Advanced/Packet Option/IPアドレス
	ip_address : bpy.props.StringProperty(name = 'IP Address', default = '127.0.0.1')
	# Advanced/Packet Option/ポート番号
	port : bpy.props.IntProperty(name = 'Port', default = 2000)
	# Advanced/Axis Option
	axis_option : bpy.props.BoolProperty(default = False)
	# Advanced/Axis Option/軸設定
	# todo: いい感じの軸変換が出来るまでの繋ぎ仮設定。 A temporary setting until a good axis conversion is achieved.
	axis_quat_x : bpy.props.EnumProperty(name = 'Quaternion X', default=ECLLAxisType.Minus_Y.name, items = axis_items)
	axis_quat_y : bpy.props.EnumProperty(name = 'Quaternion Y', default=ECLLAxisType.Plus_X.name, items = axis_items)
	axis_quat_z : bpy.props.EnumProperty(name = 'Quaternion Z', default=ECLLAxisType.Plus_Z.name, items = axis_items)
	axis_loc_x : bpy.props.EnumProperty(name = 'Location X', default=ECLLAxisType.Plus_Y.name, items = axis_items)
	axis_loc_y : bpy.props.EnumProperty(name = 'Location Y', default=ECLLAxisType.Minus_X.name, items = axis_items)
	axis_loc_z : bpy.props.EnumProperty(name = 'Location Z', default=ECLLAxisType.Minus_Z.name, items = axis_items)
	
	

	# 送信対象Armature
	send_armatures : bpy.props.StringProperty(name = bpy.app.translations.pgettext('Sending Armatures'), default = '')

# 日本語用辞書
# see. https://colorful-pico.net/introduction-to-addon-development-in-blender/2.8/html/chapter_03/06_Support_Multiple_Languages.html
translation_dict = {
	"ja_JP" :
		{
			("*", "Target Armature Name") : "対象Armature名",
			("*", "Sending Armatures") : "送信中Armatures",
			("*", "Axis Option") : "軸変換 Option",
			("*", "Send max bones per frame") : "1フレームの最大ボーン送信数",
			("*", "You may be hitting the transmission limit. Try lowering the [Send max bones per frame].") : "送信数制限に引っかかっている可能性があります。「1フレームの最大ボーン送信数」を下げてみてください。",
		},
}


# Live link実体
class CLBLink(bpy.types.Operator):
	bl_idname = "clb.live_link"
	bl_label = "Modal Timer Operator Skeletal"
	bl_options = {"UNDO"}

	udp_socket = None
	timer_event = None
	# dict[object.name] - list[bone.name]
	accum_object_bones = {}

	def modal(self, context, event):
		property = context.scene.property
		property.send_armatures = ''

		# Live Link停止
		if clb_var.run_livelink == False:
			self.cancel(context)
			print('CANCELLED')
			return {'CANCELLED'}
		
		params = {}

		# Pose
		if property.type == ECLLControlType.Pose.name:
			bone_transforms = {}
			objects = []
			if property.pose_armature_name != '':
				if property.pose_armature_name in bpy.data.objects:
					objects = [bpy.data.objects[property.pose_armature_name]]
			else:
				objects = bpy.context.selected_objects

			# このフレームで読み込んだボーン数
			num_read_bone = 0;
			# このフレームで読み込めるボーン上限数を読み込んだか。Property.pose_packet_max_bones_per_frame
			finish_max_read_bone = False
			for object in objects:
				if object.type != 'ARMATURE':
					continue
				property.send_armatures += object.name + ', '

				accum_bones = []
				# 途中まで読み込んだ分。この続きから読み込む
				if object.name in self.accum_object_bones:
					accum_bones = self.accum_object_bones[object.name]

				# pose. リファレンスポーズからの差分
				for bone in bpy.data.objects[object.name].pose.bones[len(accum_bones):]:

					# Rig等でボーンを直接操作されない場合はRefPoseのまま。matrixには値が入る
					'''
					location = bone.location
					quaternion = bone.rotation_quaternion
					scale = bone.scale
					'''
					# WORLDだとObject自体の値が入っている場合に反映されてしまう。スケール0.01など
					'''
					matrix = object.convert_space(pose_bone=bone, matrix=bone.matrix, to_space='LOCAL', from_space='WORLD')
					'''
					matrix = object.convert_space(pose_bone=bone, matrix=bone.matrix, to_space='LOCAL', from_space='POSE')
					location = matrix.to_translation()
					quaternion = matrix.to_quaternion()
					scale = matrix.to_scale()
					
					# Blender の Armature は Y front. UE5 には X front で投げる
					# 軸変更出来た方が良い
					# transform = [-quaternion.y, quaternion.x, quaternion.z, quaternion.w] # UE5 quinn
					# transform = [-quaternion.x, -quaternion.z, -quaternion.y, quaternion.w]
					transform = [
							self.getAxisValue(property.axis_quat_x, quaternion),
							self.getAxisValue(property.axis_quat_y, quaternion),
							self.getAxisValue(property.axis_quat_z, quaternion),
							quaternion.w
						]
					
					need_scale = scale != mathutils.Vector((1,1,1))
					need_location = (location != mathutils.Vector((0,0,0))) or need_scale
					if need_location == True:
						# transform += [location.y, -location.x, -location.z] # UE5 quinn
						# transform += [location.x, location.z, -location.y]
						transform += [
								self.getAxisValue(property.axis_loc_x, location),
								self.getAxisValue(property.axis_loc_y, location),
								self.getAxisValue(property.axis_loc_z, location)
							]
					if need_scale == True:
						if len(transform) < 7:
							print("error transforms");
						transform += [scale.x, scale.y, scale.z]
					
					bone_transforms[bone.name] = transform

					# 最大読み取りボーン数制御
					if property.pose_packet_max_bones_per_frame > 0:
						accum_bones += [bone.name]
						num_read_bone += 1
						if num_read_bone >= property.pose_packet_max_bones_per_frame:
							finish_max_read_bone = True
							break

				self.accum_object_bones[object.name] = accum_bones
				if finish_max_read_bone == True:
					break;
			
			# 最大値を超えずに終了したのでキャッシュをクリアする
			if property.pose_packet_max_bones_per_frame > 0:
				if finish_max_read_bone == False:
					self.accum_object_bones = {}
				params['accumulate'] = True
			
			if len(bone_transforms) == 0:
				# print('PASS_THROUGH')
				return {'PASS_THROUGH'}
			
			params['bone_transforms'] = bone_transforms
			# print('transform Num = ' + str(len(bone_transforms)))
		else:
			print('Unknown control type: ' + property.type)
			return {'PASS_THROUGH'}

		data = {}
		data['header'] = 'CLL'
		data['subject'] = property.subject
		data['type'] = ECLLControlType[property.type].value
		data['params'] = params

		addr = (property.ip_address, property.port)
		json_data = json.dumps(data).encode('utf-8')
		try:
			self.udp_socket.sendto(json_data, addr)
		except OSError as e:
			clb_var.run_livelink = False
			except_message = str(e)
			# WinError 10040 データグラム ソケットで送信されたメッセージが、内部のメッセージのバッファーまたはほかのネットワークの制限を超えています。または、データグラムの受信に使われるバッファーがデータグラムより小さく設定されています。
			# 1回のパケット送信量が大きいので、パケット分割を勧める（本来は自動的にパケット分割するが良い）
			if '10040' in except_message:
				message = bpy.app.translations.pgettext("You may be hitting the transmission limit. Try lowering the [Send max bones per frame].") + "\n" + except_message
			else:
				message = except_message
			raise OSError(message) from OSError
		except Exception as e:
			clb_var.run_livelink = False
			raise e

		return {'PASS_THROUGH'}

	def execute(self, context):
		if clb_var.run_livelink == False:
			# 一定間隔で実行
			clb_var.run_livelink = True
			self.udp_socket = socket(AF_INET, SOCK_DGRAM)
			self.timer_event = context.window_manager.event_timer_add(clb_var.link_interval, window = context.window)
			context.window_manager.modal_handler_add(self)
			return {'RUNNING_MODAL'}

		else:
			# 停止処理
			# ボタンを2回押された場合はselfは別インスタンスになるので、フラグ操作のみ。
			# 実際の停止は modal で判断
			clb_var.run_livelink = False
			return{'FINISHED'}

	def cancel(self, context):
		clb_var.run_livelink = False
		context.window_manager.event_timer_remove(self.timer_event)
		self.timer_event = None

	# 軸設定から値を取得
	def getAxisValue(self, axis_type, value):
		if axis_type == ECLLAxisType.Plus_X.name:
			return value.x
		elif axis_type == ECLLAxisType.Minus_X.name:
			return -value.x
		elif axis_type == ECLLAxisType.Plus_Y.name:
			return value.y
		elif axis_type == ECLLAxisType.Minus_Y.name:
			return -value.y
		elif axis_type == ECLLAxisType.Plus_Z.name:
			return value.z
		elif axis_type == ECLLAxisType.Minus_Z.name:
			return -value.z
		raise Exception("invalid axis type: axis_type=" + str(axis_type))
		return 0


# パネル描画
# https://docs.blender.org/api/current/bpy.types.Panel.html#bpy.types.Panel
class CLB_PT_Panel(bpy.types.Panel):
	bl_label = "Blender to UE5"
	bl_space_type = "VIEW_3D"   
	bl_region_type = "UI"    
	bl_category  = "LiveLink"
	bl_options = {"DEFAULT_CLOSED"}

	def draw(self, context):
		global GetIcon
		property  = context.scene.property

		layout = self.layout

		# https://docs.blender.org/api/current/bpy.types.UILayout.html#bpy.types.UILayout
		layout.prop(property, "type")
		layout.prop(property, "subject")

		if property.type == ECLLControlType.Pose.name:
			pose_option_header, pose_option_panel = layout.panel_prop(property, "pose_option")
			pose_option_header.label(text='Pose Option')
			if pose_option_panel:
				pose_option_panel.prop(property, "pose_packet_max_bones_per_frame")
				pose_option_panel.prop(property, "pose_armature_name")
				pose_option_panel.prop(property, "send_armatures", emboss =False)

		row = layout.row()
		start_button = row.box()

		text = 'Live Link Start'
		icon = 'RADIOBUT_OFF'
		if clb_var.run_livelink == True:
			text = 'Stop'
			icon = 'RADIOBUT_ON'
		start_button.operator(CLBLink.bl_idname, text=text,icon=icon)
		
		
		advanced_header, advanced_panel = layout.panel_prop(property, "advanced")
		advanced_header.label(text='Advanced')
		if advanced_panel:
			packet_option_header, packet_option_panel = advanced_panel.panel_prop(property, "packet_option")
			packet_option_header.label(text='Packet Option')
			if packet_option_panel:
				packet_option_panel.prop(property, "ip_address")
				packet_option_panel.prop(property, "port")

			axis_option_header, axis_option_panel = advanced_panel.panel_prop(property, "axis_option")
			axis_option_header.label(text=bpy.app.translations.pgettext('Axis Option'))
			if axis_option_panel:
				axis_option_panel.prop(property, "axis_quat_x")
				axis_option_panel.prop(property, "axis_quat_y")
				axis_option_panel.prop(property, "axis_quat_z")
				axis_option_panel.prop(property, "axis_loc_x")
				axis_option_panel.prop(property, "axis_loc_y")
				axis_option_panel.prop(property, "axis_loc_z")



register_classes = [CLBProperty, CLBLink, CLB_PT_Panel]

# 初期化処理
#
def register():
	bpy.app.translations.register(__name__, translation_dict)

	for register_class in register_classes:
		bpy.utils.register_class(register_class)

	bpy.types.Scene.property = bpy.props.PointerProperty(type = CLBProperty)


# 終了処理
#
def unregister():
	for register_class in register_classes:
		bpy.utils.unregister_class(register_class)
	
	del bpy.types.Scene.property
	bpy.app.translations.unregister(__name__)

if __name__ == "__main__":
	register()
