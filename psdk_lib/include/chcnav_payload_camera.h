/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file chcnav_payload_camera.h
 * @brief This is the header file for "chcnav_payload_camera.cpp",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/
#ifndef CHCNAV_PAYLOAD_CAMERA_H
#define CHCNAV_PAYLOAD_CAMERA_H

#include "chcnav_typedef.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Camera work mode.
 */
typedef enum {
  CHCNAV_CAMERA_MODE_IMAGE = 0, /* Camera is in image/image capture mode. */
  CHCNAV_CAMERA_MODE_VIDEO = 1, /* Camera is in video capture mode. */
  CHCNAV_CAMERA_MODE_IMAGE_SURVEY =
      2 /* Camera is in image survey capture mode.  */
} CHCNAV_CAMERA_MODE_E;

/**
 * @brief Camera capture image mode.
 */
typedef enum {
  CHCNAV_CAMERA_CAPTURE_MODE_SINGLE = 1,   /* Single capture mode. */
  CHCNAV_CAMERA_CAPTURE_MODE_INTERVAL = 2, /* Interval capture mode. */
} CHCNAV_CAMERA_CAPTURE_MODE_E;

/**
 * @brief Information about the status of a capture.
 */
typedef enum {
  CHCNAV_CAMERA_CAPTURING_PHOTO_IDLE = 0,   /* Image capturing in idle state. */
  CHCNAV_CAMERA_CAPTURING_SINGLE_PHOTO = 1, /* Image capture in progress. */
  CHCNAV_CAMERA_CAPTURING_INTERVAL_PHOTO_IDLE =
      2, /* Image capturing interval set but idle. */
  CHCNAV_CAMERA_CAPTURING_INTERVAL_PHOTO =
      3 /* Image capturing interval set and capture in progress. */
} CHCNAV_CAMERA_CAPTURE_STATE_E;

/**
 * @brief Camera metering mode.
 */
typedef enum {
  CHCNAV_CAMERA_METERING_MODE_CENTER = 0,  /* Center metering mode. */
  CHCNAV_CAMERA_METERING_MODE_AVERAGE = 1, /* Average metering mode. */
  CHCNAV_CAMERA_METERING_MODE_SPOT = 2     /* Spot metering mode. */
} CHCNAV_CAMERA_METERING_MODE_E;

/**
 * @brief Camera focus mode.
 */
typedef enum {
  CHCNAV_CAMERA_FOCUS_TYPE_STEP =
      0, /* Focus one step increment (-1 for focusing in, 1 for focusing out
            towards infinity). */
  CHCNAV_CAMERA_FOCUS_TYPE_CONTINUOUS =
      1, /* Continuous focus up/down until stopped (-1 for focusing in, 1 for
            focusing out towards infinity, 0 to stop focusing). */
  CHCNAV_CAMERA_FOCUS_TYPE_RANGE =
      2, /* Focus value as proportion of full camera focus range (a value
            between 0.0 and 100.0) */
  CHCNAV_CAMERA_FOCUS_TYPE_METERS = 3, /*Focus value in metres. */
  CHCNAV_CAMERA_FOCUS_TYPE_AUTO = 4,   /* Focus automatically.*/
  CHCNAV_CAMERA_FOCUS_TYPE_AUTO_SINGLE =
      5, /*Single auto focus. Mainly used for still pictures. */
  CHCNAV_CAMERA_FOCUS_TYPE_AUTO_CONTINUOUS =
      6 /*Continuous auto focus. Mainly used for dynamic scenes. */
} CHCNAV_CAMERA_FOCUS_MODE_E;

/**
 * @brief Camera zoom mode.
 */
typedef enum {
  CHCNAV_CAMERA_ZOOM_MODE_STEP =
      0, /*Zoom one step increment (-1 for wide, 1 for tele)*/
  CHCNAV_CAMERA_ZOOM_MODE_CONTINUOUS =
      1, /*Continuous zoom up/down until stopped (-1 for wide, 1 for tele, 0 to
            stop zooming)*/
  CHCNAV_CAMERA_ZOOM_MODE_RANGE =
      2, /*Zoom value as proportion of full camera range (a percentage value
            between 0.0 and 100.0)*/
  CHCNAV_CAMERA_ZOOM_MODE_FOCAL_LENGTH =
      3, /*Zoom value/variable focal length in millimetres. */
  CHCNAV_CAMERA_ZOOM_MODE_HORIZONTAL_FOV =
      4, /*Zoom value as horizontal field of view in degrees.*/
  CHCNAV_CAMERA_ZOOM_TYPE_ENUM_END=5,
} CHCNAV_CAMERA_ZOOM_MODE_E;

/**
 * @brief Sdcard status.
 */
typedef enum {
  CHCNAV_CAMERA_SDCARD_STATUS_EMPTY = 0, /*no sdcard*/
  CHCNAV_CAMERA_SDCARD_STATUS_UNFORMATTED =
      1,                                 /*Sdcard present but unformatted. */
  CHCNAV_CAMERA_SDCARD_STATUS_READY = 2, /*Sdcard present and ready.*/
  CHCNAV_CAMERA_SDCARD_STATUS_NOT_SUPPORTED =
      3, /*Camera does not supply sdcard status information.*/
} CHCNAV_CAMERA_SDCARD_STATUS_E;

/**
 * @brief Sdcard usage.
 */
typedef enum {
  CHCNAV_CAMERA_SDCARD_USAGE_FLAG_SET =
      1, /* Always set to 1 (sdcard_usage is supported). | */
  CHCNAV_CAMERA_SDCARD_USAGE_FLAG_PHOTO = 2, /* Sdcard for saving photos. | */
  CHCNAV_CAMERA_SDCARD_USAGE_FLAG_VIDEO = 4, /* Sdcard for saving videos. | */
  CHCNAV_CAMERA_SDCARD_USAGE_FLAG_LOGS = 8,  /* Sdcard for saving logs. | */
  CHCNAV_CAMERA_SDCARD_USAGE_FLAG_ENUM_END = 9, /*  | */
} CHCNAV_CAMERA_SDCARD_USAGE_FLAG_E;

/**
 * @brief Camera exposure mode.
 */
typedef enum {
  CHCNAV_CAMERA_EXPOSURE_MODE_AUTO = 1,              /*!< Program mode */
  CHCNAV_CAMERA_EXPOSURE_MODE_SHUTTER_PRIORITY = 2,  /*!< Shutter priority mode */
  CHCNAV_CAMERA_EXPOSURE_MODE_APERTURE_PRIORITY = 3, /*!< Aperture priority mode */
  CHCNAV_CAMERA_EXPOSURE_MODE_MANUAL = 4,            /*!< Manual mode */
  CHCNAV_CAMERA_EXPOSURE_MODE_UNKNOWN = 0xFF /*!< The camera exposure mode is unknown. */
} CHCNAV_CAMERA_EXPOSURE_MODE_E;

/**
 * @brief Camera white balance mode.
 */
typedef enum {
  CHCNAV_CAMERA_WHITE_BALANCE_MODE_AUTO = 0,
  CHCNAV_CAMERA_WHITE_BALANCE_MODE_INCANDESCENT = 1, /*Incandescent lamp*/
  CHCNAV_CAMERA_WHITE_BALANCE_MODE_SUNSET = 3,       /*Sunset mode*/
  CHCNAV_CAMERA_WHITE_BALANCE_MODE_SUNNY = 4,        /*Sunny mode*/
  CHCNAV_CAMERA_WHITE_BALANCE_MODE_CLOUDY = 5,       /*Cloudy mode*/
  CHCNAV_CAMERA_WHITE_BALANCE_MODE_FLUORESCENT = 7,  /*Fluorescent lamp mode*/
  CHCNAV_CAMERA_WHITE_BALANCE_MODE_UNKNOWN = 0xFF
} CHCNAV_CAMERA_WHITE_BALANCE_MODE_E;

/**
 * @brief Camera color mode.
 */
typedef enum {
  CHCNAV_CAMERA_COLOR_MODE_NEUTRAL = 0,
  CHCNAV_CAMERA_COLOR_MODE_ENHANCED = 1,
  CHCNAV_CAMERA_COLOR_MODE_UNPROCESSED = 2,
  CHCNAV_CAMERA_COLOR_MODE_NIGHT = 3,
} CHCNAV_CAMERA_COLOR_MODE_E;

/**
 * @brief Camera picture format.
 */
typedef enum {
  CHCNAV_CAMERA_PICTURE_FORMAT_JPEG = 0,
  CHCNAV_CAMERA_PICTURE_FORMAT_RAW = 1,
  CHCNAV_CAMERA_PICTURE_FORMAT_JPEG_RAW = 2,
} CHCNAV_CAMERA_PICTURE_FORMAT_E;

/**
 * @brief Camera picture quality.
 */
typedef enum {
  CHCNAV_CAMERA_PICTURE_QUALITY_LOW = 0,
  CHCNAV_CAMERA_PICTURE_QUALITY_MEDIUM = 1,
  CHCNAV_CAMERA_PICTURE_QUALITY_HIGH = 2,
  CHCNAV_CAMERA_PICTURE_QUALITY_ULTRA = 3,
} CHCNAV_CAMERA_PICTURE_QUALITY_E;

/**
 * @brief Camera video encode format.
 */
typedef enum {
  CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_H264 = 1,
  CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_HEVC = 3,
  CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_MPEG = 4,
} CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_E;

/**
 * @brief Camera video record format.
 */
typedef enum {
  CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_AOV = 0,
  CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_MP4 = 1,
  CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_TS = 5,
} CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_E;

/**
 * @brief Camera video stream type.
 */
typedef enum
{
   CHCNAV_CAMERA_VIDEO_STREAM_TYPE_RTSP=0, /* Stream is RTSP */
   CHCNAV_CAMERA_VIDEO_STREAM_TYPE_RTPUDP=1, /* Stream is RTP UDP */
   CHCNAV_CAMERA_VIDEO_STREAM_TYPE_TCP_MPEG=2, /* Stream is MPEG on TCP */
   CHCNAV_CAMERA_VIDEO_STREAM_TYPE_MPEG_TS_H264=3, /* Stream is h.264 on MPEG TS */
   CHCNAV_CAMERA_VIDEO_STREAM_TYPE_ENUM_END=4,
} CHCNAV_CAMERA_VIDEO_STREAM_TYPE_E;

/**
 * @brief Camera video stream flags.
 */
typedef enum
{
   CHCNAV_CAMERA_VIDEO_STREAM_STATUS_FLAGS_RUNNING=1, /* Stream is active (running) */
   CHCNAV_CAMERA_VIDEO_STREAM_STATUS_FLAGS_THERMAL=2, /* Stream is thermal imaging */
   CHCNAV_CAMERA_VIDEO_STREAM_STATUS_FLAGS_ENUM_END=3,
} CHCNAV_CAMERA_VIDEO_STREAM_STATUS_FLAGS_E;

typedef enum
{
   CHCNAV_CAMERA_SOURCE_DEFAULT=0, /* Default camera source. */
   CHCNAV_CAMERA_SOURCE_RGB=1, /* RGB camera source. */
   CHCNAV_CAMERA_SOURCE_IR=2, /* IR camera source. */
   CHCNAV_CAMERA_SOURCE_NDVI=3, /* NDVI camera source. */
} CHCNAV_CAMERA_SOURCE_E;

typedef enum {
  CHCNAV_STREAM_OSD_MODE_CLOSED = 0, /* camerea osd closed. */
  CHCNAV_STREAM_OSD_MODE_OPEN = 1,   /* camerea osd is opened. */
} CHCNAV_STREAM_OSD_MODE_E;

typedef enum {
  CHCNAV_CAMERA_IR_MODE_WHITE_HOT = 0, /* IR camerea white hot mode. */
  CHCNAV_CAMERA_IR_MODE_BLACK_HOT = 1,   /* IR camerea black hot mode. */
  CHCNAV_CAMERA_IR_MODE_PSEUDO_COLOR = 2, /* IR camerea pseudo color mode. */
} CHCNAV_CAMERA_IR_MODE_E;

/**
 * @brief Camera metering range when in spot metering mode.
 */
typedef struct {
  uint8_t col; /* Specifies column coordinate. */
  uint8_t row; /* Specifies row coordinate. */
} CHCNAV_CAMERA_SPOT_METERING_RANGE_STRUCT;

/**
 * @brief Camera metering target when in spot metering mode.
 */
typedef struct {
  uint8_t col; /* Specifies column coordinate. */
  uint8_t row; /* Specifies row coordinate. */
} CHCNAV_CAMERA_SPOT_METERING_TARGET_STRUCT;

/**
 * @brief Camera focus assistant settings.
 */
typedef struct {
  bool is_enabled_mf; /* Specifies if the lens focus assistant is enabled for
                         manual focusing. */
  bool is_enabled_af; /* Specifies if the lens focus assistant is enabled for
                         auto focusing. */
} CHCNAV_CAMERA_FOCUS_ASSISTANT_SETTINGS_STRUCT;

/**
 * @brief Information about camera sdcard.
 */
typedef struct {
  uint8_t storage_id;    /*Storage ID (1 for first, 2 for second, etc.)*/
  uint8_t storage_count; /*Number of storage devices.*/
  CHCNAV_CAMERA_SDCARD_STATUS_E status; /*Status of sdcard.*/
  CHCNAV_CAMERA_SDCARD_USAGE_FLAG_E
      storage_usage; /*Flags indicating whether this instance is preferred
                        storage for photos, videos, etc.
                        (CHCNAV_CAMERA_SDCARD_USAGE_FLAG_E)*/
  uint32_t total_capacity_mb; /*Total capacity.if sdcard is not ready value will
                                 be ignored.*/
  uint32_t used_capacity_mb;  /*Used capacity. if sdcard is not ready value will
                                 be ignored.*/
  uint32_t available_capacity_mb; /*Available capacity. if sdcard is not ready
                                     value will be ignored.*/
  uint32_t read_speed_mb_per_second;  /*Read speed. if sdcard is not ready value
                                         will be ignored.*/
  uint32_t write_speed_mb_per_second; /*Write speed. if sdcard is not ready
                                         value will be ignored.*/
} CHCNAV_CAMERA_SDCARD_STATE_STRUCT;

typedef struct {
  uint8_t storage_count;     /*Number of storage devices.*/
  uint32_t firmware_version; /*<  Version of the camera firmware, encoded as:
                                (Dev & 0xff) << 24 | (Patch & 0xff) << 16 |
                                (Minor & 0xff) << 8 | (Major & 0xff)*/
  float focal_length;        /*< [mm] Focal length*/
  float sensor_size_h;       /*< [mm] Image sensor size horizontal*/
  float sensor_size_v;       /*< [mm] Image sensor size vertical*/
  uint32_t flags;            /*<  Not use.*/
  uint16_t resolution_h;     /*< [pix] Horizontal image resolution*/
  uint16_t resolution_v;     /*< [pix] Vertical image resolution*/
  uint16_t cam_definition_version; /*<  Camera definition version (iteration)*/
  uint8_t vendor_name[32];         /*<  Name of the camera vendor*/
  uint8_t model_name[32];          /*<  Name of the camera model*/
  uint8_t lens_id; /*<  Reserved for a lens ID.Use 0 if not known.*/
  char cam_definition_uri
      [140]; /*<  Camera definition URI (if any, otherwise only basic functions
                will be available). HTTP- (http://) and MAVLink FTP-
                (mavlinkftp://) formatted URIs are allowed (and both must be
                supported by any GCS that implements the Camera Protocol). The
                definition file may be xz compressed, which will be indicated by
                the file extension .xml.xz (a GCS that implements the protocol
                must support decompressing the file). The string needs to be
                zero terminated.*/
} CHCNAV_CAMERA_INFORMATION_STRUCT;

/**
 * @brief Camera system state.
 */
typedef struct {
  float temperature;                /*Camera temperature */
  CHCNAV_CAMERA_MODE_E camera_mode; /* Camera current work mode, */
  float zoom_level; /* Current zoom level as a percentage of the full range (0.0
                       to 100.0, NaN if not known)*/
  float focus_level; /* Current focus level as a percentage of the full range
                        (0.0 to 100.0, NaN if not known)*/
  CHCNAV_CAMERA_CAPTURE_STATE_E capturing_state; /* Camera state of capturing */
  bool is_capturing;                /* Camera is in capturing status. */
  bool is_capturing_interval_start; /* Camera is in interval capturing start
                                       status. */
  uint16_t
      image_capturing_interval_time_seconds; /* Current interval capture
                                              * countdown time, the value is
                                              * decreasing, when the value
                                              * equals to zero trigger the
                                              * interval take image, uint:s. */
  uint16_t image_capturing_interval_count; /* Current interval image count, the
                                            * value is decreasing step by one
                                            * from the setted count when
                                            * interval taking image */
  uint16_t image_capturing_history_count;  /* History interval image count*/
  bool is_recording;                       /* Camera is in recording status. */
  uint16_t video_recording_time_seconds;   /* Current recording process time,
                                              uint:s. */
  bool has_error;                          /* Camera in error status. */
} CHCNAV_CAMERA_SYSTEM_STATE_STRUCT;

/**
 * @brief Camera serial number.
 */
typedef struct {
  uint8_t serial_number[32];
} CHCNAV_CAMERA_SN_STRUCT;

/**
 * @brief Camera capability.
 */
typedef struct {
  uint8_t zoom_flag;  /*0:If not support 1：if support zoom control*/
  uint8_t focus_flag; /*0:If not support 1：if support focus */
  uint8_t ircut_flag; /*0:If not support 1：if support ircut*/
  uint8_t
      exposure_mode_flag; /*0:If not support 1：if support ircut exposure mode*/
  uint8_t iso_flag;       /*0:If not support 1：if support set iso*/
  uint8_t aperture_flag;  /*0:If not support 1：if support set aperture*/
  uint8_t shutter_flag;   /*0:If not support 1：if support set shutter*/
  uint8_t ev_flag;        /*0:If not support 1：if support set ev*/
  uint8_t meter_flag;     /*0:If not support 1：if support set metering mode*/
  uint8_t
      wb_mode_flag; /*0:If not support 1：if support set white balance mode*/
  uint8_t antiflicker_flag;  /*0:If not support 1：if support antiflicker*/
  uint8_t brightness_flag;   /*0:If not support 1：if support set brightness*/
  uint8_t saturation_flag;   /*0:If not support 1：if support set saturation*/
  uint8_t contrast_flag;     /*0:If not support 1：if support set contrast*/
  uint8_t sharpness_flag;    /*0:If not support 1：if support set sharpness*/
  uint8_t color_mode_flag;   /*0:If not support 1：if support set color mode*/
  uint8_t video_encode_flag; /*0:If not support 1：if support set video encode*/
  uint8_t video_format_flag; /*0:If not support 1：if support set save video
                                format*/
  uint8_t
      video_media_flag; /*0:If not support 1：if support set media parameter*/
  uint8_t photo_format_flag; /*0:if not support 1：if support set save photo
                                format*/
  uint8_t photo_ratio_flag;  /*0:If not support 1：if support set photo ratio*/
  uint8_t
      photo_quality_flag; /*0:If not support 1：if support set photo quality*/
  uint8_t battery_flag;   /*0:If not support 1：if support battery powered*/
} CHCNAV_CAMERA_CAP_STRUCT;

/**
 * @brief Camera media config.
 */
typedef struct {
  uint32_t width;     /*Horizontal image resolution*/
  uint32_t height;    /*Vertical image resolution*/
  uint16_t framerate; /*framerate*/
  uint32_t bitrate;   /*bitrate,unit：Kbps*/
} CHCNAV_CAMERA_CONFIG_STRUCT;

/**
 * @brief Camera video stream information.
 */
typedef struct {
 uint16_t framerate; /*< [Hz] Frame rate.*/
 uint32_t bitrate; /*< [bits/s] Bit rate.*/
 uint16_t flags; /*<  Bitmap of stream status flags. CHCNAV_CAMERA_VIDEO_STREAM_STATUS_FLAGS_E*/
 uint16_t resolution_h; /*< [pix] Horizontal resolution.*/
 uint16_t resolution_v; /*< [pix] Vertical resolution.*/
 uint16_t rotation; /*< [deg] Video image rotation clockwise.*/
 uint16_t hfov; /*< [deg] Horizontal Field of view.*/
 uint8_t stream_id; /*<  Video Stream ID (1 for first, 2 for second, etc.)*/
 uint8_t count; /*<  Number of streams available.*/
 uint8_t type; /*<  Type of stream. CHCNAV_CAMERA_VIDEO_STREAM_TYPE_E*/
 char name[32]; /*<  Stream name.*/
 char uri[160]; /*<  Video stream URI (TCP or RTSP URI ground station should connect to) or port number (UDP port ground station should listen to).*/
} CHCNAV_CAMERA_VIDEO_STREAM_INFORMATION_STRUCT;

/**
 * @brief Camera common handler.
 * @warning Can not execute blocking functions in Callback function, because
 * that will block chcnav root thread
 */
typedef struct {

  /**
   * @brief Callback function used to get camera information.
   * @param camera_information: Camera system information.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_camera_information)(
      CHCNAV_CAMERA_INFORMATION_STRUCT *camera_information);

  /**
   * @brief Callback function used to get camera system state.
   * @param system_state: Camera system state.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_camera_state)(
      CHCNAV_CAMERA_SYSTEM_STATE_STRUCT *system_state);

  /**
   * @brief Callback function used to get camera serial number.
   * @param camera_sn: Camera serial number.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_camera_sn)(CHCNAV_CAMERA_SN_STRUCT *camera_sn);

  /**
   * @brief Callback function used to get camera capability.
   * @param camera_cap: Camera capability.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_camera_capability)(
      CHCNAV_CAMERA_CAP_STRUCT *camera_cap);

  /**
   * @brief Callback function used to set camera work mode.
   * @param mode: Camera work mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_camera_mode)(CHCNAV_CAMERA_MODE_E mode);

  /**
   * @brief Callback function used to get camera current work mode.
   * @param mode: Camera work mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_camera_mode)(CHCNAV_CAMERA_MODE_E *mode);

  /**
   * @brief Callback function used to start capture image.
   * @return Execution result.
   */
  chcnav_return_code_t (*start_capture_image)(void);

  /**
   * @brief  Callback function used to stop capture image.
   * @return Execution result.
   */
  chcnav_return_code_t (*stop_capture_image)(void);

  /**
   * @brief  Callback function used to set camera capture image mode.
   * @param mode: Camera capture image mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_capture_image_mode)(
      CHCNAV_CAMERA_CAPTURE_MODE_E mode);

  /**
   * @brief  Callback function used to get camera current capture image mode.
   * @param mode: camera capture image mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_capture_image_mode)(
      CHCNAV_CAMERA_CAPTURE_MODE_E *mode);

  /**
   * @brief  Callback function used to set camera capture time interval
   * settings.
   * @note The value range of interval imagegraph count is [2, 255].
   * @param settings: camera capture time interval settings.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_image_time_interval_settings)(
      CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT settings);

  /**
   * @brief  Callback function used to get camera capture time interval
   * settings.
   * @param settings: camera capture time interval settings.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_image_time_interval_settings)(
      CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT *settings);

  /**
   * @brief Callback function used to get camera video stream information.
   * @param stream_id camera video stream id
   * @param video_stream_info: camera video stream information.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_video_stream_information)(uint8_t stream_id,CHCNAV_CAMERA_VIDEO_STREAM_INFORMATION_STRUCT *video_stream_info);

  /**
   * @brief Callback function used to start record video.
   * @return Execution result.
   */
  chcnav_return_code_t (*start_record_video)(void);

  /**
   * @brief Callback function used to stop record video.
   * @return Execution result.
   */
  chcnav_return_code_t (*stop_record_video)(void);

  /**
   * @brief  Callback function used to get camera current sd card state.
   * @param storage_id: Storage id (1 for first, 2 for second, etc.)
   * @param sd_card_state: camera sd card state.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_sd_card_state)(
      uint8_t storage_id, CHCNAV_CAMERA_SDCARD_STATE_STRUCT *sd_card_state);

  /**
   * @brief  Callback function used to format the sd card inserted.
   * @param storage_id: Storage id (1 for first, 2 for second, etc.)
   * @return Execution result.
   */
  chcnav_return_code_t (*format_sd_card)(uint8_t storage_id);

  /**
   * @brief  Reset camera settings.
   * @return Execution result.
   */
  chcnav_return_code_t (*reset_system_settings)(void);
} CHCNAV_CAMERA_COMMON_HANDLER_STRUCT;

/**
 * @brief Camera set and get parameter handler.
 * @warning Can not execute blocking functions in callback function, because
 * that will block chcnav root thread
 */
typedef struct {
  /**
   * @brief Used to set camera focus mode.
   * @param mode: Camera focus mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_focus_mode)(CHCNAV_CAMERA_FOCUS_MODE_E mode);

  /**
   * @brief Used to get camera current focus mode.
   * @param mode: Pointer used to store camera focus mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_focus_mode)(CHCNAV_CAMERA_FOCUS_MODE_E *mode);

  /**
   * @brief Used to set camera zoom mode.
   * @param mode: Camera zoom mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_zoom_mode)(CHCNAV_CAMERA_ZOOM_MODE_E mode);

  /**
   * @brief Used to get camera zoom mode.
   * @param mode: Camera zoom mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_zoom_mode)(CHCNAV_CAMERA_ZOOM_MODE_E *mode);

  /**
   * @brief Used to set camera exposure mode.
   * @param mode: Camera exposure mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_exposure_mode)(CHCNAV_CAMERA_EXPOSURE_MODE_E mode);

  /**
   * @brief Used to get camera exposure mode.
   * @param mode: Camera exposure mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_exposure_mode)(
      CHCNAV_CAMERA_EXPOSURE_MODE_E *mode);

  /**
   * @brief Used to get camera shutter speed.
   * @param value: Camera shutter speed.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_shutter_speed)(uint32_t *value);

  /**
   * @brief Used to get camera aperture.
   * @param value: Camera aperture.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_aperture)(float *value);

  /**
   * @brief Used to get camera iso.
   * @param value: Camera iso.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_iso)(uint32_t *value);

  /**
   * @brief Used to get camera ev.
   * @param value: Camera ev.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_ev)(float *value);

  /**
   * @brief Used to set camera metering mode.
   * @param mode: Camera metering mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_metering_mode)(CHCNAV_CAMERA_METERING_MODE_E mode);

  /**
   * @brief Used to get camera current metering mode.
   * @param mode: Pointer used to store camera metering mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_metering_mode)(
      CHCNAV_CAMERA_METERING_MODE_E *mode);

  /**
   * @brief Used to get camera current spot metering range.
   * @param mode: Pointer used to store camera metering range.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_spot_metering_range)(
      CHCNAV_CAMERA_SPOT_METERING_RANGE_STRUCT *range);

  /**
   * @brief Used to get camera current spot metering target.
   * @param mode: Pointer used to store camera metering target.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_spot_metering_target)(
      CHCNAV_CAMERA_SPOT_METERING_TARGET_STRUCT *target);

  /**
   * @brief Used to set camera write balance mode.
   * @param mode: Camera write balance mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_white_balance_mode)(
      CHCNAV_CAMERA_WHITE_BALANCE_MODE_E mode);

  /**
   * @brief Used to get camera write balance mode.
   * @param mode: Camera write balance mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_white_balance_mode)(
      CHCNAV_CAMERA_WHITE_BALANCE_MODE_E *mode);

  /**
   * @brief Used to set camera brightness.
   * @param value: Camera brightness value, 0-100.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_brightness)(uint8_t value);

  /**
   * @brief Used to get camera brightness.
   * @param value: Camera brightness value, 0-100.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_brightness)(uint8_t *value);

  /**
   * @brief Used to set camera saturation.
   * @param value: Camera saturation value, 0-100.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_saturation)(uint8_t value);

  /**
   * @brief Used to get camera saturation.
   * @param value: Camera saturation value, 0-100.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_saturation)(uint8_t *value);

  /**
   * @brief Used to set camera contrast.
   * @param value: Camera contrast value, 0-100.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_contrast)(uint8_t value);

  /**
   * @brief Used to get camera contrast.
   * @param value: Camera contrast value, 0-100.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_contrast)(uint8_t *value);

  /**
   * @brief Used to set camera sharpness.
   * @param value: Camera sharpness value, 0-100.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_sharpness)(uint8_t value);

  /**
   * @brief Used to get camera sharpness.
   * @param value: Camera sharpness value, 0-100.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_sharpness)(uint8_t *value);

  /**
   * @brief Used to set camera color mode.
   * @param value: Camera color mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_color_mode)(CHCNAV_CAMERA_COLOR_MODE_E mode);

  /**
   * @brief Used to get camera color mode.
   * @param value: Camera color mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_color_mode)(CHCNAV_CAMERA_COLOR_MODE_E *mode);

  /**
   * @brief Used to get camera capture interval.
   * @param value: Camera capture interval, unit:ms.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_capture_interval)(uint32_t *value);

  /**
   * @brief Used to set camera picture format.
   * @param format: Picture format.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_picture_format)(
      CHCNAV_CAMERA_PICTURE_FORMAT_E format);

  /**
   * @brief Used to get camera picture format.
   * @param format: Picture format.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_picture_format)(
      CHCNAV_CAMERA_PICTURE_FORMAT_E *format);

  /**
   * @brief Used to set camera picture quality.
   * @param value: Picture quality.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_picture_quality)(
      CHCNAV_CAMERA_PICTURE_QUALITY_E value);

  /**
   * @brief Used to get camera picture quality.
   * @param value: Picture quality.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_picture_quality)(
      CHCNAV_CAMERA_PICTURE_QUALITY_E *value);

  /**
   * @brief Used to set camera video encode format.
   * @param value: Video encode format.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_video_encode_format)(
      CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_E value);

  /**
   * @brief Used to get camera video encode format.
   * @param value: Video encode format.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_video_encode_format)(
      CHCNAV_CAMERA_VIDEO_ENCODE_FORMAT_E *value);

  /**
   * @brief Used to set camera video record format.
   * @param value: Video record format.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_video_record_format)(
      CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_E value);

  /**
   * @brief Used to get camera video record format.
   * @param value: Video record format.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_video_record_format)(
      CHCNAV_CAMERA_VIDEO_RECORD_FORMAT_E *value);

  /**
   * @brief Used to set camera media config.
   * @param value: Media config struct.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_media_config)(CHCNAV_CAMERA_CONFIG_STRUCT config);

  /**
   * @brief Used to get camera media config.
   * @param value: Media config struct.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_media_config)(CHCNAV_CAMERA_CONFIG_STRUCT *config);


  /**
   * @brief Used to set digicam config.
   * @param exposure_mode: Exposure modes: P, TV, AV, M, Etc.
   * @param shutter_speed: Shutter speed: Divisor number for one second.
   * @param aperture:Aperture: F stop number.
   * @param iso:ISO number e.g. 80, 100, 200, Etc.
   * @param exposure_compensation_value:Exposure compensation value
   * @return Execution result.
   */
  chcnav_return_code_t (*set_digicam_config)(CHCNAV_CAMERA_EXPOSURE_MODE_E exposure_mode,uint32_t shutter_speed,float aperture,uint32_t iso,float exposure_compensation_value);

  /**
   * @brief Used to Set camera source. Changes the camera's active sources on cameras with multiple image sensors.
   * @param device_id: 1-6 for cameras, 0 for all cameras.
   * @param primary_source: Primary Source.
   * @param second_source: Secondary Source. If non-zero the second source will be displayed as picture-in-picture.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_camera_source)(uint8_t device_id,CHCNAV_CAMERA_SOURCE_E primary_source,CHCNAV_CAMERA_SOURCE_E second_source);

  /**
   * @brief Used to initiate the camera tracking.
   * @param x: Point to track x value (normalized 0..1, 0 is left, 1 is right).
   * @param y: Point to track y value (normalized 0..1, 0 is top, 1 is bottom).
   * @param radius: Point radius (normalized 0..1, 0 is one pixel, 1 is full image width).
   * @param device_id: 1 to 6 for cameras,0: all cameras
   * @return Execution result.
   */
  chcnav_return_code_t (*set_camera_track_point)(float x,float y,float radius,uint8_t device_id);

  /**
   * @brief Used to set camer ir mode.
   * @param mode: Camera ir mode,defined in enum CHCNAV_CAMERA_IR_MODE_E
   * @return Execution result.
   */
  chcnav_return_code_t (*set_camera_ir_mode) (CHCNAV_CAMERA_IR_MODE_E mode);
  /**
   * @brief Used to get camer ir mode.
   * @param mode: Camera ir mode,defined in enum CHCNAV_CAMERA_IR_MODE_E
   * @return Execution result.
   */
  chcnav_return_code_t (*get_camera_ir_mode) (CHCNAV_CAMERA_IR_MODE_E *mode);
  /**
   * @brief Used to set stream osd mode.
   * @param mode: Stream osd mode,defined in enum CHCNAV_STREAM_OSD_MODE_E
   * @return Execution result.
   */
  chcnav_return_code_t (*set_stream_osd) (CHCNAV_STREAM_OSD_MODE_E mode);
  /**
   * @brief Used to get stream osd mode.
   * @param mode: Stream osd mode,defined in enum CHCNAV_STREAM_OSD_MODE_E
   * @return Execution result.
   */
  chcnav_return_code_t (*get_stream_osd) (CHCNAV_STREAM_OSD_MODE_E *mode);
} CHCNAV_CAMERA_PARAMETER_HANDLER_STRUCT;

/**
 * @brief Initialize the payload camera module.
 * @note The interface is the total initialization interface of the camera
 * module.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_payload_camera_init();

/**
 * @brief Register the handler for payload camera common function interfaces.
 * @note Registration of this interface needs to be after
 * chcnav_payload_camera_init.
 * @param camera_common_handler: Pointer to the handler for payload camera
 * common functions.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_payload_camera_register_common_handler(
    const CHCNAV_CAMERA_COMMON_HANDLER_STRUCT *camera_common_handler);

/**
 * @brief Register the handler for payload camera set and get parameter function
 * interfaces.
 * @note Registration of this interface needs to be after
 * chcnav_payload_camera_init.
 * @param camera_parameter_handler: Pointer to the handler for payload camera
 * parameter functions.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_payload_camera_register_parameter_handler(
    const CHCNAV_CAMERA_PARAMETER_HANDLER_STRUCT *camera_parameter_handler);

/**
 * @brief Used to get camera video stream network address.
 * @param ip_addr: Video stream network ip address.
 * @param ip_addr_len: The length of video stream network ip address.
 * @param port: Video stream network port
 * @return Execution result.
 */
chcnav_return_code_t chcnav_payload_camera_get_video_stream_network_address(
    char *ip_addr, int ip_addr_len, uint16_t *port);


/**
 * @brief DeInitialize the payload camera module.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_payload_camera_deinit();

#ifdef __cplusplus
}
#endif

#endif