/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file chcnav_typedef.h
 * @brief This is the header file for "chcnav_typedef.cpp",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/

#ifndef CHCNAV_TYPEDEF_H
#define CHCNAV_TYPEDEF_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CHCNAV_PI (3.14159265358979323846f)
#define CHCNAV_FILE_NAME_SIZE_MAX 256
#define CHCNAV_FILE_PATH_SIZE_MAX (CHCNAV_FILE_NAME_SIZE_MAX + 256)
#define CHCNAV_IP_ADDR_STRING_SIZE_MAX 15
#define CHCNAV_MD5_BUFFER_LEN_SIZE 16

#define CHCNAV_TRUE 1
#define CHCNAV_FALSE 0

#define CHCNAV_RESULT_FAITURE (-1)
#define CHCNAV_RESULT_SUCCESS 0

/**
 * @brief Type define double as chcnav_f64_t.
 */
typedef double chcnav_f64_t;
/**
 * @brief Type define float as chcnav_f32_t.
 */
typedef float chcnav_f32_t;
/**
 * @brief Type define uint8_t as chcnav_u8_t.
 */
typedef uint8_t chcnav_u8_t;
/**
 * @brief Type define uint16_t as chcnav_u16_t.
 */
typedef uint16_t chcnav_u16_t;
/**
 * @brief Type define uint64 as chcnav_return_code_t.
 * @details The type can be any value of chcnav_error_code.
 */
typedef int32_t chcnav_return_code_t;

typedef enum {
  CHCNAV_MOUNT_POSITION_TYPE_UNKNOWN = 0,
  CHCNAV_MOUNT_POSITION_TYPE_PAYLOAD_PORT = 1,
  CHCNAV_MOUNT_POSITION_TYPE_EXTENSION_PORT = 2,
  CHCNAV_MOUNT_POSITION_TYPE_EXTENSION_LITE_PORT = 3
} CHCNAV_MOUNT_POSITION_TYPE_E;

typedef enum {
  CHCNAV_MOUNT_POSITION_UNKNOWN = 0,
  CHCNAV_MOUNT_POSITION_PAYLOAD_PORT_NO1 = 1,
  CHCNAV_MOUNT_POSITION_PAYLOAD_PORT_NO2 = 2,
  CHCNAV_MOUNT_POSITION_PAYLOAD_PORT_NO3 = 3,
  CHCNAV_MOUNT_POSITION_EXTENSION_PORT = 4,
  CHCNAV_MOUNT_POSITION_EXTENSION_LITE_PORT = 5
} CHCNAV_MOUNT_POSITION_E;

typedef enum {
  CHCNAV_UAV_SERIES_UNKNOWN = 0,
  CHCNAV_UAV_SERIES_X500 = 1,
  CHCNAV_UAV_SERIES_P60 = 2,
  CHCNAV_UAV_SERIES_P330PRO = 3,
  CHCNAV_UAV_SERIES_BB4 = 4
} CHCNAV_UAV_SERIES_E;

typedef enum {
  CHCNAV_CAMERA_UNKNOWN = 0, /* Camera is unknown. */
  CHCNAV_CAMERA_C5 = 1,      /* Camera is C5. */
  CHCNAV_CAMERA_C30 = 2,     /* Camera is C30. */
  CHCNAV_CAMERA_R10PS = 3,     /* Camera is R10pros. */
  CHCNAV_CAMERA_PSDK = 30    /* Camera type is third party camera based on Payload SDK. */
} CHCNAV_CAMERA_E;

typedef enum {
  CHCNAV_DOWNLOAD_FILE_TYPE_ORG = 0, /* Media sub file origin data type. */
  CHCNAV_DOWNLOAD_FILE_TYPE_IMU = 27 /* Media sub file IMU data type.  */
} CHCNAV_DOWNLOAD_FILE_SUB_TYPE_E;

typedef enum {
  CHCNAV_CAMERA_FILE_TYPE_JPEG = 0,  /* Media file jpeg type. */
  CHCNAV_CAMERA_FILE_TYPE_MP4 = 1    /* Media file mp4 type. */
} CHCNAV_CAMERA_FILE_TYPE_E;

typedef enum {
  CHCNAV_CHANNEL_ADDRESS_UNKNOWN = 0,
  CHCNAV_CHANNEL_ADDRESS_PAYLOAD_PORT_NO1,
  CHCNAV_CHANNEL_ADDRESS_PAYLOAD_PORT_NO2,
  CHCNAV_CHANNEL_ADDRESS_PAYLOAD_PORT_NO3,
  CHCNAV_CHANNEL_ADDRESS_EXTENSION_PORT
} CHCNAV_CHANNEL_ADDRESS_E;

typedef enum {
  CHCNAV_CAMERA_ZOOM_SPEED_SLOWEST = 72, /* Slowest zoom speed. */
  CHCNAV_CAMERA_ZOOM_SPEED_SLOW = 73,    /* Slow zoom speed. */
  CHCNAV_CAMERA_ZOOM_SPEED_MODERATELY_SLOW =
      74, /* Slightly slower than normal zoom speed. */
  CHCNAV_CAMERA_ZOOM_SPEED_NORMAL = 75, /* Normal zoom speed. */
  CHCNAV_CAMERA_ZOOM_SPEED_MODERATELY_FAST =
      76, /* Slightly faster than normal zoom speed. */
  CHCNAV_CAMERA_ZOOM_SPEED_FAST = 77,   /* Fast zoom speed. */
  CHCNAV_CAMERA_ZOOM_SPEED_FASTEST = 78 /* Fastest zoom speed. */
} CHCNAV_CAMERA_ZOOM_SPEED_E;

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

typedef enum {
  CHCNAV_CAMERA_ZOOM_DIRECTION_OUT =
      0, /* Zooms out, reducing the zoom factor. */
  CHCNAV_CAMERA_ZOOM_DIRECTION_IN =
      1 /* Zooms in, increasing the zoom factor. */
} CHCNAV_CAMERA_ZOOM_DIRECTION_E;


typedef enum {
    CHCNAV_GIMBAL_MODE_LOCK                        = 0, /* Lock mode, fix gimbal attitude in the ground coordinate, ignoring movement of aircraft. */
    CHCNAV_GIMBAL_MODE_FPV                         = 1, /* FPV (First Person View) mode, only control roll and yaw angle of gimbal in the ground coordinate to follow aircraft. */
    CHCNAV_GIMBAL_MODE_YAW_FOLLOW                  = 2, /* Yaw follow mode, only control yaw angle of gimbal in the ground coordinate to follow aircraft. */
} CHCNAV_GIMBAL_MODE_E;

/**
 * @brief Subscription frequency type.
 */
typedef enum {
    CHCNAV_SUBSCRIPTION_TOPIC_1_HZ            = 1,
    CHCNAV_SUBSCRIPTION_TOPIC_10_HZ           = 10,
    CHCNAV_SUBSCRIPTION_TOPIC_50_HZ           = 50,
    CHCNAV_SUBSCRIPTION_TOPIC_100_HZ          = 100,
} CHCNAV_SUBSCRIPTION_TOPIC_FREQ_E;

typedef struct {
  chcnav_f32_t focus_x; /* Specifies the horizontal coordinate within the
                          zone. Range: 0 to 1. The point [0.0, 0.0] represents
                          the top-left corner of the screen.*/
  chcnav_f32_t
      focus_y; /* Specifies vertical zone coordinate. Range: 0 to 1. */
} CHCNAV_CAMERA_POINT_IN_SCREEN_STRUCT;

typedef struct {
  chcnav_u16_t max_focal_length;  /* The maximum focal length of the lens,
                                     unit: 0.1mm. */
  chcnav_u16_t min_focal_length;  /* The minimum focal length of the lens,
                                     unit: 0.1mm. */
  chcnav_u16_t focal_fength_step; /* The minimum interval of focal length
                                     change, unit: 0.1mm. */
} CHCNAV_CAMERA_OPTICAL_ZOOM_SPEC_STRUCT;

typedef struct {
  chcnav_u8_t capture_count; /* Specifies the total capture count of interval
                              * settings. 0: reserved, 1-254: specific number,
                              * 255: continuous capture until stopped. */
  chcnav_u16_t time_interval_seconds; /* Specifies the interval time between
                                         two captures, unit: s*/
} CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT;

/**
 * @brief Represents a vector using floating-point coordinates.
 */
typedef struct {
    chcnav_f32_t x; /*!< X-coordinate of the vector. */
    chcnav_f32_t y; /*!< Y-coordinate of the vector. */
    chcnav_f32_t z; /*!< Z-coordinate of the vector. */
} CHCNAV_VECTOR_3F_STRUCT;

/**
 * @brief Represents an attitude using floating-point values for pitch, roll, and yaw.
 */
typedef struct {
    chcnav_f32_t pitch; /* Pitch angle in degrees. */
    chcnav_f32_t roll;  /* Roll angle in degrees. */
    chcnav_f32_t yaw;   /* Yaw angle in degrees. */
} CHCNAV_ATTITUDE_STRCUT;

/**
 * @brief Represents a quaternion, when converted to a rotation matrix or Euler angles.
 */
typedef struct {
    chcnav_f32_t q0; /* Quaternion component w. */
    chcnav_f32_t q1; /* Quaternion component x. */
    chcnav_f32_t q2; /* Quaternion component y. */
    chcnav_f32_t q3; /* Quaternion component z. */
} CHCNAV_QUATERNION_STRUCT;

/**
 * @brief Timestamp data structure.
 */
typedef struct {
    uint64_t microsecond; //unit:us
} CHCNAV_TIMESTAMP_STRUCT;

/**
 * @brief Prototype of callback function used to receive data of topic.
 * @warning User can not execute blocking style operations or functions in the callback function, because that will block PSDK
 * root thread, causing problems such as slow system response, payload disconnection or infinite loop.
 * @param data: pointer to data of the topic, user need transfer type of this pointer to the corresponding data structure
 * pointer for getting every item of the topic conveniently.
 * @param dataSize: the size of memory space pointed by data argument, equal to data structure size corresponding to the topic.
 * @param timestamp: pointer to timestamp corresponding this data. Use flight controller power-on timestamp on M300 RTK.
 * Use payload local timestamp on M30/M30T.
 * @return Execution result.
 */
typedef chcnav_return_code_t (*CHCNAV_RECEIVE_DATA_OF_TOPIC_CALLBACK)(const uint8_t *data, uint16_t data_size,
                                                         const CHCNAV_TIMESTAMP_STRUCT *timestamp);
#ifdef __cplusplus
}
#endif

#endif