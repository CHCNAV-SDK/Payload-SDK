# Camera Management
This document describes the key information and usage of structures and function prototypes in the `chcnav_camera_manager.h` file.
- Enum
  * CHCNAV_CAMETA_MANAGER_WORK_MODE_E
  * CHCNAV_CAMERA_MANAGER_SHOOT_PHOTO_MODE_E
  * CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_E
  * CHCNAV_CAMERA_MANAGER_FOCUS_MODE_E
  * CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_E
  * CHCNAV_CAMERA_MANAGER_ISO_E
  * CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_E
  * CHCNAV_CAMERA_MANAGER_APERTURE_E
  * CHCNAV_CAMERA_MANAGER_METERING_MODE_E
  * CHCNAV_CAMERA_MANAGER_CAPTURING_STATE_E
  * CHCNAV_CAMERA_MANAGER_RECORDING_STATE_E
- Struct
  * CHCNAV_CAMERA_MANAGER_FIRMWARE_VERSION_STRUCT
  * CHCNAV_CAMERA_MANAGER_STORAGE_INFO_STRUCT
- Function
  * chcnav_camera_manager_init
  * chcnav_camera_manager_deinit
  * chcnav_camera_manager_get_camera_type
  * chcnav_camera_manager_get_firmware_version
  * chcnav_camera_manager_get_camera_connect_status
  * chcnav_camera_manager_set_mode
  * chcnav_camera_manager_get_mode
  * chcnav_camera_manager_set_photo_time_interval_settings
  * chcnav_camera_manager_get_photo_time_interval_settings
  * chcnav_camera_manager_start_shoot_photo
  * chcnav_camera_manager_stop_shoot_photo
  * chcnav_camera_manager_get_capturing_state
  * chcnav_camera_manager_set_focus_mode
  * chcnav_camera_manager_get_focus_mode
  * chcnav_camera_manager_trigger_focus
  * chcnav_camera_manager_start_continuous_zoom
  * chcnav_camera_manager_stop_continuous_zoom
  * chcnav_camera_manager_set_exposure_mode
  * chcnav_camera_manager_get_exposure_mode
  * chcnav_camera_manager_set_ISO
  * chcnav_camera_manager_get_ISO
  * chcnav_camera_manager_set_aperture
  * chcnav_camera_manager_get_aperture
  * chcnav_camera_manager_set_shutter_speed
  * chcnav_camera_manager_get_shutter_speed
  * chcnav_camera_manager_set_exposure_compensation
  * chcnav_camera_manager_get_exposure_compensation
  * chcnav_camera_manager_reset_camera_settings
  * chcnav_camera_manager_start_record_video
  * chcnav_camera_manager_stop_record_video
  * chcnav_camera_manager_get_recording_state
  * chcnav_camera_manager_get_recording_time
  * chcnav_camera_manager_format_storage
  * chcnav_camera_manager_get_storage_info
  * chcnav_camera_manager_set_metering_mode
  * chcnav_camera_manager_get_metering_mode
  * chcnav_camera_manager_get_metering_point_region_range
  * chcnav_camera_manager_set_metering_point
  * chcnav_camera_manager_get_metering_point

## Enum
### CHCNAV_CAMETA_MANAGER_WORK_MODE_E
  ```
    typedef enum {
        /*!
        - Photo mode. The user can take photos in this mode.
        */
        CHCNAV_CAMERA_MANAGER_WORK_MODE_SHOOT_PHOTO = 0,
        /*!
        - Video recording mode. The user can record video in this mode.
        */
        CHCNAV_CAMERA_MANAGER_WORK_MODE_RECORD_VIDEO = 1,
        /*!
        * Camera work mode is unknown.
        */
        CHCNAV_CAMERA_MANAGER_WORK_MODE_UNKNOWN = 0xFF,
    } CHCNAV_CAMETA_MANAGER_WORK_MODE_E;
  ```
### CHCNAV_CAMERA_MANAGER_SHOOT_PHOTO_MODE_E
  ```
    typedef enum {
        /*!
        - Single-shot mode.
        */
        CHCNAV_CAMERA_MANAGER_SHOOT_PHOTO_MODE_SINGLE = 0x01,
        /*!
        - Interval shooting mode.
        */
        CHCNAV_CAMERA_MANAGER_SHOOT_PHOTO_MODE_INTERVAL = 0x06,
        /*!
        - Shoot photo mode is unknown.
        */
        CHCNAV_CAMERA_MANAGER_SHOOT_PHOTO_MODE_UNKNOWN = 0xFF,
    } CHCNAV_CAMERA_MANAGER_SHOOT_PHOTO_MODE_E;
  ```
### CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_E
  ```
    typedef enum {
        CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_PROGRAM_AUTO = 1,       /*!< Auto mode */
        CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_SHUTTER_PRIORITY = 2,   /*!< Shutter priority mode */
        CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_APERTURE_PRIORITY = 3,  /*!< Aperture priority mode */
        CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_EXPOSURE_MANUAL = 4,    /*!< Manual mode */
        CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_UNKNOWN = 0xFF          /*!< Exposure mode is unknown. */
    } CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_E;
  ```
### CHCNAV_CAMERA_MANAGER_FOCUS_MODE_E
  ```
    typedef enum {
        /*!
        - Auto focus mode.
        */
        CHCNAV_CAMERA_MANAGER_FOCUS_MODE_AUTO = 1,
        /*!
        - Continuous auto focus mode.
        */
        CHCNAV_CAMERA_MANAGER_FOCUS_MODE_AFC = 2,
        /*!
        - Focus mode is unknown.
        */
        CHCNAV_CAMERA_MANAGER_FOCUS_MODE_UNKNOWN = 0xFF,
    } CHCNAV_CAMERA_MANAGER_FOCUS_MODE_E;
  ```
###  CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_E
  ```
    typedef enum {
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_8000 = 0,     /*!< 1/8000 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_6400 = 1,     /*!< 1/6400 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_6000 = 2,     /*!< 1/6000 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_5000 = 3,     /*!< 1/5000 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_4000 = 4,     /*!< 1/4000 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_3200 = 5,     /*!< 1/3200 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_3000 = 6,     /*!< 1/3000 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_2500 = 7,     /*!< 1/2500 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_2000 = 8,     /*!< 1/2000 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_1600 = 9,     /*!< 1/1600 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_1500 = 10,    /*!< 1/1500 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_1250 = 11,    /*!< 1/1250 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_1000 = 12,    /*!< 1/1000 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_800 = 13,     /*!< 1/800 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_725 = 14,     /*!< 1/725 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_640 = 15,     /*!< 1/640 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_500 = 16,     /*!< 1/500 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_400 = 17,     /*!< 1/400 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_320 = 19,     /*!< 1/320 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_200 = 22,     /*!< 1/200 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_100 = 27,     /*!< 1/100 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_90 = 28,      /*!< 1/90 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_80 = 29,      /*!< 1/80 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_60 = 30,      /*!< 1/60 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_50 = 31,      /*!< 1/50 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_40 = 32,      /*!< 1/40 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_30 = 33,      /*!< 1/30 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_20 = 35,      /*!< 1/20 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_10 = 38,      /*!< 1/10 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_5 = 41,       /*!< 1/5 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1 = 48,         /*!< 1.0 s */
        CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_UNKNOWN = 0xFF, /*!< Unknown */
    } CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_E;
  ```
### CHCNAV_CAMERA_MANAGER_ISO_E
  ```
    typedef enum {
        /*! Automatically set ISO value. Not available in manual mode on all cameras. */
        CHCNAV_CAMERA_MANAGER_ISO_AUTO = 0x00,
        /*! ISO value is set to 100. */
        CHCNAV_CAMERA_MANAGER_ISO_100 = 0x03,
        /*! ISO value is set to 200. */
        CHCNAV_CAMERA_MANAGER_ISO_200 = 0x04,
        /*! ISO value is set to 400.*/
        CHCNAV_CAMERA_MANAGER_ISO_400 = 0x05,
        /*! ISO value is set to 800.*/
        CHCNAV_CAMERA_MANAGER_ISO_800 = 0x06,
        /*! ISO value is set to 1600.*/
        CHCNAV_CAMERA_MANAGER_ISO_1600 = 0x07,
        /*! ISO value is set to 3200.*/
        CHCNAV_CAMERA_MANAGER_ISO_3200 = 0x08,
        /*! ISO value is set to 6400.*/
        CHCNAV_CAMERA_MANAGER_ISO_6400 = 0x09,
        /*! ISO value is set to 12800.*/
        CHCNAV_CAMERA_MANAGER_ISO_12800 = 0x0A,
        /*! ISO value is set to 25600.*/
        CHCNAV_CAMERA_MANAGER_ISO_25600 = 0x0B,
        /*! ISO value is fixed by camera firmware. */
        CHCNAV_CAMERA_MANAGER_ISO_FIXED = 0xFF,
    } CHCNAV_CAMERA_MANAGER_ISO_E;
  ```
### CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_E
  ```
    typedef enum {
        /*! Camera exposure compensation value is -5.0 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_5_0 = 1,
        /*! Camera exposure compensation value is -4.7 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_4_7 = 2,
        /*! Camera exposure compensation value is -4.3 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_4_3 = 3,
        /*! Camera exposure compensation value is -4.0 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_4_0 = 4,
        /*! Camera exposure compensation value is -3.7 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_3_7 = 5,
        /*! Camera exposure compensation value is -3.3 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_3_3 = 6,
        /*! Camera exposure compensation value is -3.0 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_3_0 = 7,
        /*! Camera exposure compensation value is -2.7 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_2_7 = 8,
        /*! Camera exposure compensation value is -2.3 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_2_3 = 9,
        /*! Camera exposure compensation value is -2.0 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_2_0 = 10,
        /*! Camera exposure compensation value is -1.7 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_1_7 = 11,
        /*! Camera exposure compensation value is -1.3 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_1_3 = 12,
        /*! Camera exposure compensation value is -1.0 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_1_0 = 13,
        /*! Camera exposure compensation value is -0.7 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_0_7 = 14,
        /*! Camera exposure compensation value is -0.3 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_0_3 = 15,
        /*! Camera exposure compensation value is 0.0 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_0_0 = 16,
        /*! Camera exposure compensation value is +0.3 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_0_3 = 17,
        /*! Camera exposure compensation value is +0.7 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_0_7 = 18,
        /*! Camera exposure compensation value is +1.0 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_1_0 = 19,
        /*! Camera exposure compensation value is +1.3 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_1_3 = 20,
        /*! Camera exposure compensation value is +1.7 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_1_7 = 21,
        /*! Camera exposure compensation value is +2.0 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_2_0 = 22,
        /*! Camera exposure compensation value is +2.3 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_2_3 = 23,
        /*! Camera exposure compensation value is +2.7 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_2_7 = 24,
        /*! Camera exposure compensation value is +3.0 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_3_0 = 25,
        /*! Camera exposure compensation value is +3.3 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_3_3 = 26,
        /*! Camera exposure compensation value is +3.7 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_3_7 = 27,
        /*! Camera exposure compensation value is +4.0 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_4_0 = 28,
        /*! Camera exposure compensation value is +4.3 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_4_3 = 29,
        /*! Camera exposure compensation value is +4.7 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_4_7 = 30,
        /*! Camera exposure compensation value is +5.0 ev.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_5_0 = 31,
        /*! Camera exposure compensation value is fixed by the camera.*/
        CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_FIXED = 0xFF,
    } CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_E;
  ```
### CHCNAV_CAMERA_MANAGER_APERTURE_E
  ```
    typedef enum {
        /*! Aperture value is f/1.6.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_1_DOT_6 = 160,
        /*! Aperture value is f/1.7.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_1_DOT_7 = 170,
        /*! Aperture value is f/1.8.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_1_DOT_8 = 180,
        /*! Aperture value is f/2.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_2 = 200,
        /*! Aperture value is f/2.2.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_2_DOT_2 = 220,
        /*! Aperture value is f/2.4.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_2_DOT_4 = 240,
        /*! Aperture value is f/2.5.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_2_DOT_5 = 250,
        /*! Aperture value is f/2.6.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_2_DOT_6 = 260,
        /*! Aperture value is f/2.8.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_2_DOT_8 = 280,
        /*! Aperture value is f/3.2.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_3_DOT_2 = 320,
        /*! Aperture value is f/3.4.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_3_DOT_4 = 340,
        /*! Aperture value is f/3.5.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_3_DOT_5 = 350,
        /*! Aperture value is f/4.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_4 = 400,
        /*! Aperture value is f/4.5.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_4_DOT_5 = 450,
        /*! Aperture value is f/4.8.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_4_DOT_8 = 480,
        /*! Aperture value is f/5.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_5 = 500,
        /*! Aperture value is f/5.6.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_5_DOT_6 = 560,
        /*! Aperture value is f/6.3.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_6_DOT_3 = 630,
        /*! Aperture value is f/6.8.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_6_DOT_8 = 680,
        /*! Aperture value is f/7.1.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_7_DOT_1 = 710,
        /*! Aperture value is f/8.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_8 = 800,
        /*! Aperture value is f/9.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_9 = 900,
        /*! Aperture value is f/9.6.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_9_DOT_6 = 960,
        /*! Aperture value is f/10.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_10 = 1000,
        /*! Aperture value is f/11.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_11 = 1100,
        /*! Aperture value is f/13.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_13 = 1300,
        /*! Aperture value is f/14.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_14 = 1400,
        /*! Aperture value is f/16.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_16 = 1600,
        /*! Aperture value is f/18.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_18 = 1800,
        /*! Aperture value is f/19.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_19 = 1900,
        /*! Aperture value is f/20.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_20 = 2000,
        /*! Aperture value is f/22.*/
        CHCNAV_CAMERA_MANAGER_APERTURE_F_22 = 2200,
        /*! Aperture value is unknown. */
        CHCNAV_CAMERA_MANAGER_APERTURE_F_UNKNOWN = 0xFFFF,
    } CHCNAV_CAMERA_MANAGER_APERTURE_E;
  ```
### CHCNAV_CAMERA_MANAGER_METERING_MODE_E
  ```
    typedef enum {
        CHCNAV_CAMERA_MANAGER_METERING_MODE_CENTRAL = 0,
        CHCNAV_CAMERA_MANAGER_METERING_MODE_AVERAGE = 1,
        CHCNAV_CAMERA_MANAGER_METERING_MODE_SPOT = 2,
        CHCNAV_CAMERA_MANAGER_METERING_MODE_UNKNOWN = 0xFF,
    } CHCNAV_CAMERA_MANAGER_METERING_MODE_E;
  ```
### CHCNAV_CAMERA_MANAGER_CAPTURING_STATE_E
  ```
    typedef enum {
        /* Not capturing */
        CHCNAV_CAMERA_MANAGER_CAPTURING_STATE_IDLE = 0,

        /* Single capture in progress */
        CHCNAV_CAMERA_MANAGER_CAPTURING_STATE_SINGLE = 1,

        /* Multiple capture in progress */
        CHCNAV_CAMERA_MANAGER_CAPTURING_STATE_MULTI = 2,
    } CHCNAV_CAMERA_MANAGER_CAPTURING_STATE_E;
  ```
### CHCNAV_CAMERA_MANAGER_RECORDING_STATE_E
  ```
    typedef enum {
        CHCNAV_CAMERA_MANAGER_RECORDING_STATE_IDLE = 0,
        CHCNAV_CAMERA_MANAGER_RECORDING_STATE_STARTING = 1,
        CHCNAV_CAMERA_MANAGER_RECORDING_STATE_RECORDING = 2,
        CHCNAV_CAMERA_MANAGER_RECORDING_STATE_STOPPING = 3,
    } CHCNAV_CAMERA_MANAGER_RECORDING_STATE_E;
  ```

## Struct
### CHCNAV_CAMERA_MANAGER_FIRMWARE_VERSION_STRUCT
  ```
    typedef struct {
        uint8_t firmware_version[4];
    } CHCNAV_CAMERA_MANAGER_FIRMWARE_VERSION_STRUCT;
  ```
### CHCNAV_CAMERA_MANAGER_STORAGE_INFO_STRUCT
  ```
    typedef struct {
        uint32_t total_capacity;     /* MByte */
        uint32_t remain_capacity;    /* MByte */
    } CHCNAV_CAMERA_MANAGER_STORAGE_INFO_STRUCT;
  ```

## Function
### chcnav_camera_manager_init
  **Function**: Initialize the camera management module.
  ```
    chcnav_return_code_t chcnav_camera_manager_init(void);
  ```
  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_deinit
  **Function**: Deinitialize the camera management module.
  ```
    chcnav_return_code_t chcnav_camera_manager_deinit(void);
  ```
  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_camera_type
  **Function**: Get the camera type at the selected mount position.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_camera_type(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_E *camera_type);
  ```
  **Parameters**:
  * position: Camera mount position.
  * camera_type: See `CHCNAV_CAMERA_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_firmware_version
  **Function**: Get the camera firmware version at the selected mount position.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_firmware_version(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_FIRMWARE_VERSION_STRUCT *firmware_version);
  ```
  **Parameters**:
  * position: Camera mount position.
  * firmware_version: See `CHCNAV_CAMERA_MANAGER_FIRMWARE_VERSION_STRUCT`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_camera_connect_status
  **Function**: Get the camera connection status at the selected mount position.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_camera_connect_status(CHCNAV_MOUNT_POSITION_E position, bool *connect_status);
  ```
  **Parameters**:
  * position: Camera mount position.
  * connect_status: Returned connection status.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_set_mode
  **Function**: Set the camera work mode at the selected mount position.
  ```
    chcnav_return_code_t chcnav_camera_manager_set_mode(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMETA_MANAGER_WORK_MODE_E work_mode);
  ```
  **Parameters**:
  * position: Camera mount position.
  * work_mode: See `CHCNAV_CAMETA_MANAGER_WORK_MODE_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_mode
  **Function**: Get the camera work mode at the selected mount position.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_mode(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMETA_MANAGER_WORK_MODE_E *work_mode);
  ```
  **Parameters**:
  * position: Camera mount position.
  * work_mode: See `CHCNAV_CAMETA_MANAGER_WORK_MODE_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_set_photo_time_interval_settings
  **Function**: Set interval shooting parameters for the camera at the selected mount position.
  > Note: After setting the photo interval mode and starting capture, the camera takes photos at the specified time interval until the required number of photos is complete.

  ```
    chcnav_return_code_t chcnav_camera_manager_set_photo_time_interval_settings(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT interval_setting);
  ```
  **Parameters**:
  * position: Camera mount position.
  * interval_setting: See `CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_photo_time_interval_settings
  **Function**: Get interval shooting parameters for the camera at the selected mount position.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_photo_time_interval_settings(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT *interval_setting);
  ```
  **Parameters**:
  * position: Camera mount position.
  * interval_setting: See `CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_start_shoot_photo
  **Function**: Start taking photos.
   > Note: The camera must be in photo mode.

  ```
    chcnav_return_code_t chcnav_camera_manager_start_shoot_photo(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_SHOOT_PHOTO_MODE_E mode);
  ```
  **Parameters**:
  * position: Camera mount position.
  * mode: See `CHCNAV_CAMERA_MANAGER_SHOOT_PHOTO_MODE_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_stop_shoot_photo
  **Function**: Stop taking photos.
  ```
    chcnav_return_code_t chcnav_camera_manager_stop_shoot_photo(CHCNAV_MOUNT_POSITION_E position);
  ```
  **Parameters**:
  * position: Camera mount position.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_capturing_state
  **Function**: Get the camera capturing state.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_capturing_state(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_CAPTURING_STATE_E *capturing_state);
  ```
  **Parameters**:
  * position: Camera mount position.
  * capturing_state: See `CHCNAV_CAMERA_MANAGER_CAPTURING_STATE_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_set_focus_mode
  **Function**: Set the camera focus mode at the selected mount position.
  ```
    chcnav_return_code_t chcnav_camera_manager_set_focus_mode(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_FOCUS_MODE_E focus_value);
  ```
  **Parameters**:
  * position: Camera mount position.
  * focus_value: See `CHCNAV_CAMERA_MANAGER_FOCUS_MODE_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_focus_mode
  **Function**: Get the camera focus mode at the selected mount position.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_focus_mode(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_FOCUS_MODE_E *focus_mode);
  ```
  **Parameters**:
  * position: Camera mount position.
  * focus_value: See `CHCNAV_CAMERA_MANAGER_FOCUS_MODE_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_trigger_focus
  **Function**: Trigger a single focus operation.
  > Note: Effective when the focus mode is set to auto focus.

  ```
    chcnav_return_code_t chcnav_camera_manager_trigger_focus(CHCNAV_MOUNT_POSITION_E position);
  ```
  **Parameters**:
  * position: Camera mount position.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_start_continuous_zoom
  **Function**: Start continuous zoom for the camera at the selected mount position.
  > Note: Changes the lens focal length in the specified direction. Focal length change stops when the maximum or minimum focal length is reached, or when `chcnav_camera_manager_stop_continuous_zoom` is called.

  ```
    chcnav_return_code_t chcnav_camera_manager_start_continuous_zoom(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_ZOOM_DIRECTION_E zoom_direction);
  ```
  **Parameters**:
  * position: Camera mount position.
  * zoom_direction: See `CHCNAV_CAMERA_ZOOM_DIRECTION_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_stop_continuous_zoom
  **Function**: Stop continuous zoom for the camera at the selected mount position.
  > Note: Call this function to stop zoom when focal length is changing after `chcnav_camera_manager_start_continuous_zoom` was called.

  ```
    chcnav_return_code_t chcnav_camera_manager_stop_continuous_zoom(CHCNAV_MOUNT_POSITION_E position);
  ```
  **Parameters**:
  * position: Camera mount position.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_set_exposure_mode
  **Function**: Set the camera exposure mode at the selected mount position.
  > Note: Different exposure modes define whether aperture, shutter speed, and ISO can be set automatically or manually.

  ```
    chcnav_return_code_t chcnav_camera_manager_set_exposure_mode(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_E mode);
  ```
  **Parameters**:
  * position: Camera mount position.
  * mode: See `CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_exposure_mode
  **Function**: Get the camera exposure mode at the selected mount position.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_exposure_mode(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_E *mode);
  ```
  **Parameters**:
  * position: Camera mount position.
  * mode: See `CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_set_ISO
  **Function**: Set the ISO value at the selected mount position.
  > Note: ISO can only be set when the camera exposure mode is manual.

  ```
    chcnav_return_code_t chcnav_camera_manager_set_ISO(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_ISO_E iso);
  ```
  **Parameters**:
  * position: Camera mount position.
  * iso: See `CHCNAV_CAMERA_MANAGER_ISO_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_ISO
  **Function**: Get the ISO value at the selected mount position.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_ISO(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_ISO_E *iso);
  ```
  **Parameters**:
  * position: Camera mount position.
  * iso: See `CHCNAV_CAMERA_MANAGER_ISO_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_set_aperture
  **Function**: Set the aperture value at the selected mount position.
  > Note: Aperture can only be set when the camera exposure mode is manual or aperture priority.

  ```
    chcnav_return_code_t chcnav_camera_manager_set_aperture(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_APERTURE_E aperture);
  ```
  **Parameters**:
  * position: Camera mount position.
  * aperture: See `CHCNAV_CAMERA_MANAGER_APERTURE_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_aperture
  **Function**: Get the aperture value at the selected mount position.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_aperture(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_APERTURE_E *aperture);
  ```
  **Parameters**:
  * position: Camera mount position.
  * aperture: See `CHCNAV_CAMERA_MANAGER_APERTURE_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_set_shutter_speed
  **Function**: Set the camera shutter speed at the selected mount position.
  > Note: Sets the camera shutter speed. When the camera is in RECORD_VIDEO mode, shutter speed must not be slower than the video frame rate; for example, if the video frame rate is 30 fps, shutter speed must be <= 1/30.
  Shutter speed can only be set when the camera exposure mode is manual or shutter priority.

  ```
    chcnav_return_code_t chcnav_camera_manager_set_shutter_speed(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_E shutter_speed);
  ```
  **Parameters**:
  * position: Camera mount position.
  * shutter_speed: See `CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_shutter_speed
  **Function**: Get the camera shutter speed at the selected mount position.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_shutter_speed(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_E *shutter_speed);
  ```
  **Parameters**:
  * position: Camera mount position.
  * shutter_speed: See `CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_set_exposure_compensation
  **Function**: Set the camera exposure compensation at the selected mount position.
  > Note: Exposure compensation is effective when the camera exposure mode is set to auto, aperture priority, or shutter priority.

  ```
    chcnav_return_code_t chcnav_camera_manager_set_exposure_compensation(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_E ev);
  ```
  **Parameters**:
  * position: Camera mount position.
  * ev: See `CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_exposure_compensation
  **Function**: Get the camera exposure compensation at the selected mount position.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_exposure_compensation(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_E *ev);
  ```
  **Parameters**:
  * position: Camera mount position.
  * ev: See `CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_reset_camera_settings
  **Function**: Reset camera settings.
  ```
    chcnav_return_code_t chcnav_camera_manager_reset_camera_settings(CHCNAV_MOUNT_POSITION_E position);
  ```
  **Parameters**:
  * position: Camera mount position.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_start_record_video
  **Function**: Start video recording.
  > Note: The camera must be in RECORD_VIDEO mode.

  ```
    chcnav_return_code_t chcnav_camera_manager_start_record_video(CHCNAV_MOUNT_POSITION_E position);
  ```
  **Parameters**:
  * position: Camera mount position.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_stop_record_video
  **Function**: Stop video recording.
  > Note: Effective when the camera is recording normally.

  ```
    chcnav_return_code_t chcnav_camera_manager_stop_record_video(CHCNAV_MOUNT_POSITION_E position);
  ```
  **Parameters**:
  * position: Camera mount position.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_recording_state
  **Function**: Get the camera recording state.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_recording_state(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_RECORDING_STATE_E *recording_state);
  ```
  **Parameters**:
  * position: Camera mount position.
  * recording_state: See `CHCNAV_CAMERA_MANAGER_RECORDING_STATE_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_recording_time
  **Function**: Get the camera recording duration.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_recording_time(CHCNAV_MOUNT_POSITION_E position, uint16_t *recording_time);
  ```
  **Parameters**:
  * position: Camera mount position.
  * recording_time: Retrieved recording duration, in seconds.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_format_storage
  **Function**: Format the SD card.
  ```
    chcnav_return_code_t chcnav_camera_manager_format_storage(CHCNAV_MOUNT_POSITION_E position);
  ```
  **Parameters**:
  * position: Camera mount position.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_storage_info
  **Function**: Get SD card storage information.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_storage_info(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_STORAGE_INFO_STRUCT *storage_info);
  ```
  **Parameters**:
  * position: Camera mount position.
  * storage_info: See `CHCNAV_CAMERA_MANAGER_STORAGE_INFO_STRUCT`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_set_metering_mode
  **Function**: Set the camera metering mode at the selected mount position.
  ```
    chcnav_return_code_t chcnav_camera_manager_set_metering_mode(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_METERING_MODE_E metering_mode);
  ```
  **Parameters**:
  * position: Camera mount position.
  * metering_mode: See `CHCNAV_CAMERA_MANAGER_METERING_MODE_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_metering_mode
  **Function**: Get the camera metering mode at the selected mount position.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_metering_mode(CHCNAV_MOUNT_POSITION_E position, CHCNAV_CAMERA_MANAGER_METERING_MODE_E *metering_mode);
  ```
  **Parameters**:
  * position: Camera mount position.
  * metering_mode: See `CHCNAV_CAMERA_MANAGER_METERING_MODE_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_metering_point_region_range
  **Function**: Get the metering point region range.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_metering_point_region_range(CHCNAV_MOUNT_POSITION_E position, uint8_t *hrz_num, uint8_t *vtc_num);
  ```
  **Parameters**:
  * position: Camera mount position.
  * hrz_num: Returned horizontal range value.
  * vtc_num: Returned vertical range value.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_set_metering_point
  **Function**: Set the metering point.
  ```
    chcnav_return_code_t chcnav_camera_manager_set_metering_point(CHCNAV_MOUNT_POSITION_E position, uint8_t x, uint8_t y);
  ```
  **Parameters**:
  * position: Camera mount position.
  * x: Horizontal coordinate value; must not exceed hrz_num - 1.
  * y: Vertical coordinate value; must not exceed vtc_num - 1.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_camera_manager_get_metering_point
  **Function**: Get the metering point.
  ```
    chcnav_return_code_t chcnav_camera_manager_get_metering_point(CHCNAV_MOUNT_POSITION_E position, uint8_t *x, uint8_t *y);
  ```
  **Parameters**:
  * position: Camera mount position.
  * x: Retrieved horizontal coordinate value.
  * y: Retrieved vertical coordinate value.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
