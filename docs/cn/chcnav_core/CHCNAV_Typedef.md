# CHCNAV Typedef
Typedef 的头文件为chcnav_typedef.h，本文档描述了chcnav_typedef.h 文件中宏定义和结构体的关键信息和使用方法。

# 宏定义
- 圆周率
  ```
  #define CHCNAV_PI (3.14159265358979323846f)
  ```
- 文件名最大长度
  ```
    #define CHCNAV_FILE_NAME_SIZE_MAX 256
  ```
- 文件路径最大长度
  ```
    #define CHCNAV_FILE_PATH_SIZE_MAX (CHCNAV_FILE_NAME_SIZE_MAX + 256)

  ```
- ip地址最大长度
  ```
    #define CHCNAV_IP_ADDR_STRING_SIZE_MAX 15
  ```
- md5 缓存区长度
  ```
    #define CHCNAV_MD5_BUFFER_LEN_SIZE 16
  ```
- PSDK TRUE
  ```
    #define CHCNAV_TRUE 1
  ```
- PSDK FALSE
  ```
    #define CHCNAV_FALSE 0
  ```
- PSDK 返回失败
  ```
    #define CHCNAV_RESULT_FAITURE (-1)
  ```
- PSDK 返回成功
  ```
    #define CHCNAV_RESULT_SUCCESS 0
  ```
# 类型
- 双精度浮点类型
  ```
    typedef double chcnav_f64_t;
  ```
- 单精度浮点类型
  ```
    typedef float chcnav_f32_t;
  ```
- chcnav_u8_t类型
  ```
    typedef uint8_t chcnav_u8_t;
  ```
- chcnav_u16_t类型
  ```
    typedef uint16_t chcnav_u16_t;
  ```
- 返回值类型定义 (int32_t)
  ```
    typedef int32_t chcnav_return_code_t;
  ```
# 枚举
- CHCNAV_MOUNT_POSITION_TYPE_E
  安装位置类型
  ```
    typedef enum {
        CHCNAV_MOUNT_POSITION_TYPE_UNKNOWN = 0,
        CHCNAV_MOUNT_POSITION_TYPE_PAYLOAD_PORT = 1,
        CHCNAV_MOUNT_POSITION_TYPE_EXTENSION_PORT = 2,
        CHCNAV_MOUNT_POSITION_TYPE_EXTENSION_LITE_PORT = 3
    } CHCNAV_MOUNT_POSITION_TYPE_E;
  ```
- CHCNAV_MOUNT_POSITION_E
  安装位置
  ```
    typedef enum {
        CHCNAV_MOUNT_POSITION_UNKNOWN = 0,
        CHCNAV_MOUNT_POSITION_PAYLOAD_PORT_NO1 = 1,
        CHCNAV_MOUNT_POSITION_PAYLOAD_PORT_NO2 = 2,
        CHCNAV_MOUNT_POSITION_PAYLOAD_PORT_NO3 = 3,
        CHCNAV_MOUNT_POSITION_EXTENSION_PORT = 4,
        CHCNAV_MOUNT_POSITION_EXTENSION_LITE_PORT = 5
    } CHCNAV_MOUNT_POSITION_E;
  ```
- CHCNAV_UAV_SERIES_E
  无人机类型
  ```
    typedef enum {
        CHCNAV_UAV_SERIES_UNKNOWN = 0,
        CHCNAV_UAV_SERIES_X500 = 1,
        CHCNAV_UAV_SERIES_P60 = 2,
        CHCNAV_UAV_SERIES_P330PRO = 3,
        CHCNAV_UAV_SERIES_BB4 = 4
    } CHCNAV_UAV_SERIES_E;
  ```
- CHCNAV_CAMERA_E
  挂载相机型号
  ```
    typedef enum {
        /* Camera is unknown. */
        CHCNAV_CAMERA_UNKNOWN = 0,
         /* Camera is C5. */
        CHCNAV_CAMERA_C5 = 1,
        /* Camera is C30. */
        CHCNAV_CAMERA_C30 = 2,
        /* Camera is R10pros. */
        CHCNAV_CAMERA_R10PS = 3,
         /* Camera type is third party camera based on Payload SDK. */
        CHCNAV_CAMERA_PSDK = 30
    } CHCNAV_CAMERA_E;
  ```
- CHCNAV_CAMERA_TYPE_E
  挂载相机功能类型
  ```
    typedef enum {
      /* All of camera. */
      CHCNAV_CAMERA_TYPE_ALL = 0,
      /* Telephoto camera. */
      CHCNAV_CAMERA_TYPE_TELEPHOTO = 1,
      /* wide angle camera. */
      CHCNAV_CAMERA_TYPE_WIDE_ANGLE = 2,
      /* infrared camera. */
      CHCNAV_CAMERA_TYPE_INFRARED = 3,
    } CHCNAV_CAMERA_TYPE_E;
  ```
- CHCNAV_DOWNLOAD_FILE_SUB_TYPE_E
  下载的文件类型
  ```
    typedef enum {
        /* Media sub file origin data type. */
        CHCNAV_DOWNLOAD_FILE_TYPE_ORG = 0,
        /* Media sub file IMU data type.  */
        CHCNAV_DOWNLOAD_FILE_TYPE_IMU = 27
    } CHCNAV_DOWNLOAD_FILE_SUB_TYPE_E;

  ```
- CHCNAV_CAMERA_FILE_TYPE_E
  媒体文件类型
  ```
    typedef enum {
        /* Media file jpeg type. */
        CHCNAV_CAMERA_FILE_TYPE_JPEG = 0,
        /* Media file mp4 type. */
        CHCNAV_CAMERA_FILE_TYPE_MP4 = 1
    } CHCNAV_CAMERA_FILE_TYPE_E;

  ```
- CHCNAV_CHANNEL_ADDRESS_E
  ```
    typedef enum {
        CHCNAV_CHANNEL_ADDRESS_UNKNOWN = 0,
        CHCNAV_CHANNEL_ADDRESS_PAYLOAD_PORT_NO1,
        CHCNAV_CHANNEL_ADDRESS_PAYLOAD_PORT_NO2,
        CHCNAV_CHANNEL_ADDRESS_PAYLOAD_PORT_NO3,
        CHCNAV_CHANNEL_ADDRESS_EXTENSION_PORT
    } CHCNAV_CHANNEL_ADDRESS_E;
  ```
- CHCNAV_CAMERA_ZOOM_SPEED_E
  ```
    typedef enum {
        /* Slowest zoom speed. */
        CHCNAV_CAMERA_ZOOM_SPEED_SLOWEST = 72,
        /* Slow zoom speed. */
        CHCNAV_CAMERA_ZOOM_SPEED_SLOW = 73,
         /* Slightly slower than normal zoom speed. */
        CHCNAV_CAMERA_ZOOM_SPEED_MODERATELY_SLOW =
            74,
        /* Normal zoom speed. */
        CHCNAV_CAMERA_ZOOM_SPEED_NORMAL = 75,
        /* Slightly faster than normal zoom speed. */
        CHCNAV_CAMERA_ZOOM_SPEED_MODERATELY_FAST =
            76,
        /* Fast zoom speed. */
        CHCNAV_CAMERA_ZOOM_SPEED_FAST = 77,
        /* Fastest zoom speed. */
        CHCNAV_CAMERA_ZOOM_SPEED_FASTEST = 78
        } CHCNAV_CAMERA_ZOOM_SPEED_E;
  ```
- CHCNAV_CAMERA_BURST_COUNT_E
  ```
    typedef enum {
        /* Capture 2 pictures per trigger. */
        CHCNAV_CAMERA_BURST_COUNT_2 = 2,
        /* Capture 3 pictures per trigger. */
        CHCNAV_CAMERA_BURST_COUNT_3 = 3,
        /* Capture 5 pictures per trigger. */
        CHCNAV_CAMERA_BURST_COUNT_5 = 5,
        /* Capture 7 pictures per trigger. */
        CHCNAV_CAMERA_BURST_COUNT_7 = 7,
        /* Unknown burst count. */
        CHCNAV_CAMERA_BURST_COUNT_KNOWN = 0xFF
    } CHCNAV_CAMERA_BURST_COUNT_E;
  ```
- CHCNAV_CAMERA_ZOOM_DIRECTION_E
  ```
    typedef enum {
         /* Zooms out, reducing the zoom factor. */
        CHCNAV_CAMERA_ZOOM_DIRECTION_OUT =
            0,
        /* Zooms in, increasing the zoom factor. */
        CHCNAV_CAMERA_ZOOM_DIRECTION_IN =
            1
    } CHCNAV_CAMERA_ZOOM_DIRECTION_E;
  ```
- CHCNAV_GIMBAL_MODE_E
  ```
    typedef enum {
        /* Free mode, can control pitch/yaw/roll angle. */
        CHCNAV_GIMBAL_MODE_FREE                        = 0,
        /* FPV (First Person View) mode, only control roll and yaw angle of gimbal in the ground coordinate to follow aircraft. */
        CHCNAV_GIMBAL_MODE_FPV                         = 1,
        /* Yaw follow mode, only control yaw angle of gimbal in the ground coordinate to follow aircraft. */
        CHCNAV_GIMBAL_MODE_YAW_FOLLOW                  = 2,
         /* Lock mode, fix gimbal attitude in the ground coordinate, ignoring movement of aircraft. */
        CHCNAV_GIMBAL_MODE_LOCK                        = 3,
    } CHCNAV_GIMBAL_MODE_E;
  ```

# 结构体
- CHCNAV_CAMERA_POINT_IN_SCREEN_STRUCT
  ```
    typedef struct {
         /* Specifies the horizontal coordinate within the
            zone. Range: 0 to 1. The point [0.0, 0.0] represents
            the top-left corner of the screen.*/
        chcnav_f32_t focus_x;
        /* Specifies vertical zone coordinate. Range: 0 to 1. */
        chcnav_f32_t focus_y;
    } CHCNAV_CAMERA_POINT_IN_SCREEN_STRUCT;
  ```
- CHCNAV_CAMERA_OPTICAL_ZOOM_SPEC_STRUCT
  ```
  typedef struct {
         /* The maximum focal length of the lens,
            unit: 0.1mm. */
        chcnav_u16_t max_focal_length;
         /* The minimum focal length of the lens,
            unit: 0.1mm. */
        chcnav_u16_t min_focal_length;
        /* The minimum interval of focal length
            change, unit: 0.1mm. */
        chcnav_u16_t focal_fength_step;
  } CHCNAV_CAMERA_OPTICAL_ZOOM_SPEC_STRUCT;
  ```
- CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT
  ```
    typedef struct {
        /* Specifies the total capture count of interval
        * settings. 0: reserved, 1-254: specific number,
        * 255: continuous capture until stopped. */
        chcnav_u8_t capture_count;
         /* Specifies the interval time between
            two captures, unit: s*/
        chcnav_u16_t time_interval_seconds;
    } CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT;

  ```
- CHCNAV_ATTITUDE_STRCUT
  ```
    typedef struct {
        /* Pitch angle in degrees. */
        chcnav_f32_t pitch;
        /* Roll angle in degrees. */
        chcnav_f32_t roll;
        /* Yaw angle in degrees. */
        chcnav_f32_t yaw;
    } CHCNAV_ATTITUDE_STRCUT;

  ```
- CHCNAV_QUATERNION_STRUCT
  ```
    typedef struct {
        /* Quaternion component w. */
        chcnav_f32_t q0;
        /* Quaternion component x. */
        chcnav_f32_t q1;
        /* Quaternion component y. */
        chcnav_f32_t q2;
        /* Quaternion component z. */
        chcnav_f32_t q3;
    } CHCNAV_QUATERNION_STRUCT;

  ```