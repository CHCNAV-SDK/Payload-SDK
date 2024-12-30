# CHCNAV Core
PSDK Core相关功能的头文件为chcnav_core.h ，本文档描述了chcnav_core.h  文件中结构体和函数原型的关键信息和使用方法。

## 函数原型
- chcnav_core_init
- chcnav_core_start
- chcnav_core_deinit

# 函数原型
## chcnav_core_init
初始化 Payload SDK 内核
- 注意事项:
> - chcnav_core_init接口的调用位置需要特别注意，需要在OSAL handler函数HAL handler函数注册完成后调用,并且，必须在调用其他功能模块接口开始前进行初始化

## chcnav_core_start
通知 Payload SDK 核心应用程序启动,需要在所有模块初始化和注册接口后完成调用

## chcnav_core_deinit
反初始化 Payload SDK Core