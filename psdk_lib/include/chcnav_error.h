/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file chcnav_error.h
 * @brief This is a header file that defines the types of errors in the program.
 ********************************************************************************/

#ifndef CHCNAV_ERROR_H
#define CHCNAV_ERROR_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*common error */
#define CHCNAV_RETURN_OK                       0   /*!< Payload SDK return is ok. */
#define CHCNAV_RETURN_ERR_FAILURE              -1  /*!< Payload SDK return is failure. */
#define CHCNAV_RETURN_ERR_ALLOC                -2  /*!< Payload SDK return alloc error. */
#define CHCNAV_RETURN_ERR_TIMEOUT              -3  /*!< Payload SDK return timeout error. */
#define CHCNAV_RETURN_ERR_NOT_FOUND            -4  /*!< Payload SDK return not found error. */
#define CHCNAV_RETURN_ERR_OUT_OF_RANGE         -5  /*!< Payload SDK return out of range error. */
#define CHCNAV_RETURN_ERR_PARAM                -6  /*!< Payload SDK return parameter error. */
#define CHCNAV_RETURN_ERR_SYSTEM               -7  /*!< Payload SDK return system error. */
#define CHCNAV_RETURN_ERR_BUSY                 -8  /*!< Payload SDK return busy error. */
#define CHCNAV_RETURN_ERR_UNSUPPORT            -9  /*!< Payload SDK return nonsupport error. */
#define CHCNAV_RETURN_ERR_STRING_EMPTY         -10 /*!< Payload SDK return string empty error. */
#define CHCNAV_RETURN_ERR_STRING_NOT_MATCH     -11 /*!< Payload SDK return string not match error. */
#define CHCNAV_RETURN_ERR_UNKNOWN              -12 /*!< Payload SDK return unknown error. */

/**
 * @brief chcnav module enum for defining error code.
 */
typedef enum {
    CHCNAV_SYSTEM_MODULE_ERROR = -50,
    CHCNAV_CAMERA_MANAGER_MODULE_ERROR = -100,
    CHCNAV_PAYLOAD_CAMERA_MODULE_ERROR = -200,
    CHCNAV_GIMBAL_MANAGER_MODULE_ERROR = -300,
    CHCNAV_FC_SUBSCRIPTION_MODULE_ERROR = -400,
    CHCNAV_UNKNOWN_MODULE_ERROR,
} CHCNAV_MODULE_ERROR_E;

/**
 * @brief Error code of system module.
 */
typedef enum {
    CHCNAV_SYSTEM_ERR_CODE_NOT_INIT = 1,
    CHCNAV_SYSTEM_ERR_CODE_ALLOC = 2,
    CHCNAV_SYSTEM_ERR_CODE_TIMEOUT = 3,
    CHCNAV_SYSTEM_ERR_CODE_NOT_FOUND = 4,
    CHCNAV_SYSTEM_ERR_CODE_OUT_OF_RANGGE = 5,
    CHCNAV_SYSTEM_ERR_CODE_PARAM = 6,
    CHCNAV_SYSTEM_ERR_CODE_SYSTEM = 7,
    CHCNAV_SYSTEM_ERR_CODE_BUSY = 8,
    CHCNAV_SYSTEM_ERR_CODE_UNSUPPORT = 9,
    CHCNAV_SYSTEM_ERR_CODE_UNKNOWN = 10,
    CHCNAV_SYSTEM_ERR_CODE_NONSUPPORT_IN_CURRENT_STATE = 11,
    CHCNAV_SYSTEM_ERR_CODE_HARDWARE_ERR = 12,
    CHCNAV_SYSTEM_ERR_CODE_INSUFFICIENT_ELECTRICITY = 13,
    CHCNAV_SYSTEM_ERR_CODE_DUPLICATE = 14,
} CHCNAV_SYSTEM_ERR_CODE_E;

/**
 * @brief Error code of camera manager module.
 */
typedef enum {
    CHCNAV_CAMERA_MANAGER_ERR_CODE_NOT_INIT = 1,
    CHCNAV_CAMERA_MANAGER_ERR_CODE_ALLOC = 2,
    CHCNAV_CAMERA_MANAGER_ERR_CODE_TIMEOUT = 3,
    CHCNAV_CAMERA_MANAGER_ERR_CODE_SYSTEM = 7,
    CHCNAV_CAMERA_MANAGER_ERR_CODE_UNSUPPORT = 9,
    CHCNAV_CAMERA_MANAGER_ERR_CODE_UNSUPPORTED_COMMANDIN_CUR_STATE = 10,
    CHCNAV_CAMERA_MANAGER_ERR_CODE_HARDWARE_ERROR = 11,
    CHCNAV_CAMERA_MANAGER_ERR_CODE_INVALID_COMMAND_PARAMETER = 12,
    CHCNAV_CAMERA_MANAGER_ERR_CODE_PARAMETER_SET_FAILED = 13,
    CHCNAV_CAMERA_MANAGER_ERR_CODE_PARAMETER_GET_FAILED = 14,
    CHCNAV_CAMERA_MANAGER_ERR_CODE_SD_CARD_MISSING = 15,
    CHCNAV_CAMERA_MANAGER_ERR_CODE_SD_CARD_FULL = 16,
    CHCNAV_CAMERA_MANAGER_ERR_CODE_SD_CARD_ERROR = 17,
    CHCNAV_CAMERA_MANAGER_ERR_CODE_SENSOR_ERROR = 18,
    CHCNAV_CAMERA_MANAGER_ERR_CODE_REMOTE_CONTROL_UNCONNECTED = 19,
    CHCNAV_CAMERA_MANAGER_ERR_CODE_AIRCRAFT_UNCONNECTED = 20,
    CHCNAV_CAMERA_MANAGER_ERR_CODE_UNDEFINE_ERROR = 99,
} CHCNAV_CAMERA_MANAGER_ERR_CODE_E;

/**
 * @brief Error code of payload camera module.
 */
typedef enum {
    CHCNAV_PAYLOAD_CAMERA_ERR_CODE_ALLOC = 2,
    CHCNAV_PAYLOAD_CAMERA_ERR_CODE_TIMEOUT = 3,
    CHCNAV_PAYLOAD_CAMERA_ERR_CODE_SYSTEM = 7,
    CHCNAV_PAYLOAD_CAMERA_ERR_CODE_UNSUPPORT = 9,
    CHCNAV_PAYLOAD_CAMERA_ERR_CODE_UNSUPPORTED_COMMANDIN_CUR_STATE = 10,
    CHCNAV_PAYLOAD_CAMERA_ERR_CODE_HARDWARE_ERROR = 11,
    CHCNAV_PAYLOAD_CAMERA_ERR_CODE_INVALID_COMMAND_PARAMETER = 12,
    CHCNAV_PAYLOAD_CAMERA_ERR_CODE_PARAMETER_SET_FAILED = 13,
    CHCNAV_PAYLOAD_CAMERA_ERR_CODE_PARAMETER_GET_FAILED = 14,
    CHCNAV_PAYLOAD_CAMERA_ERR_CODE_SD_CARD_MISSING = 15,
    CHCNAV_PAYLOAD_CAMERA_ERR_CODE_SD_CARD_FULL = 16,
    CHCNAV_PAYLOAD_CAMERA_ERR_CODE_SD_CARD_ERROR = 17,
    CHCNAV_PAYLOAD_CAMERA_ERR_CODE_SENSOR_ERROR = 18,
    CHCNAV_PAYLOAD_CAMERA_ERR_CODE_REMOTE_CONTROL_UNCONNECTED = 19,
    CHCNAV_PAYLOAD_CAMERA_ERR_CODE_UNDEFINE_ERROR = 99,
} CHCNAV_PAYLOAD_CAMERA_ERR_CODE_E;

/**
 * @brief Error code of gimbal manager module.
 */
typedef enum {
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_NOT_INIT = 1,
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_ALLOC = 2,
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_TIMEOUT = 3,
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_SYSTEM = 7,
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_UNSUPPORT = 9,
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_UNSUPPORTED_COMMANDIN_CUR_STATE = 10,
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_HARDWARE_ERROR = 11,
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_INVALID_COMMAND_PARAMETER = 12,
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_PARAMETER_SET_FAILED = 13,
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_PARAMETER_GET_FAILED = 14,
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_SD_CARD_MISSING = 15,
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_SD_CARD_FULL = 16,
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_SD_CARD_ERROR = 17,
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_SENSOR_ERROR = 18,
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_REMOTE_CONTROL_UNCONNECTED = 19,
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_AIRCRAFT_UNCONNECTED = 20,
    CHCNAV_GIMBAL_MANAGER_ERR_CODE_UNDEFINE_ERROR = 99,
} CHCNAV_GIMBAL_MANAGER_ERR_CODE_E;

/**
 * @brief Error code of subscription module.
 */
typedef enum {
    CHCNAV_FC_SUBSCRIPTION_ERR_CODE_NOT_INIT = 1,
    CHCNAV_FC_SUBSCRIPTION_ERR_CODE_ALLOC = 2,
    CHCNAV_FC_SUBSCRIPTION_ERR_CODE_TIMEOUT = 3,
    CHCNAV_FC_SUBSCRIPTION_ERR_CODE_PARAM = 6,
    CHCNAV_FC_SUBSCRIPTION_ERR_CODE_SYSTEM = 7,
    CHCNAV_FC_SUBSCRIPTION_ERR_CODE_MAXIMUM_LIMIT_EXCEEDED = 14,
    CHCNAV_FC_SUBSCRIPTION_ERR_CODE_INVALID_TOPIC_FREQ = 15,
    CHCNAV_FC_SUBSCRIPTION_ERR_CODE_TOPIC_DUPLICATE = 16,
    CHCNAV_FC_SUBSCRIPTION_ERR_CODE_TOPIC_NOT_SUBSCRIBED = 17,
    CHCNAV_FC_SUBSCRIPTION_ERR_CODE_TIMESTAMP_NOT_ENABLE = 18,
    CHCNAV_FC_SUBSCRIPTION_ERR_CODE_TOPIC_NOT_SUPPORTED = 19,
} CHCNAV_FC_SUBSCRIPTION_ERR_CODE_E;

typedef enum {
    /* system module error range -50 ~ -100 */
    CHCNAV_SYSTEM_ERROR_NONSUPPORT                  = CHCNAV_SYSTEM_MODULE_ERROR - CHCNAV_SYSTEM_ERR_CODE_UNSUPPORT,
    CHCNAV_SYSTEM_ERROR_TIMEOUT                     = CHCNAV_SYSTEM_MODULE_ERROR - CHCNAV_SYSTEM_ERR_CODE_TIMEOUT,
    CHCNAV_SYSTEM_ERROR_MEMORY_ALLOC_FAILED         = CHCNAV_SYSTEM_MODULE_ERROR - CHCNAV_SYSTEM_ERR_CODE_ALLOC,
    CHCNAV_SYSTEM_ERROR_INVALID_PARAMETER           = CHCNAV_SYSTEM_MODULE_ERROR - CHCNAV_SYSTEM_ERR_CODE_PARAM,
    CHCNAV_SYSTEM_ERROR_SYSTEM_ERROR                = CHCNAV_SYSTEM_MODULE_ERROR - CHCNAV_SYSTEM_ERR_CODE_SYSTEM,
    CHCNAV_SYSTEM_ERROR_UNKNOWN                     = CHCNAV_SYSTEM_MODULE_ERROR - CHCNAV_SYSTEM_ERR_CODE_UNKNOWN,
    CHCNAV_SYSTEM_ERROR_NOT_FOUND                   = CHCNAV_SYSTEM_MODULE_ERROR - CHCNAV_SYSTEM_ERR_CODE_NOT_FOUND,
    CHCNAV_SYSTEM_ERROR_OUT_OF_RANGE                = CHCNAV_SYSTEM_MODULE_ERROR - CHCNAV_SYSTEM_ERR_CODE_OUT_OF_RANGGE,
    CHCNAV_SYSTEM_ERROR_BUSY                        = CHCNAV_SYSTEM_MODULE_ERROR - CHCNAV_SYSTEM_ERR_CODE_BUSY,
    CHCNAV_SYSTEM_ERROR_NONSUPPORT_IN_CURRENT_STATE = CHCNAV_SYSTEM_MODULE_ERROR - CHCNAV_SYSTEM_ERR_CODE_NONSUPPORT_IN_CURRENT_STATE,
    CHCNAV_SYSTEM_ERROR_HARDWARE_ERR                = CHCNAV_SYSTEM_MODULE_ERROR - CHCNAV_SYSTEM_ERR_CODE_HARDWARE_ERR,
    CHCNAV_SYSTEM_ERROR_INSUFFICIENT_ELECTRICITY    = CHCNAV_SYSTEM_MODULE_ERROR - CHCNAV_SYSTEM_ERR_CODE_INSUFFICIENT_ELECTRICITY,
    CHCNAV_SYSTEM_ERROR_DUPLICATE                   = CHCNAV_SYSTEM_MODULE_ERROR - CHCNAV_SYSTEM_ERR_CODE_DUPLICATE,
    /* Camera manager errors range -101 ~ -200 */
    CHCNAV_CAMERA_MANAGER_ERROR_NOT_INIT                         = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_NOT_INIT,
    CHCNAV_CAMERA_MANAGER_ERROR_ALLOC_FAILED                     = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_ALLOC,
    CHCNAV_CAMERA_MANAGER_ERROR_TIMEOUT                          = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_TIMEOUT,
    CHCNAV_CAMERA_MANAGER_ERROR_SYSTEM_ERROR                     = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_SYSTEM,
    CHCNAV_CAMERA_MANAGER_ERROR_UNSUPPORTED_COMMAND              = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_UNSUPPORT,
    CHCNAV_CAMERA_MANAGER_ERROR_UNSUPPORTED_COMMAND_IN_CUR_STATE = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_UNSUPPORTED_COMMANDIN_CUR_STATE,
    CHCNAV_CAMERA_MANAGER_ERROR_HARDWARE_ERROR                   = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_INVALID_COMMAND_PARAMETER,
    CHCNAV_CAMERA_MANAGER_ERROR_INVALID_COMMAND_PARAMETER        = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_INVALID_COMMAND_PARAMETER,
    CHCNAV_CAMERA_MANAGER_ERROR_PARAMETER_SET_FAILED             = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_PARAMETER_SET_FAILED,
    CHCNAV_CAMERA_MANAGER_ERROR_PARAMETER_GET_FAILED             = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_PARAMETER_GET_FAILED,
    CHCNAV_CAMERA_MANAGER_ERROR_SD_CARD_MISSING                  = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_SD_CARD_MISSING,
    CHCNAV_CAMERA_MANAGER_ERROR_SD_CARD_FULL                     = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_SD_CARD_FULL,
    CHCNAV_CAMERA_MANAGER_ERROR_SD_CARD_ERROR                    = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_SD_CARD_ERROR,
    CHCNAV_CAMERA_MANAGER_ERROR_SENSOR_ERROR                     = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_SENSOR_ERROR,
    CHCNAV_CAMERA_MANAGER_ERROR_REMOTE_CONTROL_UNCONNECTED       = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_REMOTE_CONTROL_UNCONNECTED,
    CHCNAV_CAMERA_MANAGER_ERROR_AIRCRAFT_UNCONNECTED             = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_AIRCRAFT_UNCONNECTED,
    CHCNAV_CAMERA_MANAGER_ERROR_UNDEFINE_ERROR                   = CHCNAV_CAMERA_MANAGER_MODULE_ERROR - CHCNAV_CAMERA_MANAGER_ERR_CODE_UNDEFINE_ERROR,
    /* Payload camera errors range -201 ~ -300 */
    CHCNAV_PAYLOAD_CAMERA_ERROR_ALLOC_FAILED                     = CHCNAV_PAYLOAD_CAMERA_MODULE_ERROR - CHCNAV_PAYLOAD_CAMERA_ERR_CODE_ALLOC,
    CHCNAV_PAYLOAD_CAMERA_ERROR_TIMEOUT                          = CHCNAV_PAYLOAD_CAMERA_MODULE_ERROR - CHCNAV_PAYLOAD_CAMERA_ERR_CODE_TIMEOUT,
    CHCNAV_PAYLOAD_CAMERA_ERROR_SYSTEM_ERROR                     = CHCNAV_PAYLOAD_CAMERA_MODULE_ERROR - CHCNAV_PAYLOAD_CAMERA_ERR_CODE_SYSTEM,
    CHCNAV_PAYLOAD_CAMERA_ERROR_UNSUPPORTED_COMMAND              = CHCNAV_PAYLOAD_CAMERA_MODULE_ERROR - CHCNAV_PAYLOAD_CAMERA_ERR_CODE_UNSUPPORT,
    CHCNAV_PAYLOAD_CAMERA_ERROR_UNSUPPORTED_COMMAND_IN_CUR_STATE = CHCNAV_PAYLOAD_CAMERA_MODULE_ERROR - CHCNAV_PAYLOAD_CAMERA_ERR_CODE_UNSUPPORTED_COMMANDIN_CUR_STATE,
    CHCNAV_PAYLOAD_CAMERA_ERROR_HARDWARE_ERROR                   = CHCNAV_PAYLOAD_CAMERA_MODULE_ERROR - CHCNAV_PAYLOAD_CAMERA_ERR_CODE_HARDWARE_ERROR,
    CHCNAV_PAYLOAD_CAMERA_ERROR_INVALID_COMMAND_PARAMETER        = CHCNAV_PAYLOAD_CAMERA_MODULE_ERROR - CHCNAV_PAYLOAD_CAMERA_ERR_CODE_INVALID_COMMAND_PARAMETER,
    CHCNAV_PAYLOAD_CAMERA_ERROR_PARAMETER_SET_FAILED             = CHCNAV_PAYLOAD_CAMERA_MODULE_ERROR - CHCNAV_PAYLOAD_CAMERA_ERR_CODE_PARAMETER_SET_FAILED,
    CHCNAV_PAYLOAD_CAMERA_ERROR_PARAMETER_GET_FAILED             = CHCNAV_PAYLOAD_CAMERA_MODULE_ERROR - CHCNAV_PAYLOAD_CAMERA_ERR_CODE_PARAMETER_GET_FAILED,
    CHCNAV_PAYLOAD_CAMERA_ERROR_SD_CARD_MISSING                  = CHCNAV_PAYLOAD_CAMERA_MODULE_ERROR - CHCNAV_PAYLOAD_CAMERA_ERR_CODE_SD_CARD_MISSING,
    CHCNAV_PAYLOAD_CAMERA_ERROR_SD_CARD_FULL                     = CHCNAV_PAYLOAD_CAMERA_MODULE_ERROR - CHCNAV_PAYLOAD_CAMERA_ERR_CODE_SD_CARD_FULL,
    CHCNAV_PAYLOAD_CAMERA_ERROR_SD_CARD_ERROR                    = CHCNAV_PAYLOAD_CAMERA_MODULE_ERROR - CHCNAV_PAYLOAD_CAMERA_ERR_CODE_SD_CARD_ERROR,
    CHCNAV_PAYLOAD_CAMERA_ERROR_SENSOR_ERROR                     = CHCNAV_PAYLOAD_CAMERA_MODULE_ERROR - CHCNAV_PAYLOAD_CAMERA_ERR_CODE_SENSOR_ERROR,
    CHCNAV_PAYLOAD_CAMERA_ERROR_REMOTE_CONTROL_UNCONNECTED       = CHCNAV_PAYLOAD_CAMERA_MODULE_ERROR - CHCNAV_PAYLOAD_CAMERA_ERR_CODE_REMOTE_CONTROL_UNCONNECTED,
    CHCNAV_PAYLOAD_CAMERA_ERROR_UNDEFINE_ERROR                   = CHCNAV_PAYLOAD_CAMERA_MODULE_ERROR - CHCNAV_PAYLOAD_CAMERA_ERR_CODE_UNDEFINE_ERROR,
    /* Gimbal manager errors range -301 ~ -400 */
    CHCNAV_GIMBAL_MANAGER_ERROR_NOT_INIT                         = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_NOT_INIT,
    CHCNAV_GIMBAL_MANAGER_ERROR_ALLOC_FAILED                     = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_ALLOC,
    CHCNAV_GIMBAL_MANAGER_ERROR_TIMEOUT                          = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_TIMEOUT,
    CHCNAV_GIMBAL_MANAGER_ERROR_SYSTEM_ERROR                     = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_SYSTEM,
    CHCNAV_GIMBAL_MANAGER_ERROR_UNSUPPORTED_COMMAND              = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_UNSUPPORT,
    CHCNAV_GIMBAL_MANAGER_ERROR_UNSUPPORTED_COMMAND_IN_CUR_STATE = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_UNSUPPORTED_COMMANDIN_CUR_STATE,
    CHCNAV_GIMBAL_MANAGER_ERROR_HARDWARE_ERROR                   = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_INVALID_COMMAND_PARAMETER,
    CHCNAV_GIMBAL_MANAGER_ERROR_INVALID_COMMAND_PARAMETER        = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_INVALID_COMMAND_PARAMETER,
    CHCNAV_GIMBAL_MANAGER_ERROR_PARAMETER_SET_FAILED             = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_PARAMETER_SET_FAILED,
    CHCNAV_GIMBAL_MANAGER_ERROR_PARAMETER_GET_FAILED             = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_PARAMETER_GET_FAILED,
    CHCNAV_GIMBAL_MANAGER_ERROR_SD_CARD_MISSING                  = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_SD_CARD_MISSING,
    CHCNAV_GIMBAL_MANAGER_ERROR_SD_CARD_FULL                     = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_SD_CARD_FULL,
    CHCNAV_GIMBAL_MANAGER_ERROR_SD_CARD_ERROR                    = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_SD_CARD_ERROR,
    CHCNAV_GIMBAL_MANAGER_ERROR_SENSOR_ERROR                     = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_SENSOR_ERROR,
    CHCNAV_GIMBAL_MANAGER_ERROR_REMOTE_CONTROL_UNCONNECTED       = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_REMOTE_CONTROL_UNCONNECTED,
    CHCNAV_GIMBAL_MANAGER_ERROR_AIRCRAFT_UNCONNECTED             = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_AIRCRAFT_UNCONNECTED,
    CHCNAV_GIMBAL_MANAGER_ERROR_UNDEFINE_ERROR                   = CHCNAV_GIMBAL_MANAGER_MODULE_ERROR - CHCNAV_GIMBAL_MANAGER_ERR_CODE_UNDEFINE_ERROR,
    /* Fc subscription errors range -401 ~ -500 */
    CHCNAV_FC_SUBSCRIPTION_ERROR_CODE_NOT_INIT                   = CHCNAV_FC_SUBSCRIPTION_MODULE_ERROR - CHCNAV_FC_SUBSCRIPTION_ERR_CODE_NOT_INIT,
    CHCNAV_FC_SUBSCRIPTION_ERROR_CODE_ALLOC_FAILED               = CHCNAV_FC_SUBSCRIPTION_MODULE_ERROR - CHCNAV_FC_SUBSCRIPTION_ERR_CODE_ALLOC,
    CHCNAV_FC_SUBSCRIPTION_ERROR_CODE_TIMEOUT                    = CHCNAV_FC_SUBSCRIPTION_MODULE_ERROR - CHCNAV_FC_SUBSCRIPTION_ERR_CODE_TIMEOUT,
    CHCNAV_FC_SUBSCRIPTION_ERROR_CODE_INVALID_PARAM              = CHCNAV_FC_SUBSCRIPTION_MODULE_ERROR - CHCNAV_FC_SUBSCRIPTION_ERR_CODE_PARAM,
    CHCNAV_FC_SUBSCRIPTION_ERROR_CODE_SYSTEM                     = CHCNAV_FC_SUBSCRIPTION_MODULE_ERROR - CHCNAV_FC_SUBSCRIPTION_ERR_CODE_SYSTEM,
    CHCNAV_FC_SUBSCRIPTION_ERROR_CODE_MAXIMUM_LIMIT_EXCEEDED     = CHCNAV_FC_SUBSCRIPTION_MODULE_ERROR - CHCNAV_FC_SUBSCRIPTION_ERR_CODE_MAXIMUM_LIMIT_EXCEEDED,
    CHCNAV_FC_SUBSCRIPTION_ERROR_CODE_INVALID_TOPIC_FREQ         = CHCNAV_FC_SUBSCRIPTION_MODULE_ERROR - CHCNAV_FC_SUBSCRIPTION_ERR_CODE_INVALID_TOPIC_FREQ,
    CHCNAV_FC_SUBSCRIPTION_ERROR_CODE_TOPIC_DUPLICATE            = CHCNAV_FC_SUBSCRIPTION_MODULE_ERROR - CHCNAV_FC_SUBSCRIPTION_ERR_CODE_TOPIC_DUPLICATE,
    CHCNAV_FC_SUBSCRIPTION_ERROR_CODE_TOPIC_NOT_SUBSCRIBED       = CHCNAV_FC_SUBSCRIPTION_MODULE_ERROR - CHCNAV_FC_SUBSCRIPTION_ERR_CODE_TOPIC_NOT_SUBSCRIBED,
    CHCNAV_FC_SUBSCRIPTION_ERROR_CODE_TIMESTAMP_NOT_ENABLE       = CHCNAV_FC_SUBSCRIPTION_MODULE_ERROR - CHCNAV_FC_SUBSCRIPTION_ERR_CODE_TIMESTAMP_NOT_ENABLE,
    CHCNAV_FC_SUBSCRIPTION_ERROR_CODE_TOPIC_NOT_SUPPORTED        = CHCNAV_FC_SUBSCRIPTION_MODULE_ERROR - CHCNAV_FC_SUBSCRIPTION_ERR_CODE_TOPIC_NOT_SUPPORTED,
} CHCNAV_ERROR_CODE_E;

#ifdef __cplusplus
}
#endif
#endif //CHCNAV_ERROR_H