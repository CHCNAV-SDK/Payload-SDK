# CHCNAV 版本信息
PSDK 获取版本信息相关功能的头文件为chcnav_version,本文档描述了chcnav_version.h 文件中的宏定义。
## 宏定义
- CHCNAV PSDK 主版本号
  CHCNAV PSDK 主版本号，当有不兼容的 API 更改时。范围从 0 到 99
  ```
    #define CHCNAV_VERSION_MAJOR 0
  ```
- CHCNAV PSDK 次版本号
  CHCNAV PSDK 次版本号，当以向后兼容的方式添加功能时会发生变化。范围从 0 到 99。
  ```
    #define CHCNAV_VERSION_MINOR 0
  ```
- CHCNAV PSDK 修改版本号
  CHCNAV PSDK 修改版本号，当有向后兼容的错误修复更改时。范围从 0 到 99
  ```
    #define CHCNAV_VERSION_PATCH 0
  ```
- CHCNAV PSDK 代码分支名
  CHCNAV PSDK 代码分支名
  ```
    #define CHCNAV_VERSION_BRANCH "branch name"
  ```
- CHCNAV PSDK 代码COMMIT号
  CHCNAV PSDK 代码COMMIT号
  ```
    #define CHCNAV_VERSION_COMMIT "ee6852e"
  ```