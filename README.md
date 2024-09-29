# ComLiveLinkBlender

ドキュメント
https://com04.sakura.ne.jp/cll/wiki/index.php

α版につき簡易説明になります。

# 初期設定
## プロジェクトへの適用
### UE5 側の設定
1. ZIPで落としてきたプラグインを解凍して、中身の「ComLiveLink」フォルダをプロジェクトの /Plugins/ フォルダの中に入れます
2. UEエディターを起動します

### Blender 側の設定
1. 解凍した中にある「ComLiveLink/Tools/addons/ComLiveLinkBlender.py」をBlenderにaddonとしてInstallしてください。
2. 「Preferences」の「Add-ons」で「LiveLink: ComLiveLinkBlender」を有効化してください
3. 右側に「LiveLink」タブに「Blender to UE5」が出ます。

## 使い方

### UE5 側
1. Animationブループリントで「CLiveLink」ノードを繋ぎます。このノードで受信してポーズを再現します。
2. 「SubjectName」は後述のBlender側の設定と合わせてください。
3. シーンに配置して、PIEします

### Blender 側
1. 「LiveLink」タブの「Blender to UE5」で設定します。
2. 「Subject」を前述のUE5のABP「CLiveLink」ノードのSubject名と合わせます。
3. 「Live Link Start」ボタンを押します。
4. Object モードで対象のボーンを選択します。
5. Pose モードに切り替えてボーンを動かすと、UE5側に反映されます。


# 予定
+ ポーズのリセット
+ LiveLinkノードの前にポーズがあると、上書きでなく加算で出て崩れてしまう。いい感じに。
+ デバッグ
  + ボーン構成が違うもの
  + Blender側から送信後、UE5側動かした時
+ シーケンサー周りのいい感じの対応
+ 頂点データもやりたいけど……ちょっと難しい……
