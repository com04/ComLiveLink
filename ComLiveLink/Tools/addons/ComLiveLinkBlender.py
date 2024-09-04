bl_info = {
    "name": "ComLiveLinkBlender",
    "author": "com04",
    "version": (0, 1),
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


class CLBVariables:
	# 更新間隔。パケットの送信間隔
	link_interval = 0.1
	# 現在 LiveLinkを実行中か
	run_livelink = False
clb_var = CLBVariables()


# プロパティ。設定類
#
class CLBProperty(bpy.types.PropertyGroup):
	# IPアドレス
	ip_address : bpy.props.StringProperty(name = 'IP Address', default = '127.0.0.1')
	# ポート番号
	port : bpy.props.IntProperty(name = 'Port', default = 2000)
	# 固有の識別名
	subject : bpy.props.StringProperty(name = 'Subject', default = 'Animation')
	# LiveLink種類
	type : bpy.props.EnumProperty(name = 'Type', default=ECLLControlType.Pose.name, items =
		[
			(ECLLControlType.Pose.name, ECLLControlType.Pose.name, ''),
			(ECLLControlType.Animation.name, ECLLControlType.Animation.name, ''),
		])
	# オプション設定
	optional : bpy.props.BoolProperty(default = False)


# Live link実体
class CLBLink(bpy.types.Operator):
	bl_idname = "clb.live_link"
	bl_label = "Modal Timer Operator Skeletal"
	bl_options = {"UNDO"}

	udp_socket = None
	timer_event = None

	def modal(self, context, event):
		property = context.scene.property

		# Live Link停止
		if clb_var.run_livelink == False:
			self.cancel(context)
			print('CANCELLED')
			return {'CANCELLED'}
		
		params = {}

		# Pose
		if property.type == ECLLControlType.Pose.name:
			bone_transforms = {}
			objects = bpy.context.selected_objects
			for object in objects:
				if object.type != 'ARMATURE':
					continue
				# pose. リファレンスポーズからの差分
				for bone in bpy.data.objects[object.name].pose.bones:
					location = bone.location
					quaternion = bone.rotation_quaternion
					scale = bone.scale
					# Blender の Armature は Y front. UE5 には X front で投げる
					# 軸変更出来た方が良い
					transform = [-quaternion.y, quaternion.x, quaternion.z, quaternion.w]
					
					need_scale = scale != mathutils.Vector((1,1,1))
					need_location = (location != mathutils.Vector((0,0,0))) or need_scale
					if need_location == True:
						transform += [location.y, -location.x, -location.z]
					if need_scale == True:
						if len(transform) < 7:
							print("error");
						transform += [scale.x, scale.y, scale.z]
					bone_transforms[bone.name] = transform
			if len(bone_transforms) == 0:
				print('PASS_THROUGH')
				return {'PASS_THROUGH'}
			
			params['bone_transforms'] = bone_transforms;
		# todo
		# elif property.type == ECLLControlType.Animation.name:
			# pass
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
		self.udp_socket.sendto(json_data, addr)
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
		
		row = layout.row()
		start_button = row.box()

		text = 'Live Link Start'
		icon = 'RADIOBUT_OFF'
		if clb_var.run_livelink == True:
			text = 'Stop'
			icon = 'RADIOBUT_ON'
		start_button.operator(CLBLink.bl_idname, text=text,icon=icon)
		
		optional_header, optional_panel = layout.panel_prop(property, "optional")
		optional_header.label(text='Option')
		if optional_panel:
			optional_panel.prop(property, "ip_address")
			optional_panel.prop(property, "port")

register_classes = [CLBProperty, CLBLink, CLB_PT_Panel]

# 初期化処理
#
def register():
	for register_class in register_classes:
		bpy.utils.register_class(register_class)

	bpy.types.Scene.property = bpy.props.PointerProperty(type = CLBProperty)


# 終了処理
#
def unregister():
	for register_class in register_classes:
		bpy.utils.unregister_class(register_class)
	
	del bpy.types.Scene.property

if __name__ == "__main__":
	register()
