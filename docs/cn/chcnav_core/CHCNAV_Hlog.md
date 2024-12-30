# CHCNAV Hlog
PSDK Hlog相关功能的头文件为chcnav_hlog.h ，本文档描述了chcnav_hlog.h  文件中结构体和函数原型的关键信息和使用方法。

# 函数原型
- chcnav_hlog_init
  chcnav log 初始化接口，初始化时传入使用log的进程名称，第二个参数是设置log的配置文件
- chcnav_hlog_flush
  chcnav log 刷新接口，如对日志输出要求很高时可调用，否则无需调用
- chcnav_hlog_dump_hlog_settings
  chcnav log 打印log配置参数接口

# 宏定义
- CHCNAV_HLOG
  打印日志，使用方法为，第一个参数为module名，第二个是日志级别，后边是实际要打印的数据
  ```
    CHCNAV_HLOG(module1, INFO, "%s: Hello, there. [PI = %f?]", argv[0], kPI);
  ```
- CHCNAV_HLOG_INFO
  打印INFO日志
  ```
    CHCNAV_HLOG_INFO(module1,"%s: Hello, there. [PI = %f?]", argv[0], kPI);
  ```
- CHCNAV_HLOG_ERROR
  打印ERROR日志
- CHCNAV_HLOG_WARN
- 打印WARN日志

# 配置文件
  配置文件和应用程序放在同一目录，hlog-example.conf介绍
  ```
    logdir              .      # 设置日志保存目录
    logfilename         hlog   # 设置日志文件名称
    logtofile           1      # 1：写入文件 0：不写入文件
    logtostderr         0      # 1: 输出到终端 0 :不输出到终端
    minlevel            INFO   # 最小日志级别，大于等于此级别日志输出

    # 基于模块的自定义日志记录级别
    module1     INFO
    module2     WARN
    module3     VERBOSE
  ```
  如果没有配置conf文件，日志默认配置将不输出到终端，保存文件放在/tmp目录