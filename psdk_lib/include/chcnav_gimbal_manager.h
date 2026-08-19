/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file chcnav_gimbal_manager.h
 * @brief This is the header file for "chcnav_gimbal_manager.cpp",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/
#ifndef CHCNAV_GIMBAL_MANAGER_H
#define CHCNAV_GIMBAL_MANAGER_H
#include "chcnav_gimbal.h"
#include "chcnav_typedef.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Gimbal manager rotation command property.
 */
typedef struct {
    chcnav_f32_t pitch; /* Pitch angle in degree, unit: degree */
    chcnav_f32_t roll; /* Roll angle in degree, unit: degree */
    chcnav_f32_t yaw; /* Yaw angle in degree, unit: degree */
} CHCNAV_GIMBAL_MANAGER_ROTATION_STRUCT;

/**
 * @brief Initialize the gimbal manager module.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_gimbal_manager_init(void);

/**
 * @brief Deinitialize the gimbal manager module.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_gimbal_manager_deinit(void);

/**
 * @brief Set the work mode of the gimbal.
 * @param position: gimbal mount position, input limit see enum CHCNAV_MOUNT_POSITION_E
 * @param mode: gimbal work mode, input limit see enum CHCNAV_GIMBAL_MODE_E
 * @return Execution result.
 */
chcnav_return_code_t chcnav_gimbal_manager_set_mode(CHCNAV_MOUNT_POSITION_E position, CHCNAV_GIMBAL_MODE_E mode);

/**
 * @brief Reset  gimbal attitude.
 * @param mountPosition: gimbal mount position, input limit see enum CHCNAV_MOUNT_POSITION_E
 * @param mode: reset mode, input limit see enum CHCNAV_GIMBAL_RESET_MODE_E
 * @return Execution result.
 */
chcnav_return_code_t chcnav_gimbal_manager_reset(CHCNAV_MOUNT_POSITION_E position, CHCNAV_GIMBAL_RESET_MODE_E reset_mode);

/**
 * @brief Rotate the angle of the gimbal.
 * @param mountPosition: gimbal mount position, input limit see enum CHCNAV_MOUNT_POSITION_E
 * @param rotation: the rotation parameters to be executed on the target gimbal, refer to CHCNAV_GIMBAL_MANAGER_ROTATION_STRUCT
 * @return Execution result.
 */
chcnav_return_code_t chcnav_gimbal_manager_rorate(CHCNAV_MOUNT_POSITION_E position, CHCNAV_GIMBAL_MANAGER_ROTATION_STRUCT rotation);

/**
 * @brief Restore factory settings of gimbal, including fine tune angle, pitch angle extension enable flag and max
 * speed etc.
 * @param mountPosition: gimbal mount position, input limit see enum CHCNAV_MOUNT_POSITION_E
 * @return Execution result.
 */
chcnav_return_code_t chcnav_gimbal_manager_restore_factory_settings(CHCNAV_MOUNT_POSITION_E position);
#ifdef __cplusplus
}
#endif
#endif