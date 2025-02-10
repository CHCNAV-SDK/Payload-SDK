/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file chcnav_flight_controller.h
 * @brief This is the header file for "chcnav_flight_controller.cpp",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/
#ifndef CHCNAV_FLIGHT_CONTROLLER_H
#define CHCNAV_FLIGHT_CONTROLLER_H

#include "chcnav_typedef.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Initialize the flight controller module.
 * @note The interface is the total initialization interface of the camera
 * module.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_flight_controller_init();

/**
 * @brief Arm the aircraft.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_flight_controller_arm();

/**
 * @brief Disarm the aircraft.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_flight_controller_disarm();


/**
 * @brief Request taking off action when the aircraft is on the ground.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_flight_controller_start_take_off();

/**
 * @brief Request start waypoint action.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_flight_controller_start_waypoint();

/**
 * @brief Request pause action.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_flight_controller_pause();

/**
 * @brief Request go home action.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_flight_controller_start_go_home();

/**
 * @brief Request landing action.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_flight_controller_start_landing();

/**
 * @brief DeInitialize the flight controller module.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_flight_controller_deinit();

#ifdef __cplusplus
}
#endif

#endif