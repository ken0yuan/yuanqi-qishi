# 元气骑士
## 环境需求
- 安装3.5版本以上的cmake工具
- 安装Qt5版本的Qt库，不可为Qt6
- 基本的g++，gcc工具等
## 注意事项
&emsp;在本地编译时，请将CMakeLists.txt中的第5行改为你的Qt库的mingw工具的对应位置。
## 项目介绍
### 初定目标
- 角色信息包含血条蓝条盾条，盾条在不受伤害3s后自动回复，蓝条血条不可回复
- 角色攻击包含近战和远程，近战不会消耗蓝条，远程攻击消耗蓝条
- 地图信息包含墙和砖块，砖块可被打破
- 子弹分为敌方和己方，碰到墙和人就消失
- 敌方分为三类，近战类，远程类，boss类，具有一定的智力，血量
### 完成目标
- 角色包含血条盾条蓝条，均不会回复
- 角色只有消耗蓝条的射击
- 地图信息包含墙和砖块，砖块可被打破
- 子弹分为敌方和己方，碰到墙和人就消失
- 敌方分为三类，近战类，远程类，boss类，具有一定的智力，血量，但是攻击方式均一样