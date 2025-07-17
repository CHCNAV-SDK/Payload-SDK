/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file chcnav_gimbal.h
 * @brief This is the header file for "chcnav_gimbal.cpp",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/
#ifndef CHCNAV_GIMBAL_H
#define CHCNAV_GIMBAL_H

#include "chcnav_typedef.h"

#ifdef __cplusplus
extern "C" {
#endif
typedef enum
{
   CHCNAV_GIMBAL_NO_ERROR = 0, /* Gimbal No failure*/
   CHCNAV_GIMBAL_ERROR_FLAGS_AT_ROLL_LIMIT=1, /* Gimbal is limited by hardware roll limit. */
   CHCNAV_GIMBAL_ERROR_FLAGS_AT_PITCH_LIMIT=2, /* Gimbal is limited by hardware pitch limit. */
   CHCNAV_GIMBAL_ERROR_FLAGS_AT_YAW_LIMIT=4, /* Gimbal is limited by hardware yaw limit. */
   CHCNAV_GIMBAL_ERROR_FLAGS_ENCODER_ERROR=8, /* There is an error with the gimbal encoders. */
   CHCNAV_GIMBAL_ERROR_FLAGS_POWER_ERROR=16, /* There is an error with the gimbal power source. */
   CHCNAV_GIMBAL_ERROR_FLAGS_MOTOR_ERROR=32, /* There is an error with the gimbal motors. */
   CHCNAV_GIMBAL_ERROR_FLAGS_SOFTWARE_ERROR=64, /* There is an error with the gimbal's software. */
   CHCNAV_GIMBAL_ERROR_FLAGS_COMMS_ERROR=128, /* There is an error with the gimbal's communication. */
   CHCNAV_GIMBAL_ERROR_FLAGS_CALIBRATION_RUNNING=256, /* Gimbal is currently calibrating. */
   CHCNAV_GIMBAL_ERROR_FLAGS_NO_MANAGER=512, /* Gimbal is not assigned to a gimbal manager. */
   CHCNAV_GIMBAL_ERROR_FLAGS_ENUM_END=513, /*  */
} CHCNAV_GIMBAL_ERROR_FLAGS_E;

typedef enum
{
  CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_DISABLE = 0,  /* Disable gimbal attitude compensation. */
  CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_ANGLE = 1,    /* Angle compensation for gimbal attitude. */
  CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_VELOCITY = 2, /* Angle velocity compensation for gimbal attitude. */
  CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_ANGLE_AND_VELOCITY = 3, /* Simultaneously perform angle and angular velocity compensation. */
} CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_E;

typedef struct {
  uint64_t uid;              /*  UID of gimbal hardware (0 if unknown).*/
  uint32_t time_boot_ms;     /* [ms] Timestamp (time since system boot).*/
  uint32_t firmware_version; /*  Version of the gimbal firmware, encoded as:
                                (Dev & 0xff) << 24 | (Patch & 0xff) << 16 |
                                (Minor & 0xff) << 8 | (Major & 0xff).*/
  uint32_t hardware_version; /*  Version of the gimbal hardware, encoded as:
                                (Dev & 0xff) << 24 | (Patch & 0xff) << 16 |
                                (Minor & 0xff) << 8 | (Major & 0xff).*/
  float
      roll_min; /* [rad] Minimum hardware roll angle (positive: rolling to the
                   right, negative: rolling to the left). NAN if unknown.*/
  float
      roll_max; /* [rad] Maximum hardware roll angle (positive: rolling to the
                   right, negative: rolling to the left). NAN if unknown.*/
  float pitch_min; /* [rad] Minimum hardware pitch angle (positive: up,
                      negative: down). NAN if unknown.*/
  float pitch_max; /* [rad] Maximum hardware pitch angle (positive: up,
                      negative: down). NAN if unknown.*/
  float yaw_min;   /* [rad] Minimum hardware yaw angle (positive: to the right,
                      negative: to the left). NAN if unknown.*/
  float yaw_max;   /* [rad] Maximum hardware yaw angle (positive: to the right,
                      negative: to the left). NAN if unknown.*/
  uint16_t cap_flags;        /*  Bitmap of gimbal capability flags.*/
  uint16_t custom_cap_flags; /*  Bitmap for use for gimbal-specific capability
                                flags.*/
  char vendor_name[32];      /*  Name of the gimbal vendor.*/
  char model_name[32];       /*  Name of the gimbal model.*/
  char
      custom_name[32]; /*  Custom name of the gimbal given to it by the user.*/
} CHCNAV_GIMBAL_INFORMATION_STRUCT;

typedef struct {
  uint32_t time_boot_ms; /* [ms] Timestamp (time since system boot).*/
  float q[4];            /*  Quaternion components, w, x, y, z (1 0 0 0 is the
                            null-rotation). The frame is described in the message
                            description.*/
  float
      angular_velocity_x; /* [rad/s] X component of angular velocity (positive:
                             rolling to the right). The frame is described in
                             the message description. NaN if unknown.*/
  float angular_velocity_y; /* [rad/s] Y component of angular velocity
                               (positive: pitching up). The frame is described
                               in the message description. NaN if unknown.*/
  float
      angular_velocity_z; /* [rad/s] Z component of angular velocity (positive:
                             yawing to the right). The frame is described in the
                             message description. NaN if unknown.*/
  uint32_t failure_flags; /*  Failure flags (define in CHCNAV_GIMBAL_ERROR_FLAGS_E)*/
  float delta_yaw; /* [rad] Yaw angle relating the quaternions in earth and
                      body frames (see message description). NaN if unknown.*/
  float delta_yaw_velocity; /* [rad/s] Yaw angular velocity relating the
                               angular velocities in earth and body frames (see
                               message description). NaN if unknown.*/
} CHCNAV_GIMBAL_ATTITUDE_STATUS_STRUCT;

typedef struct {
  float q[4]; /*  Quaternion components, w, x, y, z (1 0 0 0 is the
                 null-rotation). The frame is described in the message
                 description. Set fields to NaN to be ignored.*/
  float
      angular_velocity_x; /* [rad/s] X component of angular velocity (positive:
                             rolling to the right). The frame is described in
                             the message description. NaN to be ignored.*/
  float angular_velocity_y; /* [rad/s] Y component of angular velocity
                               (positive: pitching up). The frame is described
                               in the message description. NaN to be ignored.*/
  float
      angular_velocity_z; /* [rad/s] Z component of angular velocity (positive:
                             yawing to the right). The frame is described in the
                             message description. NaN to be ignored.*/
  uint16_t flags;         /*  Low level gimbal flags.*/
} CHCNAV_GIMBAL_SET_ATTITUDE_STRUCT;

typedef enum {
  /* Reset yaw axis of gimbal. */
  CHCNAV_GIMBAL_RESET_MODE_YAW = 1,
  /* Reset yaw axis and pitch axis of gimbal. */
  CHCNAV_GIMBAL_RESET_MODE_PITCH_AND_YAW = 3,
  /* Reset yaw axis and pitch axis of gimbal. */
  CHCNAV_GIMBAL_RESET_MODE_PITCH_DOWNWARD_UPWARD_AND_YAW = 11,
  /* Reset pitch axis of gimbal. */
  CHCNAV_GIMBAL_RESET_MODE_PITCH_DOWNWARD_UPWARD = 12,
} CHCNAV_GIMBAL_RESET_MODE_E;

typedef struct {

  /**
   * @brief Callback function used to get gimbal information.
   * @param gimbal_information: Gimbal system information.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_gimbal_information)(
      CHCNAV_GIMBAL_INFORMATION_STRUCT *gimbal_information);

  /**
   * @brief Callback function used to get gimbal system state.
   * @param system_state: Gimbal system state.
   * @note Reporting the status of a gimbal device. This message should be
   * broadcasted by a gimbal device component.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_gimbal_attitude_state)(
      CHCNAV_GIMBAL_ATTITUDE_STATUS_STRUCT *system_state);

  /**
   * @brief Callback function used to set gimbal attitude.
   * @param attitude: Gimbal attitude.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_gimbal_attitude)(
      CHCNAV_GIMBAL_SET_ATTITUDE_STRUCT *attitude);

  /**
   * @brief Callback function used to set camera work mode.
   * @param mode: Camera work mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_gimbal_mode)(CHCNAV_GIMBAL_MODE_E mode);

  /**
   * @brief Callback function used to get gimbal current work mode.
   * @param mode: Camera work mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_gimbal_mode)(CHCNAV_GIMBAL_MODE_E *mode);

  /**
   * @brief Callback function used to reset gimbal.
   * @param mode: Reset mode.
   * @return Execution result.
   */
  chcnav_return_code_t (*reset_mode)(CHCNAV_GIMBAL_RESET_MODE_E mode);

  /**
   * @brief  Reset gimbal settings.
   * @return Execution result.
   */
  chcnav_return_code_t (*reset_factory_settings)(void);

  /**
   * @brief  Set gimbal attitude compansation.
   * @return Execution result.
   */
  chcnav_return_code_t (*set_gimbal_attitude_compansation_mode)(CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_E mode);

  /**
   * @brief  Get gimbal attitude compansation.
   * @return Execution result.
   */
  chcnav_return_code_t (*get_gimbal_attitude_compansation_mode)(CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_E *mode);
} CHCNAV_GIMBAL_COMMON_HANDLER_STRUCT;

/**
 * @brief Initialize the gimbal module.
 * @note The interface is the total initialization interface of the gimbal
 * module.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_gimbal_init();

/**
 * @brief Deinitialise gimbal module.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_gimbal_deinit();

/**
 * @brief Register common handler of gimbal
 * @param common_handler: pointer to common handler functions of gimbal.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_gimbal_register_common_handler(
    const CHCNAV_GIMBAL_COMMON_HANDLER_STRUCT *common_handler);

#ifdef __cplusplus
}
#endif

#endif