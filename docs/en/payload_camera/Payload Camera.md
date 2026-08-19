# Camera Features
The header file for PSDK camera functionality is `chcnav_payload_camera.h`. This document describes the key information and usage of structures and function prototypes in the `chcnav_payload_camera.h` file.

- Enum
  * CHCNAV_CAMERA_MODE_E
  * CHCNAV_CAMERA_CAPTURE_MODE_E
  * CHCNAV_CAMERA_CAPTURE_STATE_E
  * CHCNAV_CAMERA_METERING_MODE_E
  * CHCNAV_CAMERA_SDCARD_STATUS_E
  * CHCNAV_CAMERA_SDCARD_USAGE_FLAG_E
  * CHCNAV_CAMERA_EXPOSURE_MODE_E
  * CHCNAV_CAMERA_WHITE_BALANCE_MODE_E
  * CHCNAV_CAMERA_COLOR_MODE_E
  * CHCNAV_CAMERA_PICTURE_FORMAT_E
  * CHCNAV_CAMERA_PICTURE_QUALITY_E
  * CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_E
  * CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_E
  * CHCNAV_CAMERA_VIDEO_ENCODING_E
  * CHCNAV_CAMERA_VIDEO_STREAM_TYPE_E
  * CHCNAV_CAMERA_VIDEO_STREAM_STATUS_FLAGS_E
  * CHCNAV_CAMERA_VIDEO_STREAM_SOURCE_TYPE_E
  * CHCNAV_CAMERA_SOURCE_E
  * CHCNAV_STREAM_OSD_E
  * CHCNAV_CAMERA_IR_MODE_E
- Struct
  * CHCNAV_CAMERA_SPOT_METERING_RANGE_STRUCT
  * CHCNAV_CAMERA_SPOT_METERING_TARGET_STRUCT
  * CHCNAV_CAMERA_SDCARD_STATE_STRUCT
  * CHCNAV_CAMERA_INFORMATION_STRUCT
  * CHCNAV_CAMERA_SYSTEM_STATE_STRUCT
  * CHCNAV_CAMERA_SN_STRUCT
  * CHCNAV_CAMERA_CAP_STRUCT
  * CHCNAV_CAMERA_CONFIG_STRUCT
  * CHCNAV_CAMERA_VIDEO_STREAM_INFORMATION_STRUCT
  * CHCNAV_CAMERA_VIDEO_STREAM_STATUS_STRUCT
  * CHCNAV_CAMERA_ZOOM_CONFIGURE_STRUCT
  * CHCNAV_CAMERA_FOCUS_CONFIGURE_STRUCT
  * CHCNAV_CAMERA_OSD_CONFIGURE_STRUCT
  * CHCNAV_CAMERA_COMMON_HANDLER_STRUCT
  * CHCNAV_CAMERA_PARAMETER_HANDLER_STRUCT
  * CHCNAV_CAMERA_ZOOM_HANDLER_STRUCT
  * CHCNAV_CAMERA_FOCUS_HANDLER_STRUCT
- Function
  * chcnav_payload_camera_init
  * chcnav_payload_camera_register_common_handler
  * chcnav_payload_camera_register_parameter_handler
  * chcnav_camera_zoom_handler
  * chcnav_camera_focus_handler
  * chcnav_payload_camera_get_video_stream_network_address

## Enum
### typedef enum CHCNAV_CAMERA_MODE_E
  Operating modes for camera-class payload devices.
  ```
    typedef enum {
        /* Photo mode */
        CHCNAV_CAMERA_MODE_IMAGE = 0,
        /* Video mode */
        CHCNAV_CAMERA_MODE_VIDEO= 1,
        /* Survey mode */
        CHCNAV_CAMERA_MODE_IMAGE_SURVEY = 2
    } CHCNAV_CAMERA_MODE_E;
  ```
### typedef enum CHCNAV_CAMERA_CAPTURE_MODE_E
  Capture modes for camera-class payload devices.
  ```
    typedef enum {
        /* Single-shot mode */
        CHCNAV_CAMERA_CAPTURE_MODE_SINGLE = 1,
        /* Timed capture mode */
        CHCNAV_CAMERA_CAPTURE_MODE_INTERVAL = 2,
    } CHCNAV_CAMERA_CAPTURE_MODE_E;
  ```
### typedef enum CHCNAV_CAMERA_CAPTURE_STATE_E
  Capture state of camera-class payload devices.
  ```
    typedef enum {
        /* Idle state */
        CHCNAV_CAMERA_CAPTURING_PHOTO_IDLE = 0,
        /* Single-shot state */
        CHCNAV_CAMERA_CAPTURING_SINGLE_PHOTO = 1,
        /* Timed capture, currently idle */
        CHCNAV_CAMERA_CAPTURING_INTERVAL_PHOTO_IDLE = 2,
        /* Timed capture, capturing in progress */
        CHCNAV_CAMERA_CAPTURING_INTERVAL_PHOTO = 3
    } CHCNAV_CAMERA_CAPTURE_STATE_E;
  ```
### typedef enum CHCNAV_CAMERA_METERING_MODE_E
  Metering modes for camera-class payload devices.
  ```
    typedef enum {
        /* Center-weighted metering mode */
        CHCNAV_CAMERA_METERING_MODE_CENTER = 0,
        /* Average metering mode */
        CHCNAV_CAMERA_METERING_MODE_AVERAGE = 1,
        /* Spot metering mode */
        CHCNAV_CAMERA_METERING_MODE_SPOT = 2
    } CHCNAV_CAMERA_METERING_MODE_E;
  ```
### typedef enum CHCNAV_CAMERA_SDCARD_STATUS_E
  SD card status in camera-class payload devices.
  ```
    typedef enum {
        /* No SD card inserted */
        CHCNAV_CAMERA_SDCARD_STATUS_EMPTY = 0,
        /* SD card not initialized */
        CHCNAV_CAMERA_SDCARD_STATUS_UNFORMATTED = 1,
        /* SD card ready */
        CHCNAV_CAMERA_SDCARD_STATUS_READY = 2,
        /* Camera does not provide SD card status information */
        CHCNAV_CAMERA_SDCARD_STATUS_NOT_SUPPORTED = 3,
        /* SD card full */
        CHCNAV_CAMERA_SDCARD_STATUS_FULL = 4,
    }CHCNAV_CAMERA_SDCARD_STATUS_E;
  ```
### typedef enum CHCNAV_CAMERA_SDCARD_USAGE_FLAG_E
  SD card usage in camera-class payload devices.
  ```
    typedef enum
    {
        /* SD card usage can be retrieved */
        CHCNAV_CAMERA_SDCARD_USAGE_FLAG_SET = 1,
         /* SD card used to store photos */
        CHCNAV_CAMERA_SDCARD_USAGE_FLAG_PHOTO = 2,
        /* SD card used to store videos */
        CHCNAV_CAMERA_SDCARD_USAGE_FLAG_VIDEO = 4,
        /* SD card used to store logs */
        CHCNAV_CAMERA_SDCARD_USAGE_FLAG_LOGS = 8,
    } CHCNAV_CAMERA_SDCARD_USAGE_FLAG_E;
  ```
### typedef enum CHCNAV_CAMERA_EXPOSURE_MODE_E
  ```
    typedef enum {
      /* Program auto mode */
      CHCNAV_CAMERA_EXPOSURE_MODE_AUTO = 1,
      /* Shutter priority mode */
      CHCNAV_CAMERA_EXPOSURE_MODE_SHUTTER_PRIORITY = 2,
      /* Aperture priority mode */
      CHCNAV_CAMERA_EXPOSURE_MODE_APERTURE_PRIORITY = 3,
      /* Full manual mode */
      CHCNAV_CAMERA_EXPOSURE_MODE_MANUAL = 4,
      /* Unknown mode */
      CHCNAV_CAMERA_EXPOSURE_MODE_UNKNOWN = 0xFF
    } CHCNAV_CAMERA_EXPOSURE_MODE_E;
  ```
### CHCNAV_CAMERA_WHITE_BALANCE_MODE_E
  ```
    typedef enum {
      CHCNAV_CAMERA_WHITE_BALANCE_MODE_AUTO = 0,/* Auto */
      CHCNAV_CAMERA_WHITE_BALANCE_MODE_INCANDESCENT = 1, /* Incandescent mode */
      CHCNAV_CAMERA_WHITE_BALANCE_MODE_SUNSET = 3,       /* Sunset mode */
      CHCNAV_CAMERA_WHITE_BALANCE_MODE_SUNNY = 4,        /* Sunny mode */
      CHCNAV_CAMERA_WHITE_BALANCE_MODE_CLOUDY = 5,       /* Cloudy mode */
      CHCNAV_CAMERA_WHITE_BALANCE_MODE_FLUORESCENT = 7,  /* Fluorescent mode */
      CHCNAV_CAMERA_WHITE_BALANCE_MODE_UNKNOWN = 0xFF
    } CHCNAV_CAMERA_WHITE_BALANCE_MODE_E;
  ```
### CHCNAV_CAMERA_COLOR_MODE_E
  ```
    typedef enum {
      CHCNAV_CAMERA_COLOR_MODE_NEUTRAL = 0,/* Neutral */
      CHCNAV_CAMERA_COLOR_MODE_ENHANCED = 1,/* Enhanced *
      CHCNAV_CAMERA_COLOR_MODE_UNPROCESSED = 2,/* Unprocessed */
      CHCNAV_CAMERA_COLOR_MODE_NIGHT = 3,/* Sunset */
    } CHCNAV_CAMERA_COLOR_MODE_E;
  ```
### CHCNAV_CAMERA_PICTURE_FORMAT_E
  ```
    typedef enum {
      CHCNAV_CAMERA_PICTURE_FORMAT_JPEG = 0,/* JPEG format */
      CHCNAV_CAMERA_PICTURE_FORMAT_RAW = 1,/* RAW format */
      CHCNAV_CAMERA_PICTURE_FORMAT_JPEG_RAW = 2,/* Save JPEG and RAW simultaneously */
    } CHCNAV_CAMERA_PICTURE_FORMAT_E;
  ```
### CHCNAV_CAMERA_PICTURE_QUALITY_E
  ```
    typedef enum {
      CHCNAV_CAMERA_PICTURE_QUALITY_LOW = 0,/* Low quality */
      CHCNAV_CAMERA_PICTURE_QUALITY_MEDIUM = 1,/* Medium quality */
      CHCNAV_CAMERA_PICTURE_QUALITY_HIGH = 2,/* High quality */
      CHCNAV_CAMERA_PICTURE_QUALITY_ULTRA = 3,/* Ultra high quality */
    } CHCNAV_CAMERA_PICTURE_QUALITY_E;
  ```
### CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_E
  ```
    typedef enum {
      CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_H264 = 1,
      CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_HEVC = 3,
      CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_MPEG = 4,
    } CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_E;
  ```
### CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_E
  ```
    typedef enum {
      CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_AOV = 0,
      CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_MP4 = 1,
      CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_TS = 5,
    } CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_E;
  ```
### CHCNAV_CAMERA_VIDEO_ENCODING_E
  ```
    typedef enum {
      CHCNAV_CAMERA_VIDEO_ENCODING_UNKNOWN = 0,
      CHCNAV_CAMERA_VIDEO_ENCODING_H264 = 1,
      CHCNAV_CAMERA_VIDEO_ENCODING_H265 = 2,
    } CHCNAV_CAMERA_VIDEO_ENCODING_E;
  ```
### CHCNAV_CAMERA_VIDEO_STREAM_TYPE_E
  ```
    typedef enum
    {
      /* RTSP video stream */
      CHCNAV_CAMERA_VIDEO_STREAM_TYPE_RTSP=0,
      /* RTP UDP video stream */
      CHCNAV_CAMERA_VIDEO_STREAM_TYPE_RTPUDP=1,
      /* MPEG on TCP video stream */
      CHCNAV_CAMERA_VIDEO_STREAM_TYPE_TCP_MPEG=2,
      /* h.264 on MPEG TS video stream */
      CHCNAV_CAMERA_VIDEO_STREAM_TYPE_MPEG_TS_H264=3,
      CHCNAV_CAMERA_VIDEO_STREAM_TYPE_ENUM_END=4,
    } CHCNAV_CAMERA_VIDEO_STREAM_TYPE_E;
  ```
### CHCNAV_CAMERA_VIDEO_STREAM_STATUS_FLAGS_E
  ```
    typedef enum
    {
      CHCNAV_CAMERA_VIDEO_STREAM_STATUS_FLAGS_RUNNING=1, /* Streaming in progress */
      CHCNAV_CAMERA_VIDEO_STREAM_STATUS_FLAGS_THERMAL=2, /* Thermal imaging */
      CHCNAV_CAMERA_VIDEO_STREAM_STATUS_FLAGS_ENUM_END=3,
    } CHCNAV_CAMERA_VIDEO_STREAM_STATUS_FLAGS_E;
  ```
### CHCNAV_CAMERA_VIDEO_STREAM_SOURCE_TYPE_E
  ```
    typedef enum
    {
      /* Set RTSP stream to telephoto camera data */
      CHCNAV_CAMERA_VIDEO_STREAM_SOURCE_TYPE_TELEPHOTO=1,
      /* Set RTSP stream to wide-angle camera data */
      CHCNAV_CAMERA_VIDEO_STREAM_SOURCE_TYPE_WIDE_ANGLE=2,
      /* Set RTSP stream to infrared camera data */
      CHCNAV_CAMERA_VIDEO_STREAM_SOURCE_TYPE_INFRARED=3,
      /* Set RTSP stream to picture-in-picture display mode */
      CHCNAV_CAMERA_VIDEO_STREAM_SOURCE_TYPE_PIP=4,
    } CHCNAV_CAMERA_VIDEO_STREAM_SOURCE_TYPE_E;
  ```
### CHCNAV_CAMERA_SOURCE_E
  ```
    typedef enum
    {
      CHCNAV_CAMERA_SOURCE_DEFAULT=0, /* Default camera source. */
      CHCNAV_CAMERA_SOURCE_RGB=1, /* RGB camera source. */
      CHCNAV_CAMERA_SOURCE_IR=2, /* IR camera source. */
      CHCNAV_CAMERA_SOURCE_NDVI=3, /* NDVI camera source. */
    } CHCNAV_CAMERA_SOURCE_E;
  ```
### CHCNAV_STREAM_OSD_E
  ```
    typedef enum {
      /* Enable stream OSD display */
      CHCNAV_STREAM_OSD_OPEN = 1,
      /* Disable stream OSD display */
      CHCNAV_STREAM_OSD_CLOSED = 2,
    } CHCNAV_STREAM_OSD_E;
  ```
### CHCNAV_CAMERA_IR_MODE_E
  ```
    typedef enum {
      /* Infrared color mode: white hot */
      CHCNAV_CAMERA_IR_MODE_WHITE_HOT = 0,
      /* Infrared color mode: black hot */
      CHCNAV_CAMERA_IR_MODE_BLACK_HOT = 1,
      /* Infrared color mode: iron red */
      CHCNAV_CAMERA_IR_MODE_IRON_RED = 2,
      /* Infrared color mode: lava */
      CHCNAV_CAMERA_IR_MODE_LAVA = 3,
      /* Infrared color mode: rainbow */
      CHCNAV_CAMERA_IR_MODE_RAINBOW = 4,
      /* Infrared color mode: arctic */
      CHCNAV_CAMERA_IR_MODE_ARCTIC = 5,
      /* Infrared color mode: high-contrast rainbow */
      CHCNAV_CAMERA_IR_MODE_HC_RAINBOW = 6,
      /* Infrared color mode: sky */
      CHCNAV_CAMERA_IR_MODE_SKY = 7,
      /* Infrared color mode: mid gray */
      CHCNAV_CAMERA_IR_MODE_MID_GRAY = 8,
      /* Infrared color mode: gray red */
      CHCNAV_CAMERA_IR_MODE_GRAY_RED = 9,
      /* Infrared color mode: violet orange */
      CHCNAV_CAMERA_IR_MODE_VIOLET_ORANGE = 10,
      /* Infrared color mode: alert red */
      CHCNAV_CAMERA_IR_MODE_ALERT_RED = 11,
      /* Infrared color mode: ice fire */
      CHCNAV_CAMERA_IR_MODE_ICE_FIRE = 12,
      /* Infrared color mode: cyan red */
      CHCNAV_CAMERA_IR_MODE_CYAN_RED = 13,
      /* Infrared color mode: red gradient */
      CHCNAV_CAMERA_IR_MODE_RED_GRADIENT = 14,
      /* Infrared color mode: grayscale */
      CHCNAV_CAMERA_IR_MODE_GRAYSCALE = 15,
      /* Infrared color mode: green gradient */
      CHCNAV_CAMERA_IR_MODE_GREEN_GRADIENT = 16,
      /* Infrared color mode: yellow gradient */
      CHCNAV_CAMERA_IR_MODE_YELLOW_GRADIENT = 17,
      /* Infrared color mode: alert green */
      CHCNAV_CAMERA_IR_MODE_ALERT_GREEN = 18,
      /* Infrared color mode: alert blue */
      CHCNAV_CAMERA_IR_MODE_ALERT_BLUE = 19,
      /* Infrared color mode: special 1 */
      CHCNAV_CAMERA_IR_MODE_SPECIAL1 = 20,
      /* Infrared color mode: special 2 */
      CHCNAV_CAMERA_IR_MODE_SPECIAL2 = 21
    } CHCNAV_CAMERA_IR_MODE_E;
  ```
## Struct
### CHCNAV_CAMERA_SPOT_METERING_RANGE_STRUCT
  Specifies the spot metering range for camera-class payload devices.
  ```
    typedef struct {
      uint8_t col; /* Column coordinate */
      uint8_t row; /* Row coordinate */
    } CHCNAV_CAMERA_SPOT_METERING_RANGE_STRUCT;
  ```
### CHCNAV_CAMERA_SPOT_METERING_TARGET_STRUCT
  Specifies the spot metering target for camera-class payload devices.
  ```
    typedef struct {
        uint8_t col; /* Column of the metering target */
        uint8_t row; /* Row of the metering target */
    } CHCNAV_CAMERA_SPOT_METERING_TARGET_STRUCT;
  ```
### CHCNAV_CAMERA_SDCARD_STATE_STRUCT
  SD card status in camera-class payload devices.
  ```
    typedef struct {
        /* SD card ID */
        uint8_t storage_id;
        /* Total number of SD cards */
        uint8_t storage_count;
        /* SD card status */
        CHCNAV_CAMERA_SDCARD_STATUS_E status;
        /* SD card usage */
        CHCNAV_CAMERA_SDCARD_USAGE_FLAG_E storage_usage;
        /* Total SD card capacity, in MB */
        uint32_t total_capacity_mb;
        /* Used SD card capacity, in MB */
        uint32_t used_capacity_mb;
        /* Available SD card capacity, in MB */
        uint32_t available_capacity_mb;
        /* SD card read speed, in MB/s */
        uint32_t read_speed_mb_per_second;
        /* SD card write speed, in MB/s */
        uint32_t write_speed_mb_per_second;
    } CHCNAV_CAMERA_SDCARD_STATE_STRUCT;
  ```
### CHCNAV_CAMERA_INFORMATION_STRUCT
  Basic information for camera-class payload devices.
  ```
    typedef struct {
        /* Total number of SD cards */
        uint8_t storage_count;
        /* Firmware version, encoded as (Dev & 0xff) << 24 | (Patch & 0xff) << 16 | (Minor & 0xff) << 8 | (Major & 0xff)*/
        uint32_t firmware_version;
        /* Focal length, in mm */
        float focal_length;
        /* Image sensor horizontal size, in mm */
        float sensor_size_h;
        /* Image sensor vertical size, in mm */
        float sensor_size_v;
        /* Bitmap of camera capability flags (CHCNAV_CAMERA_CAP_FLAGS_E).*/
        uint32_t flags;
        /* Horizontal image resolution */
        uint16_t resolution_h;
        /* Vertical image resolution */
        uint16_t resolution_v;
        /* Camera definition version */
        uint16_t cam_definition_version;
        /* Camera vendor name */
        uint8_t vendor_name[32];
        /* Camera model name* /
        uint8_t model_name[32];
        /* Lens ID */
        uint8_t lens_id;
        /* Camera definition URI; HTTP URIs (http://) are supported */
        char cam_definition_uri[140];
        /* Camera function type; see CHCNAV_CAMERA_TYPE_E */
        uint8_t camera_type;
    }CHCNAV_CAMERA_INFORMATION_STRUCT;
  ```
### CHCNAV_CAMERA_SYSTEM_STATE_STRUCT
  State of camera-class payload devices.
  ```
    typedef struct {
        float temperature; /* Temperature of the camera-class payload device */
        CHCNAV_CAMERA_MODE_E camera_mode; /* Camera operating mode */
        float zoom_level; /* Current zoom level as a percentage of the full range */
        float focus_level; /* Current focus level as a percentage of the full range*/
        CHCNAV_CAMERA_CAPTURE_STATE_E capturing_state; /* Camera capture state */
        bool is_capturing;/* Whether the camera is capturing photos */
        bool is_capturing_interval_start; /* Whether the camera is in timed capture mode */
        uint16_t image_capturing_interval_time_seconds; /* Current timed capture interval*/
        uint16_t image_capturing_interval_count; /* Total number of photos to capture in timed mode */
        uint16_t image_capturing_history_count; /* Historical photo capture count */
        bool is_recording; /* Whether the camera is recording video */
        uint16_t video_recording_time_seconds; /* Video recording progress, in seconds */
        bool has_error; /* Whether the camera has an error */
        uint8_t video_stream_type; /* Camera function type; see CHCNAV_CAMERA_TYPE_E */
    } CHCNAV_CAMERA_SYSTEM_STATE_STRUCT;
  ```
### CHCNAV_CAMERA_SN_STRUCT
  Serial number of camera-class payload devices.
  ```
    typedef struct {
      uint8_t serial_number[32];/* Camera serial number */
    } CHCNAV_CAMERA_SN_STRUCT;
  ```
### CHCNAV_CAMERA_CAP_STRUCT
  Capability set of camera-class payload devices.
  ```
    typedef struct {
      /* Whether zoom is supported: 0 = not supported, 1 = supported */
      uint8_t zoom_flag;
      /* Whether focus is supported: 0 = not supported, 1 = supported */
      uint8_t focus_flag;
       /* Whether IR cut filter is supported: 0 = not supported, 1 = supported*/
      uint8_t ircut_flag;
      /* Whether exposure mode can be set: 0 = not supported, 1 = supported*/
      uint8_t exposure_mode_flag;
      /* Whether ISO can be set: 0 = not supported, 1 = supported*/
      uint8_t iso_flag;
      /* Whether aperture can be set: 0 = not supported, 1 = supported*/
      uint8_t aperture_flag;
      /* Whether shutter can be set: 0 = not supported, 1 = supported*/
      uint8_t shutter_flag;
      /* Whether exposure compensation can be set: 0 = not supported, 1 = supported*/
      uint8_t ev_flag;
      /* Whether metering mode can be set: 0 = not supported, 1 = supported*/
      uint8_t meter_flag;
      /* Whether white balance mode can be set: 0 = not supported, 1 = supported*/
      uint8_t wb_mode_flag;
      /* Whether anti-flicker is supported: 0 = not supported, 1 = supported*/
      uint8_t antiflicker_flag;
      /* Whether brightness can be set: 0 = not supported, 1 = supported*/
      uint8_t brightness_flag;
      /* Whether saturation can be set: 0 = not supported, 1 = supported*/
      uint8_t saturation_flag;
      /* Whether contrast can be set: 0 = not supported, 1 = supported*/
      uint8_t contrast_flag;
      /* Whether sharpness can be set: 0 = not supported, 1 = supported*/
      uint8_t sharpness_flag;
      /* Whether color mode is supported: 0 = not supported, 1 = supported*/
      uint8_t color_mode_flag;
      /* Whether video encode format can be set: 0 = not supported, 1 = supported*/
      uint8_t video_encode_flag;
      /* Whether video save file format can be set: 0 = not supported, 1 = supported*/
      uint8_t video_format_flag;
      /* Whether media parameters (resolution, frame rate, etc.) can be set: 0 = not supported, 1 = supported*/
      uint8_t video_media_flag;
      /* Whether photo save file format can be set*/
      uint8_t photo_format_flag;
      /* Whether photo aspect ratio can be set: 0 = not supported, 1 = supported*/
      uint8_t photo_ratio_flag;
      /* Whether photo quality can be set: 0 = not supported, 1 = supported*/
      uint8_t photo_quality_flag;
      /* Whether the camera has battery power: 0 = not supported, 1 = supported*/
      uint8_t battery_flag;
    } CHCNAV_CAMERA_CAP_STRUCT;
  ```
### CHCNAV_CAMERA_CONFIG_STRUCT
  Basic parameters for camera-class payload devices.
  ```
    typedef struct {
      uint32_t width;     /* Resolution width */
      uint32_t height;    /* Resolution height */
      uint16_t framerate; /* Frame rate */
      uint32_t bitrate;   /* Bitrate, in Kbps */
    } CHCNAV_CAMERA_CONFIG_STRUCT;
  ```
### CHCNAV_CAMERA_VIDEO_STREAM_INFORMATION_STRUCT
  ```
    typedef struct {
      /* Frame rate, in Hz */
      uint16_t framerate;
      /* Bitrate, in bits/s */
      uint32_t bitrate;
      /* Stream status flags; see CHCNAV_CAMERA_VIDEO_STREAM_STATUS_FLAGS_E */
      uint16_t flags;
      /* Horizontal resolution, in pixels */
      uint16_t resolution_h;
      /* Vertical resolution, in pixels */
      uint16_t resolution_v;
      /* Clockwise video rotation, in degrees */
      uint16_t rotation;
      /* Horizontal field of view, in degrees */
      uint16_t hfov;
      /* Video stream ID; 1 is the first, 2 is the second, and so on */
      uint8_t stream_id;
      /* Total number of available video streams */
      uint8_t count;
      /* Stream type; see CHCNAV_CAMERA_VIDEO_STREAM_TYPE_E */
      uint8_t type;
      /* Stream name */
      char name[32];
      /* Video stream URI: TCP or RTSP URI and port number */
      char uri[160];
      /* Stream encoding format */
      uint8_t encoding;
    } CHCNAV_CAMERA_VIDEO_STREAM_INFORMATION_STRUCT;
  ```
### CHCNAV_CAMERA_VIDEO_STREAM_STATUS_STRUCT
  ```
    typedef struct {
      /* Stream frame rate, in Hz */
      float framerate;
      /* Stream bitrate, in bits/s */
      uint32_t bitrate;
      /* Stream status flags */
      uint16_t flags;
      /* Horizontal resolution, in pixels */
      uint16_t resolution_h;
      /* Vertical resolution, in pixels */
      uint16_t resolution_v;
      /* Clockwise stream rotation angle, in degrees */
      uint16_t rotation;
      /* Horizontal field of view, in degrees */
      uint16_t hfov;
      /* Stream ID */
      uint8_t stream_id;
    } CHCNAV_CAMERA_VIDEO_STREAM_STATUS_STRUCT;
  ```
### CHCNAV_CAMERA_ZOOM_CONFIGURE_STRUCT
  ```
    typedef struct {
      /* Current zoom value */
      float zoom;
      /* Maximum zoom value supported by the camera */
      float zoom_max;
      /* Camera function type; see CHCNAV_CAMERA_TYPE_E */
      uint8_t camera_type;
    } CHCNAV_CAMERA_ZOOM_CONFIGURE_STRUCT;
  ```
### CHCNAV_CAMERA_FOCUS_CONFIGURE_STRUCT
  ```
    typedef struct {
      /* Current focus value; set as a percentage, range: 0~100 */
      float focus;
      /* Minimum focus value; default: 0 */
      float focus_min;
      Maximum focus value, default: 100
      float focus_max;
      /* Camera function type; see CHCNAV_CAMERA_TYPE_E */
      uint8_t camera_type;
    } CHCNAV_CAMERA_FOCUS_CONFIGURE_STRUCT;
  ```
### CHCNAV_CAMERA_OSD_CONFIGURE_STRUCT
  ```
    typedef struct {
      /* OSD enable; see CHCNAV_STREAM_OSD_E for valid values */
      uint8_t osd_enable;
      /* Display pitch and yaw; see CHCNAV_STREAM_OSD_E for valid values */
      uint8_t pitch_yaw_enable;
      /* Display center crosshair; see CHCNAV_STREAM_OSD_E for valid values */
      uint8_t center_cross_enable;
      /* Display time; see CHCNAV_STREAM_OSD_E for valid values */
      uint8_t time_enable;
      /* Display laser rangefinder; see CHCNAV_STREAM_OSD_E for valid values */
      uint8_t range_enable;
      /* Display GPS coordinates; see CHCNAV_STREAM_OSD_E for valid values */
      uint8_t gps_coordinates;
      /* Display infrared temperature measurement; see CHCNAV_STREAM_OSD_E for valid values */
      uint8_t temperature_enable;
    } CHCNAV_CAMERA_OSD_CONFIGURE_STRUCT;
  ```
### CHCNAV_CAMERA_COMMON_HANDLER_STRUCT
  Controls basic actions for camera-class payload devices. Use the functions in this structure to implement callback functions for basic camera operations, including:
  - Get camera-class payload device information
  - Get the current state of camera-class payload devices
  - Get the serial number of camera-class payload devices
  - Get the capability set of camera-class payload devices
  - Set the operating mode of camera-class payload devices
  - Get the operating mode of camera-class payload devices
  - Start photo capture on camera-class payload devices
  - Stop photo capture on camera-class payload devices
  - Set the capture mode of camera-class payload devices
  - Get the capture mode of camera-class payload devices
  - Set the timed capture interval for camera-class payload devices
  - Get the timed capture interval for camera-class payload devices
  - Get video stream information for camera-class payload devices
  - Start video recording on camera-class payload devices
  - Stop video recording on camera-class payload devices
  - Get the current SD card status in camera-class payload devices
  - Format the SD card on camera-class payload devices
  - Reset parameters configured on camera-class payload devices
  ```
    typedef struct {

        /**
        * @brief Get camera device information
        * @param camera_information: Pointer to a structure for storing camera-class payload device information
        * @return Execution result
        */
        chcnav_return_code_t (*get_camera_information)(CHCNAV_CAMERA_INFORMATION_STRUCT *camera_information);

        /**
        * @brief Get the current state of the camera device
        * @param system_state: Pointer to a structure for storing the camera-class payload device system state
        * @return Execution result
        */
        chcnav_return_code_t (*get_camera_state)(CHCNAV_CAMERA_SYSTEM_STATE_STRUCT *system_state);

        /**
        * @brief Get camera serial number
        * @param camera_sn: Camera serial number
        * @return Execution result.
        */
        chcnav_return_code_t (*get_camera_sn)(CHCNAV_CAMERA_SN_STRUCT *camera_sn);

        /**
        * @brief Get camera capability set
        * @param camera_cap: Camera capability set
        * @return Execution result.
        */
        chcnav_return_code_t (*get_camera_capability)(
            CHCNAV_CAMERA_CAP_STRUCT *camera_cap);

        /**
        * @brief Set the operating mode of a camera-class device
        * @param mode: Operating mode of the camera-class payload device
        * @return Execution result
        */
        chcnav_return_code_t (*set_camera_mode)(CHCNAV_CAMERA_MODE_E mode);

        /**
        * @brief Get the operating mode of a camera-class device
        * @param mode: Pointer for storing the operating mode of the camera-class payload device
        * @return Execution result
        */
        chcnav_return_code_t (*get_camera_mode)(CHCNAV_CAMERA_MODE_E *mode);

        /**
        * @brief Start photo capture on a camera-class payload device
        * @return Execution result
        */
        chcnav_return_code_t (*start_capture_image)(void);

        /**
        * @brief Stop photo capture on a camera-class payload device
        * @return Execution result
        */
        chcnav_return_code_t (*stop_capture_image)(void);

        /**
        * @brief Set the capture mode of a camera-class payload device
        * @param mode: Capture mode of the camera-class payload device
        * @return Execution result
        */
        chcnav_return_code_t (*set_capture_image_mode)(CHCNAV_CAMERA_CAPTURE_MODE_E mode);

        /**
        * @brief Get the capture mode of a camera-class payload device
        * @param mode: Pointer to an enumeration for storing the capture mode of the camera-class payload device
        * @return Execution result
        */
        chcnav_return_code_t (*get_capture_image_mode)(CHCNAV_CAMERA_CAPTURE_MODE_E *mode);

        /**
        * @brief Set the timed capture interval for a camera-class payload device
        * @param settings: Structure for storing timed capture settings of the camera-class payload device
        * @return Execution result
        */
        chcnav_return_code_t (*set_image_time_interval_settings)(CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT settings);

        /**
        * @brief Get the timed capture interval for a camera-class payload device
        * @param settings: Pointer to a structure for storing timed capture settings of the camera-class payload device
        * @return Execution result
        */
        chcnav_return_code_t (*get_image_time_interval_settings)(CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT *settings);

        /**
        * @brief Get video stream information for a camera-class payload device
        * @param video_stream_info: Used to retrieve video stream information for the camera-class payload device
        * @return Execution result
        */
        chcnav_return_code_t (*get_video_stream_information)(uint8_t stream_id,CHCNAV_CAMERA_VIDEO_STREAM_INFORMATION_STRUCT *video_stream_info);

        /**
        * @brief Start video recording on a camera-class payload device
        * @return Execution result
        */
        chcnav_return_code_t (*start_record_video)(void);

        /**
        * @brief Stop video recording on a camera-class payload device
        * @return Execution result
        */
        chcnav_return_code_t (*stop_record_video)(void);

        /**
        * @brief Get the current SD card status in a camera-class payload device
        * @param storage_id: SD card ID
        * @param sd_card_state: Pointer for storing the SD card state of the camera-class payload device
        * @return Execution result
        */
        chcnav_return_code_t (*get_sd_card_state)(uint8_t storage_id,CHCNAV_CAMERA_SDCARD_STATE_STRUCT *sd_card_state);

        /**
        * @brief Format the SD card on a camera-class payload device
        * @param storage_id: SD card ID
        * @return Execution result
        */
        chcnav_return_code_t (*format_sd_card)(uint8_t storage_id);

        /**
        * @brief Reset parameters configured on a camera-class payload device
        * @return Execution result
        */
        chcnav_return_code_t (*reset_system_settings)(void);
    } CHCNAV_CAMERA_COMMON_HANDLER_STRUCT;
  ```
### CHCNAV_CAMERA_PARAMETER_HANDLER_STRUCT
  Controls parameter get/set functionality for camera-class payload devices. Use the functions in this structure to implement callback functions for setting and getting camera parameters, including:
  - Set camera exposure mode
  - Get camera exposure mode
  - Set camera shutter speed
  - Get camera aperture value
  - Get camera ISO
  - Get camera EV value
  - Set camera metering mode
  - Get camera metering mode
  - Get camera spot metering range
  - Get camera spot metering target
  - Set camera white balance mode
  - Get camera white balance mode
  - Set camera brightness
  - Get camera brightness
  - Set camera saturation
  - Get camera saturation
  - Set camera contrast
  - Get camera contrast
  - Set camera sharpness
  - Get camera sharpness
  - Set camera color mode
  - Get camera color mode
  - Get camera capture interval
  - Set camera picture format
  - Get camera picture format
  - Set camera image quality
  - Get camera image quality
  - Set camera encode format
  - Get camera encode format
  - Set camera video record format
  - Get camera video record format
  - Set camera media parameters
  - Get camera media parameters
  - Set multiple camera parameters
  ```
    typedef struct {
      /**
      * @brief Set camera exposure mode
      * @param mode: Camera exposure mode
      * @return Execution result
      */
      chcnav_return_code_t (*set_exposure_mode)(CHCNAV_CAMERA_EXPOSURE_MODE_E mode);

      /**
      * @brief Get camera exposure mode
      * @param mode: Camera exposure mode
      * @return Execution result
      */
      chcnav_return_code_t (*get_exposure_mode)(
          CHCNAV_CAMERA_EXPOSURE_MODE_E *mode);

      /**
      * @brief Set camera shutter speed
      * @param value: Camera shutter speed
      * @return Execution result
      */
      chcnav_return_code_t (*get_shutter_speed)(uint32_t *value);

      /**
      * @brief Get camera aperture value
      * @param value: Camera aperture value
      * @return Execution result
      */
      chcnav_return_code_t (*get_aperture)(float *value);

      /**
      * @brief Get camera ISO
      * @param value: Camera ISO
      * @return Execution result
      */
      chcnav_return_code_t (*get_iso)(uint32_t *value);

      /**
      * @brief Get camera EV value
      * @param value: Camera EV value
      * @return Execution result
      */
      chcnav_return_code_t (*get_ev)(float *value);

      /**
      * @brief Set camera metering mode
      * @param mode: Camera metering mode
      * @return Execution result
      */
      chcnav_return_code_t (*set_metering_mode)(CHCNAV_CAMERA_METERING_MODE_E mode);

      /**
      * @brief Get camera metering mode
      * @param mode: Camera metering mode
      * @return Execution result
      */
      chcnav_return_code_t (*get_metering_mode)(
          CHCNAV_CAMERA_METERING_MODE_E *mode);

      /**
      * @brief Get camera spot metering range
      * @param mode: Camera spot metering range
      * @return Execution result
      */
      chcnav_return_code_t (*get_spot_metering_range)(
          CHCNAV_CAMERA_SPOT_METERING_RANGE_STRUCT *range);

      /**
      * @brief Get camera spot metering target
      * @param mode: Camera spot metering target
      * @return Execution result
      */
      chcnav_return_code_t (*get_spot_metering_target)(
          CHCNAV_CAMERA_SPOT_METERING_TARGET_STRUCT *target);

      /**
      * @brief Set camera white balance mode
      * @param mode: Camera white balance mode
      * @return Execution result
      */
      chcnav_return_code_t (*set_white_balance_mode)(
          CHCNAV_CAMERA_WHITE_BALANCE_MODE_E mode);

      /**
      * @brief Get camera white balance mode
      * @param mode: Camera white balance mode
      * @return Execution result
      */
      chcnav_return_code_t (*get_white_balance_mode)(
          CHCNAV_CAMERA_WHITE_BALANCE_MODE_E *mode);

      /**
      * @brief Set camera brightness
      * @param value: Camera brightness, range 0-100.
      * @return Execution result
      */
      chcnav_return_code_t (*set_brightness)(uint8_t value);

      /**
      * @brief Get camera brightness
      * @param value: Camera brightness, range 0-100.
      * @return Execution result
      */
      chcnav_return_code_t (*get_brightness)(uint8_t *value);

      /**
      * @brief Set camera saturation
      * @param value: Camera saturation, range 0-100.
      * @return Execution result
      */
      chcnav_return_code_t (*set_saturation)(uint8_t value);

      /**
      * @brief Get camera saturation
      * @param value: Camera saturation, range 0-100.
      * @return Execution result
      */
      chcnav_return_code_t (*get_saturation)(uint8_t *value);

      /**
      * @brief Set camera contrast
      * @param value: Camera contrast, range 0-100.
      * @return Execution result
      */
      chcnav_return_code_t (*set_contrast)(uint8_t value);

      /**
      * @brief Get camera contrast
      * @param value: Camera contrast, range 0-100.
      * @return Execution result
      */
      chcnav_return_code_t (*get_contrast)(uint8_t *value);

      /**
      * @brief Set camera sharpness
      * @param value: Camera sharpness, range 0-100.
      * @return Execution result
      */
      chcnav_return_code_t (*set_sharpness)(uint8_t value);

      /**
      * @brief Get camera sharpness
      * @param value: Camera sharpness, range 0-100.
      * @return Execution result
      */
      chcnav_return_code_t (*get_sharpness)(uint8_t *value);

      /**
      * @brief Set camera color mode
      * @param value: Camera color mode
      * @return Execution result
      */
      chcnav_return_code_t (*set_color_mode)(CHCNAV_CAMERA_COLOR_MODE_E mode);

      /**
      * @brief Get camera color mode
      * @param value: Camera color mode
      * @return Execution result
      */
      chcnav_return_code_t (*get_color_mode)(CHCNAV_CAMERA_COLOR_MODE_E *mode);

      /**
      * @brief Get camera capture interval
      * @param value: Camera capture interval, in milliseconds
      * @return Execution result
      */
      chcnav_return_code_t (*get_capture_interval)(uint32_t *value);

      /**
      * @brief Set camera picture format
      * @param format: Camera picture format
      * @return Execution result
      */
      chcnav_return_code_t (*set_picture_format)(
          CHCNAV_CAMERA_PICTURE_FORMAT_E format);

      /**
      * @brief Get camera picture format
      * @param format: Camera picture format
      * @return Execution result
      */
      chcnav_return_code_t (*get_picture_format)(
          CHCNAV_CAMERA_PICTURE_FORMAT_E *format);

      /**
      * @brief Set camera image quality
      * @param value: Camera image quality
      * @return Execution result
      */
      chcnav_return_code_t (*set_picture_quality)(
          CHCNAV_CAMERA_PICTURE_QUALITY_E value);

      /**
      * @brief Get camera image quality
      * @param value: Camera image quality
      * @return Execution result
      */
      chcnav_return_code_t (*get_picture_quality)(
          CHCNAV_CAMERA_PICTURE_QUALITY_E *value);

      /**
      * @brief Set camera encode format
      * @param value: Camera encode format
      * @return Execution result
      */
      chcnav_return_code_t (*set_video_encode_format)(
          CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_E value);

      /**
      * @brief Get camera encode format
      * @param value: Camera encode format
      * @return Execution result
      */
      chcnav_return_code_t (*get_video_encode_format)(
          CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_E *value);

      /**
      * @brief Set camera video record format
      * @param value: Camera video record format
      * @return Execution result
      */
      chcnav_return_code_t (*set_video_record_format)(
          CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_E value);

      /**
      * @brief Get camera video record format
      * @param value: Camera video record format
      * @return Execution result
      */
      chcnav_return_code_t (*get_video_record_format)(
          CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_E *value);

      /**
      * @brief Set camera media parameters
      * @param value: Camera media parameters
      * @return Execution result
      */
      chcnav_return_code_t (*set_media_config)(CHCNAV_CAMERA_CONFIG_STRUCT config);

      /**
      * @brief Get camera media parameters
      * @param value: Camera media parameters
      * @return Execution result
      */
      chcnav_return_code_t (*get_media_config)(CHCNAV_CAMERA_CONFIG_STRUCT *config);

      /**
      * @brief Set multiple camera parameters
      * @param exposure_mode: Exposure mode
      * @param shutter_speed: Shutter speed
      * @param aperture: Aperture
      * @param iso: ISO
      * @param exposure_compensation_value: Exposure compensation value
      * @return Execution result
      */
      chcnav_return_code_t (*set_digicam_config)(CHCNAV_CAMERA_EXPOSURE_MODE_E exposure_mode,uint32_t shutter_speed,float aperture,uint32_t iso,float exposure_compensation_value);

      /**
      * @brief Set camera source
      * @param device_id: 1-6 indicates camera ID; 0 represents all cameras.
      * @param video_stream_source: Set the RTSP stream source for the camera.
      * @return Execution result.
      */
      chcnav_return_code_t (*set_camera_source)(uint8_t device_id,CHCNAV_CAMERA_VIDEO_STREAM_SOURCE_TYPE_E video_stream_source);

      /**
      * @brief Set camera tracking point.
      * @param x: Camera tracking point x value, range: 0~1; 0 means left, 1 means right.
      * @param y: Camera tracking point y value, range: 0~1; 0 means left, 1 means right.
      * @param radius: Tracking point radius, range: 0~1; 0 means 1 pixel, 1 means the entire image.
      * @param device_id: Camera ID.
      * @return Execution result.
      */
      chcnav_return_code_t (*set_camera_track_point)(float x,float y,float radius,uint8_t device_id);

      /**
      * @brief Set infrared camera mode.
      * @param mode: Infrared camera mode; see CHCNAV_CAMERA_IR_MODE_E
      * @return Execution result.
      */
      chcnav_return_code_t (*set_camera_ir_mode) (CHCNAV_CAMERA_IR_MODE_E mode);
      /**
      * @brief Get infrared camera mode.
      * @param mode: Infrared camera mode; see CHCNAV_CAMERA_IR_MODE_E
      * @return Execution result.
      */
      chcnav_return_code_t (*get_camera_ir_mode) (CHCNAV_CAMERA_IR_MODE_E *mode);
      /**
      * @brief Set camera stream OSD configuration.
      * @param osd_config: Camera stream OSD configuration; see CHCNAV_CAMERA_OSD_CONFIGURE_STRUCT
      * @return Execution result.
      */
      chcnav_return_code_t (*set_stream_osd) (CHCNAV_CAMERA_OSD_CONFIGURE_STRUCT osd_config);
      /**
      * @brief Get camera stream OSD configuration.
      * @param osd_config: Camera stream OSD configuration; see CHCNAV_CAMERA_OSD_CONFIGURE_STRUCT
      * @return Execution result.
      */
      chcnav_return_code_t (*get_stream_osd) (CHCNAV_CAMERA_OSD_CONFIGURE_STRUCT *osd_config);
      /**
      * @brief Get the list of ISO values supported by the camera.
      * @param count: Number of ISO parameters the camera can set; up to 63 parameters can be added.
      * @param capability: List of ISO values supported by the camera.
      * @return Execution result.
      */
      chcnav_return_code_t (*get_camera_iso_list) (uint16_t *count, uint16_t *capability);
      /**
      * @brief Get the list of shutter speeds supported by the camera.
      * @param count: Number of shutter parameters the camera can set; up to 63 parameters can be added.
      * @param capability: List of shutter speeds supported by the camera.
      * @return Execution result.
      */
      chcnav_return_code_t (*get_camera_shutter_list) (uint16_t *count, uint16_t *capability);
      /**
      * @brief Get the list of infrared color modes supported by the camera.
      * @param count: Number of infrared color mode parameters the camera can set; up to 63 parameters can be added.
      * @param capability: List of infrared color modes supported by the camera.
      * @return Execution result.
      */
      chcnav_return_code_t (*get_camera_ir_color_list) (uint16_t *count, uint16_t *capability);
    } CHCNAV_CAMERA_PARAMETER_HANDLER_STRUCT;
  ```
### CHCNAV_CAMERA_ZOOM_HANDLER_STRUCT
  Zoom functionality interface for camera payloads. Use the functions in this structure to implement the corresponding callback functions, including:
  - Get camera zoom configuration parameters
  - Step zoom interface
  - Continuous zoom interface
  - Zoom by factor interface
  ```
    typedef struct {
      /**
      * @brief Get camera zoom configuration parameters.
      * @param zoom_config: Camera zoom configuration.
      * @return Execution result.
      */
      chcnav_return_code_t (*get_camera_zoom_configure)(CHCNAV_CAMERA_ZOOM_CONFIGURE_STRUCT* zoom_config);
      /**
      * @brief Zoom in or out by 0.1x in the specified direction.
      * @param direction: Zoom direction; see CHCNAV_CAMERA_ZOOM_DIRECTION_E.
      * @return Execution result.
      */
      chcnav_return_code_t (*camera_zoom_step)(CHCNAV_CAMERA_ZOOM_DIRECTION_E direction);
      /**
      * @brief Continuously zoom in the specified direction until camera_continuous_zoom_stop is received.
      * @param direction: Zoom direction; see CHCNAV_CAMERA_ZOOM_DIRECTION_E.
      * @return Execution result.
      */
      chcnav_return_code_t (*camera_continuous_zoom_start)(CHCNAV_CAMERA_ZOOM_DIRECTION_E direction);
      /**
      * @brief Stop continuous zoom.
      * @return Execution result.
      */
      chcnav_return_code_t (*camera_continuous_zoom_stop)();
      /**
      * @brief Zoom by the specified factor.
      * @param factor: Zoom factor.
      * @return Execution result.
      */
      chcnav_return_code_t (*camera_zoom_by_value)(float factor);
    } CHCNAV_CAMERA_ZOOM_HANDLER_STRUCT;
  ```
### CHCNAV_CAMERA_FOCUS_HANDLER_STRUCT
  Focus functionality interface for camera payloads. Use the functions in this structure to implement the corresponding callback functions, including:
  - Get camera focus configuration parameters
  - Manual focus interface
  - Auto focus interface
  ```
    typedef struct {
      /**
      * @brief Get camera focus configuration.
      * @param focus_config: Camera focus configuration.
      * @return Execution result.
      */
      chcnav_return_code_t (*get_camera_focus_configure)(CHCNAV_CAMERA_FOCUS_CONFIGURE_STRUCT* focus_configs);
      /**
      * @brief Set focus manually.
      * @param value: Focus value (set as a percentage), range: 0~100.
      * @return Execution result.
      */
      chcnav_return_code_t (*camera_manual_focus)(float value);
      /**
      * @brief C continuous auto focus.
      * @return Execution result.
      */
      chcnav_return_code_t (*camera_auto_continuous_focus)();
    } CHCNAV_CAMERA_FOCUS_HANDLER_STRUCT;
  ```
## Function
### chcnav_payload_camera_init
  Initialize the camera-class payload device module.
### chcnav_payload_camera_register_common_handler
  Register the handler for basic camera-class payload device functionality.
### chcnav_payload_camera_register_parameter_handler
  Register the handler for camera-class payload device parameter get/set functionality.
### chcnav_camera_zoom_handler
  Register the handler for camera-class payload device zoom functionality.
### chcnav_camera_focus_handler
  Register the handler for camera-class payload device focus functionality.
### chcnav_payload_camera_get_video_stream_network_address
  Interface for retrieving the network address of a camera-class payload device.
