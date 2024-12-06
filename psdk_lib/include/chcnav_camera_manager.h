/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file chcnav_camera_manager.h
 * @brief This is the header file for "chcnav_camera_manager.cpp",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/

#ifndef CHCNAV_CAMERA_MANAGER_H
#define CHCNAV_CAMERA_MANAGER_H

#include "chcnav_typedef.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Camera work modes.
 */
typedef enum {
  /*!
   - Capture mode. Supports capturing pictures.
   */
  CHCNAV_CAMERA_MANAGER_WORK_MODE_SHOOT_PHOTO = 0,
  /*!
   - Record mode. Supports record videos.
   */
  CHCNAV_CAMERA_MANAGER_WORK_MODE_RECORD_VIDEO = 1,
  /*!
   * The camera work mode is unknown.
   */
  CHCNAV_CAMERA_MANAGER_WORK_MODE_UNKNOWN = 0xFF,
} CHCNAV_CAMETA_MANAGER_WORK_MODE_E;

/*!
 * @brief The ShootPhoto mode, set the photography method. The default value is
 * SINGLE.
 */
typedef enum {
  /*!
   - single shoot photo.
   */
  CHCNAV_CAMERA_MANAGER_SHOOT_PHOTO_MODE_SINGLE = 0x01,
  /*!
   - Sets the camera to take a picture (or multiple pictures) continuously at
     a set time interval.
   */
  CHCNAV_CAMERA_MANAGER_SHOOT_PHOTO_MODE_INTERVAL = 0x06,
  /*!
   - The shoot photo mode is unknown.
   */
  CHCNAV_CAMERA_MANAGER_SHOOT_PHOTO_MODE_UNKNOWN = 0xFF,
} CHCNAV_CAMERA_MANAGER_SHOOT_PHOTO_MODE_E;

/*!
 * @brief The exposure mode determines whether the shutter speed, aperture,
 * and ISO can be automatically or manually set, The default value is AUTO.
 */
typedef enum {
  CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_PROGRAM_AUTO = 1, /*!< Auto mode */
  CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_SHUTTER_PRIORITY =
      2, /*!< Shutter priority mode */
  CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_APERTURE_PRIORITY =
      3, /*!< Aperture priority mode */
  CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_EXPOSURE_MANUAL = 4, /*!< Manual mode */
  CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_UNKNOWN =
      0xFF /*!< The camera exposure mode is unknown. */
} CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_E;

/*!
 * @brief Camera focus mode.
 */
typedef enum {
  /*!
   - Set the camera focus mode to auto mode.
   */
  CHCNAV_CAMERA_MANAGER_FOCUS_MODE_AUTO = 1,
  /*!
   - Set the camera focus mode to Continuous AF.
   */
  CHCNAV_CAMERA_MANAGER_FOCUS_MODE_AFC = 2,
  /*!
   - The camera's focus mode is unknown.
   */
  CHCNAV_CAMERA_MANAGER_FOCUS_MODE_UNKNOWN = 0xFF,
} CHCNAV_CAMERA_MANAGER_FOCUS_MODE_E;

/*!
 * @brief Camera shutter speed values.
 */
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

/*!
 * @brief Camera ISO values.
 */
typedef enum {
  /*! The ISO value is automatically set. */
  CHCNAV_CAMERA_MANAGER_ISO_AUTO = 0x00,
  /*!  The ISO value is set to 100. */
  CHCNAV_CAMERA_MANAGER_ISO_100 = 0x03,
  /*! The ISO value is set to 200. */
  CHCNAV_CAMERA_MANAGER_ISO_200 = 0x04,
  /*! The ISO value is set to 400.*/
  CHCNAV_CAMERA_MANAGER_ISO_400 = 0x05,
  /*! The ISO value is set to 800.*/
  CHCNAV_CAMERA_MANAGER_ISO_800 = 0x06,
  /*! The ISO value is set to 1600.*/
  CHCNAV_CAMERA_MANAGER_ISO_1600 = 0x07,
  /*! The ISO value is set to 3200.*/
  CHCNAV_CAMERA_MANAGER_ISO_3200 = 0x08,
  /*! The ISO value is set to 6400.*/
  CHCNAV_CAMERA_MANAGER_ISO_6400 = 0x09,
  /*! The ISO value is set to 12800.*/
  CHCNAV_CAMERA_MANAGER_ISO_12800 = 0x0A,
  /*! The ISO value is set to 25600.*/
  CHCNAV_CAMERA_MANAGER_ISO_25600 = 0x0B,
  /*! The ISO value is determined by the camera */
  CHCNAV_CAMERA_MANAGER_ISO_FIXED = 0xFF,
} CHCNAV_CAMERA_MANAGER_ISO_E;

/*!
 * @brief Camera exposure compensation.
 */
typedef enum {
  /*! The camera's exposure compensation is -5.0ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_5_0 = 1,
  /*! The camera's exposure compensation is -4.7ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_4_7 = 2,
  /*! The camera's exposure compensation is -4.3ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_4_3 = 3,
  /*! The camera's exposure compensation is -4.0ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_4_0 = 4,
  /*! The camera's exposure compensation is -3.7ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_3_7 = 5,
  /*! The camera's exposure compensation is -3.3ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_3_3 = 6,
  /*! The camera's exposure compensation is -3.0ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_3_0 = 7,
  /*! The camera's exposure compensation is -2.7ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_2_7 = 8,
  /*! The camera's exposure compensation is -2.3ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_2_3 = 9,
  /*! The camera's exposure compensation is -2.0ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_2_0 = 10,
  /*! The camera's exposure compensation is -1.7ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_1_7 = 11,
  /*! The camera's exposure compensation is -1.3ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_1_3 = 12,
  /*! The camera's exposure compensation is -1.0ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_1_0 = 13,
  /*! The camera's exposure compensation is -0.7ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_0_7 = 14,
  /*! The camera's exposure compensation is -0.3ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_0_3 = 15,
  /*! The camera's exposure compensation is 0.0ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_N_0_0 = 16,
  /*! The camera's exposure compensation is +0.3ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_0_3 = 17,
  /*! The camera's exposure compensation is +0.7ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_0_7 = 18,
  /*! The camera's exposure compensation is +1.0ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_1_0 = 19,
  /*! The camera's exposure compensation is +1.3ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_1_3 = 20,
  /*! The camera's exposure compensation is +1.7ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_1_7 = 21,
  /*! The camera's exposure compensation is +2.0ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_2_0 = 22,
  /*! The camera's exposure compensation is +2.3ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_2_3 = 23,
  /*! The camera's exposure compensation is +2.7ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_2_7 = 24,
  /*! The camera's exposure compensation is +3.0ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_3_0 = 25,
  /*! The camera's exposure compensation is +3.3ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_3_3 = 26,
  /*! The camera's exposure compensation is +3.7ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_3_7 = 27,
  /*! The camera's exposure compensation is +4.0ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_4_0 = 28,
  /*! The camera's exposure compensation is +4.3ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_4_3 = 29,
  /*! The camera's exposure compensation is +4.7ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_4_7 = 30,
  /*! The camera's exposure compensation is +5.0ev.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_5_0 = 31,
  /*! The camera's exposure compensation is fixed by the camera.*/
  CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_FIXED = 0xFF,
} CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_E;

/*!
 * @brief Cameraaperture values.
 */
typedef enum {
  /*! The Aperture value is f/1.6.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_1_DOT_6 = 160,
  /*! The Aperture value is f/1.7.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_1_DOT_7 = 170,
  /*! The Aperture value is f/1.8.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_1_DOT_8 = 180,
  /*! The Aperture value is f/2.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_2 = 200,
  /*! The Aperture value is f/2.2.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_2_DOT_2 = 220,
  /*! The Aperture value is f/2.4.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_2_DOT_4 = 240,
  /*! The Aperture value is f/2.5.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_2_DOT_5 = 250,
  /*! The Aperture value is f/2.6.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_2_DOT_6 = 260,
  /*! The Aperture value is f/2.8.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_2_DOT_8 = 280,
  /*! The Aperture value is f/3.2.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_3_DOT_2 = 320,
  /*! The Aperture value is f/3.4.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_3_DOT_4 = 340,
  /*! The Aperture value is f/3.5.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_3_DOT_5 = 350,
  /*! The Aperture value is f/4.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_4 = 400,
  /*! The Aperture value is f/4.5.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_4_DOT_5 = 450,
  /*! The Aperture value is f/4.8.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_4_DOT_8 = 480,
  /*! The Aperture value is f/5.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_5 = 500,
  /*! The Aperture value is f/5.6.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_5_DOT_6 = 560,
  /*! The Aperture value is f/6.3.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_6_DOT_3 = 630,
  /*! The Aperture value is f/6.8.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_6_DOT_8 = 680,
  /*! The Aperture value is f/7.1.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_7_DOT_1 = 710,
  /*! The Aperture value is f/8.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_8 = 800,
  /*! The Aperture value is f/9.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_9 = 900,
  /*! The Aperture value is f/9.6.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_9_DOT_6 = 960,
  /*! The Aperture value is f/10.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_10 = 1000,
  /*! The Aperture value is f/11.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_11 = 1100,
  /*! The Aperture value is f/13.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_13 = 1300,
  /*! The Aperture value is f/14.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_14 = 1400,
  /*! The Aperture value is f/16.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_16 = 1600,
  /*! The Aperture value is f/18.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_18 = 1800,
  /*! The Aperture value is f/19.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_19 = 1900,
  /*! The Aperture value is f/20.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_20 = 2000,
  /*! The Aperture value is f/22.*/
  CHCNAV_CAMERA_MANAGER_APERTURE_F_22 = 2200,
  /*! The Aperture value is Unknown. */
  CHCNAV_CAMERA_MANAGER_APERTURE_F_UNKNOWN = 0xFFFF,
} CHCNAV_CAMERA_MANAGER_APERTURE_E;

/*!
 * @brief Camera metering mode values.
 */
typedef enum {
  /*! Set the camera metering mode to center metering.*/
  CHCNAV_CAMERA_MANAGER_METERING_MODE_CENTRAL = 0,
  /*! Set the camera metering mode to average metering.*/
  CHCNAV_CAMERA_MANAGER_METERING_MODE_AVERAGE = 1,
  /*! Set the camera metering mode to spot metering.*/
  CHCNAV_CAMERA_MANAGER_METERING_MODE_SPOT = 2,
  /*! Set the camera metering mode to Unknown.*/
  CHCNAV_CAMERA_MANAGER_METERING_MODE_UNKNOWN = 0xFF,
} CHCNAV_CAMERA_MANAGER_METERING_MODE_E;

/*!
 * @brief Get camera firmware version.
 */
typedef struct {
  uint8_t firmware_version[4];
} CHCNAV_CAMERA_MANAGER_FIRMWARE_VERSION_STRUCT;

/*!
 * @brief Get camera capture state.
 * The camera working mode must be set to
 * CHCNAV_CAMERA_MANAGER_WORK_MODE_SHOOT_PHOTO.
 */
typedef enum {
  /* Camera is not capturing photos*/
  CHCNAV_CAMERA_MANAGER_CAPTURING_STATE_IDLE = 0,

  /* Camera is capturing a single photo */
  CHCNAV_CAMERA_MANAGER_CAPTURING_STATE_SINGLE = 1,

  /* Camera is capturing multiple photos */
  CHCNAV_CAMERA_MANAGER_CAPTURING_STATE_MULTI = 2,
} CHCNAV_CAMERA_MANAGER_CAPTURING_STATE_E;

/*!
 * @brief Get camera record state.
 * The camera working mode must be set to
 * CHCNAV_CAMERA_MANAGER_WORK_MODE_RECORD_VIDEO.
 */
typedef enum {
  CHCNAV_CAMERA_MANAGER_RECORDING_STATE_IDLE = 0,
  CHCNAV_CAMERA_MANAGER_RECORDING_STATE_STARTING = 1,
  CHCNAV_CAMERA_MANAGER_RECORDING_STATE_RECORDING = 2,
  CHCNAV_CAMERA_MANAGER_RECORDING_STATE_STOPPING = 3,
} CHCNAV_CAMERA_MANAGER_RECORDING_STATE_E;

/*!
 * @brief Get camera storage device information.
 */
typedef struct {
  uint32_t total_capacity;  /* MByte */
  uint32_t remain_capacity; /* MByte */
} CHCNAV_CAMERA_MANAGER_STORAGE_INFO_STRUCT;

/**
 * @brief Initialise camera manager module, and user should call this function
 * before using camera manager features.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_init(void);

/**
 * @brief Deinitialise camera manager module.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_deinit(void);

/**
 * @brief Get camera type.
 * @param position: camera mounted position
 * @param cameraType: refer to CHCNAV_CAMERA_E.
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_get_camera_type(CHCNAV_MOUNT_POSITION_E position,
                                      CHCNAV_CAMERA_E *camera_type);

/**
 * @brief Get camera firmware version.
 * @param position: camera mounted position
 * @param firmware_version: refer to
 * CHCNAV_CAMERA_MANAGER_FIRMWARE_VERSION_STRUCT.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_get_firmware_version(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_MANAGER_FIRMWARE_VERSION_STRUCT *firmware_version);

/**
 * @brief Get camera connection status.
 * @param position: camera mounted position
 * @param connect_status: returned value of connection status
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_get_camera_connect_status(
    CHCNAV_MOUNT_POSITION_E position, bool *connect_status);

/**
 * @brief Set camera working mode.
 * @note When switching the camera working mode, if the camera is recording or
 * taking photos, you need to first stop the recording and taking business
 * before switching the working mode.
 * @param position: camera mounted position
 * @param work_mode: refer to CHCNAV_CAMETA_MANAGER_WORK_MODE_E.
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_set_mode(CHCNAV_MOUNT_POSITION_E position,
                               CHCNAV_CAMETA_MANAGER_WORK_MODE_E work_mode);

/**
 * @brief Get camera working mode.
 * @param position: camera mounted position
 * @param work_mode: refer to CHCNAV_CAMETA_MANAGER_WORK_MODE_E.
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_get_mode(CHCNAV_MOUNT_POSITION_E position,
                               CHCNAV_CAMETA_MANAGER_WORK_MODE_E *work_mode);

/**
 * @brief Set the camera shooting interval parameter.
 * @note In this mode, the camera will stop taking photos after capturing the
 * set number of shots at the set time interval photos is reached.
 * @param position: camera mounted position
 * @param interval_setting: refer to
 * CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_set_photo_time_interval_settings(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT interval_setting);

/**
 * @brief Get the camera shooting interval parameter.
 * @param position: camera mounted position
 * @param interval_setting: refer to
 * CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_get_photo_time_interval_settings(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT *interval_setting);

/**
 * @brief Start shooting photo.
 * @note Camera must be in Photo mode. Check the SD card's capacity
 * before using this method to ensure there is enough space.
 * @param position: camera mounted position
 * @param mode: refer to CHCNAV_CAMERA_MANAGER_SHOOT_PHOTO_MODE_E.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_start_shoot_photo(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_MANAGER_SHOOT_PHOTO_MODE_E mode);

/**
 * @brief Stop shooting photo.
 * @note Camera must be in Photo mode and the shoot mode is either
 * Interval or Time-lapse. If set to single shot mode, the camera will
 * automatically stop after taking the photo.
 * @param position: camera mounted position
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_stop_shoot_photo(CHCNAV_MOUNT_POSITION_E position);

/**
 * @brief Get camera capturing state.
 * @param position: camera mounted position
 * @param capturing_state: see CHCNAV_CAMERA_MANAGER_CAPTURING_STATE_E.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_get_capturing_state(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_MANAGER_CAPTURING_STATE_E *capturing_state);

/**
 * @brief Set camera focus mode.
 * @note In camera focus mode, auto mode supports single autofocus,
 * AFC mode supports continuous autofocus.
 * @param position: camera mounted position
 * @param focus_mode: refer to CHCNAV_CAMERA_MANAGER_FOCUS_MODE_E.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_set_focus_mode(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_MANAGER_FOCUS_MODE_E focus_mode);
/**
 * @brief Get camera focus mode.
 * @param position: camera mounted position
 * @param focus_mode: refer to CHCNAV_CAMERA_MANAGER_FOCUS_MODE_E.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_get_focus_mode(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_MANAGER_FOCUS_MODE_E *focus_mode);

/**
 * @brief Trigger active focusing once.
 * @note  Trigger active focusing once. Only set to auto focus mode,
 * calling this interface is effective
 * @param position: camera mounted position
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_trigger_focus(CHCNAV_MOUNT_POSITION_E position);

/**
 * @brief Start camera zoom.
 * @param position: camera mounted position
 * @param zoom_direction: zoom direction, refer to
 * CHCNAV_CAMERA_ZOOM_DIRECTION_E.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_start_continuous_zoom(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_ZOOM_DIRECTION_E zoom_direction);

/**
 * @brief Stop camera zoom.
 * @param position: camera mounted position
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_stop_continuous_zoom(CHCNAV_MOUNT_POSITION_E position);

/**
 * @brief Set camera's exposure mode.
 * @note Different exposure modes define whether settings like aperture, shutter
 * speed, and ISO are set automatically or manually. Exposure compensation is
 * adjustable in all modes except the manual mode.
 * @param position: camera mounted position
 * @param mode: refer to CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_E.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_set_exposure_mode(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_E mode);

/**
 * @brief Get camera's exposure mode.
 * @note Different exposure modes define whether settings like aperture, shutter
 * speed, and ISO are set automatically or manually. Exposure compensation is
 * adjustable in all modes except the manual mode.
 * @param position: camera mounted position
 * @param mode: refer to CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_E.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_get_exposure_mode(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_E *mode);

/**
 * @brief Set camera's iso value.
 * @note  ISO value can only be set when the camera exposure mode is in
 * manual mode.
 * @param position: camera mounted position
 * @param iso: refer to CHCNAV_CAMERA_MANAGER_ISO_E.
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_set_ISO(CHCNAV_MOUNT_POSITION_E position,
                              CHCNAV_CAMERA_MANAGER_ISO_E iso);

/**
 * @brief Get camera's iso value.
 * @param position: camera mounted position
 * @param iso: refer to CHCNAV_CAMERA_MANAGER_ISO_E.
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_get_ISO(CHCNAV_MOUNT_POSITION_E position,
                              CHCNAV_CAMERA_MANAGER_ISO_E *iso);

/**
 * @brief Set camera's aperture size value.
 * @note The exposure mode must be on
 * CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_EXPOSURE_MANUAL or
 * CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_APERTURE_PRIORITY.
 * @param position: camera mounted position
 * @param aperture: refer to CHCNAV_CAMERA_MANAGER_APERTURE_E.
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_set_aperture(CHCNAV_MOUNT_POSITION_E position,
                                   CHCNAV_CAMERA_MANAGER_APERTURE_E aperture);

/**
 * @brief Get camera's aperture size value.
 * @param position: camera mounted position
 * @param aperture: refer to CHCNAV_CAMERA_MANAGER_APERTURE_E.
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_get_aperture(CHCNAV_MOUNT_POSITION_E position,
                                   CHCNAV_CAMERA_MANAGER_APERTURE_E *aperture);

/**
 * @brief Set camera's shutter speed value.
 * @note Set the camera shutter speed. Ensure the shutter speed is not set
 * slower than the video frame rate when the camera's mode is RECORD_VIDEO.
 * For example, if the video frame rate is 30fps, the shutterSpeed must be <=
 * 1/30. Precondition: The shutter speed can be set only when the camera
 * exposure mode is CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_EXPOSURE_MANUAL mode or
 * CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_SHUTTER_PRIORITY
 * @param position: camera mounted position
 * @param shutter_speed: refer to CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_E.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_set_shutter_speed(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_E shutter_speed);

/**
 * @brief Get camera's shutter speed value.
 * @param position: camera mounted position
 * @param shutter_speed: refer to CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_E.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_get_shutter_speed(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_E *shutter_speed);

/**
 * @brief Set camera's EV value.
 * @note When the exposure mode is automatic, shutter priority, and aperture
 * priority, set the exposure compensation to be effective
 * @param position: camera mounted position
 * @param ev: refer to CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_E.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_set_exposure_compensation(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_E ev);

/**
 * @brief Get camera's EV value.
 * @param position: camera mounted position
 * @param ev: refer to CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_E.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_get_exposure_compensation(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_E *ev);

/**
 * @brief Reset camera settings.
 * @param position: camera mounted position
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_reset_camera_settings(CHCNAV_MOUNT_POSITION_E position);

/**
 * @brief Start recording.
 * @note Camera must be in RECORD_VIDEO mode.
 * @param position: camera mounted position
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_start_record_video(CHCNAV_MOUNT_POSITION_E position);

/**
 * @brief Stop recording.
 * @note Precondition: The camera is recording currently.
 * @param position: camera mounted position
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_stop_record_video(CHCNAV_MOUNT_POSITION_E position);

/**
 * @brief Get camera recording state.
 * @param position: camera mounted position
 * @param recording_state: result of getting, see
 * CHCNAV_CAMERA_MANAGER_RECORDING_STATE_E.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_get_recording_state(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_MANAGER_RECORDING_STATE_E *recording_state);

/**
 * @brief Get camera recording time.
 * @param position: camera mounted position
 * @param recording_time: result of getting, unit is seconds.
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_get_recording_time(CHCNAV_MOUNT_POSITION_E position,
                                         uint16_t *recording_time);

/**
 * @brief Format SD card.
 * @param position: the mount position of the camera
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_format_storage(CHCNAV_MOUNT_POSITION_E position);

/**
 * @brief Get storage info of SD card.
 * @param position: the mount position of the camera
 * @param storage_info: Result of SD Card storage information
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_get_storage_info(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_MANAGER_STORAGE_INFO_STRUCT *storage_info);

/**
 * @brief Set camera metering mode.
 * @param position: the mount position of the camera
 * @param metering_mode: refer to CHCNAV_CAMERA_MANAGER_METERING_MODE_E.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_set_metering_mode(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_MANAGER_METERING_MODE_E metering_mode);

/**
 * @brief Get camera metering mode.
 * @param position: the mount position of the camera
 * @param metering_mode: refer to CHCNAV_CAMERA_MANAGER_METERING_MODE_E.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_get_metering_mode(
    CHCNAV_MOUNT_POSITION_E position,
    CHCNAV_CAMERA_MANAGER_METERING_MODE_E *metering_mode);

/**
 * @brief Get the range of point metering mode settings.
 * @param position: camera mounted position
 * @param hrzNum: returned value, horizontal range.
 * @param vtcNum: returned value, vertical range.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_camera_manager_get_metering_point_region_range(
    CHCNAV_MOUNT_POSITION_E position, uint8_t *hrz_num, uint8_t *vtc_num);

/**
 * @brief Set camera metering point.
 * @param position: camera mounted position
 * @param x: Horizontal coordinate value, x <= hrz_num - 1.
 * @param y: Horizontal coordinate value, y <= vtc_num - 1.
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_set_metering_point(CHCNAV_MOUNT_POSITION_E position,
                                         uint8_t x, uint8_t y);

/**
 * @brief Get camera metering mode.
 * @param position: camera mounted position
 * @param x: Get horizontal coordinate.
 * @param y: Get vertical coordinate.
 * @return Execution result.
 */
chcnav_return_code_t
chcnav_camera_manager_get_metering_point(CHCNAV_MOUNT_POSITION_E position,
                                         uint8_t *x, uint8_t *y);

#ifdef __cplusplus
}
#endif
#endif // CHCNAV_CAMERA_MANAGER_H