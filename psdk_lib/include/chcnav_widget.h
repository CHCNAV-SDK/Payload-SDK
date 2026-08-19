/********************************************************************************
 * Copyright (c) 2025 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file chcnav_widget.h
 * @brief This is the header file for PSDK Widget module, defining the structure
 * and (exported) function prototypes.
 ********************************************************************************/

#ifndef CHCNAV_WIDGET_H
#define CHCNAV_WIDGET_H

/* Includes ------------------------------------------------------------------*/
#include "chcnav_typedef.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Exported constants --------------------------------------------------------*/

/*! The maximum length of a message that can be displayed by the mobile app floating window */
#define CHCNAV_WIDGET_FLOATING_WINDOW_MSG_MAX_LEN         255

/* Exported types ------------------------------------------------------------*/

/**
 * @brief Widget types.
 */
typedef enum {
    CHCNAV_WIDGET_TYPE_BUTTON = 1,      /*!< Button widget type */
    CHCNAV_WIDGET_TYPE_SWITCH = 2,      /*!< Switch widget type */
    CHCNAV_WIDGET_TYPE_SCALE = 3,       /*!< Scale widget type */
    CHCNAV_WIDGET_TYPE_LIST = 4,        /*!< List widget type */
    CHCNAV_WIDGET_TYPE_INT_INPUT = 5,   /*!< Integer input box widget type */
} CHCNAV_WIDGET_TYPE_E;

/**
 * @brief Button widget state.
 */
typedef enum {
    CHCNAV_WIDGET_BUTTON_STATE_RELEASE_UP = 0, /*!< Button is released up */
    CHCNAV_WIDGET_BUTTON_STATE_PRESS_DOWN = 1, /*!< Button is pressed down */
} CHCNAV_WIDGET_BUTTON_STATE_E;

/**
 * @brief Switch widget state.
 */
typedef enum {
    CHCNAV_WIDGET_SWITCH_STATE_OFF = 0, /*!< Switch is turned off */
    CHCNAV_WIDGET_SWITCH_STATE_ON = 1,  /*!< Switch is turned on */
} CHCNAV_WIDGET_SWITCH_STATE_E;

/**
 * @brief Widget file binary array.
 * @note Used in RTOS environment where there is no file system. Widget config
 *       file content is expressed as a C array.
 */
typedef struct {
    char *file_name;                /*!< The file name of the widget file. */
    uint32_t file_size;             /*!< The file size of the widget file, unit: byte. */
    const uint8_t *file_binary_array; /*!< The binary C array of the widget file. */
} CHCNAV_WIDGET_FILE_BINARY_ARRAY_STRUCT;

/**
 * @brief Widget binary array config.
 * @note Used in RTOS environment to register multiple widget config files as
 *       binary arrays.
 */
typedef struct {
    uint16_t binary_array_count;                              /*!< Binary array count. */
    CHCNAV_WIDGET_FILE_BINARY_ARRAY_STRUCT *file_binary_array_list; /*!< Pointer to binary array list. */
} CHCNAV_WIDGET_BINARY_ARRAY_CONFIG_STRUCT;

/**
 * @brief Widget handler list item.
 * @details Each item represents one widget that the payload implements.
 *          The index must be unique and is used to identify the widget
 *          in MAVLink messages.
 */
typedef struct {
    /*! The index of widget, numbered starting from 0, cannot be repeated. */
    uint32_t widget_index;

    /*! The type of widget, refer to ::CHCNAV_WIDGET_TYPE_E. */
    CHCNAV_WIDGET_TYPE_E widget_type;

    /**
     * @brief Prototype of callback function used to set widget value. Called when the user
     *        triggers the widget in the mobile app.
     * @param widget_type: the type of widget, refer to ::CHCNAV_WIDGET_TYPE_E.
     * @param index: the index of widget.
     * @param value: the value of widget, need to be set.
     *   - Button (CHCNAV_WIDGET_TYPE_BUTTON): value is ::CHCNAV_WIDGET_BUTTON_STATE_E.
     *   - Switch (CHCNAV_WIDGET_TYPE_SWITCH): value is ::CHCNAV_WIDGET_SWITCH_STATE_E.
     *   - Scale  (CHCNAV_WIDGET_TYPE_SCALE):  value range 0 to 100 (percentage).
     *   - List   (CHCNAV_WIDGET_TYPE_LIST):   value range 0 to N-1 (selected item index).
     *   - IntInput (CHCNAV_WIDGET_TYPE_INT_INPUT): input integer value.
     * @param user_data: the user data registered in handler list item.
     * @return Execution result.
     */
    chcnav_return_code_t (*set_widget_value)(CHCNAV_WIDGET_TYPE_E widget_type, uint32_t index, int32_t value,
                                             void *user_data);

    /**
     * @brief Prototype of callback function used to get widget value.
     * @param widget_type: the type of widget, refer to ::CHCNAV_WIDGET_TYPE_E.
     * @param index: the index of widget.
     * @param value: output, the value of widget. Refer to set_widget_value for value
     *        meaning for each widget type.
     * @param user_data: the user data registered in handler list item.
     * @return Execution result.
     */
    chcnav_return_code_t (*get_widget_value)(CHCNAV_WIDGET_TYPE_E widget_type, uint32_t index, int32_t *value,
                                             void *user_data);

    /*! User data that will be passed to set_widget_value and get_widget_value callbacks. */
    void *user_data;
} CHCNAV_WIDGET_HANDLER_LIST_ITEM_STRUCT;

/* Exported functions --------------------------------------------------------*/

/**
 * @brief Initialize widget module. Must be called before using any widget features.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_widget_init(void);

/**
 * @brief Deinitialize widget module. Release all resources allocated by the widget module.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_widget_deinit(void);

/**
 * @brief Register default widget UI configuration file directory path.
 * @note Under Linux system, there are two functions to set the custom widget configuration
 *       directory path: chcnav_register_default_widget_config_dir_path and
 *       chcnav_register_widget_config_by_dir_path.
 *       When you don't need multi-language support, use
 *       chcnav_register_default_widget_config_dir_path. For multi-language support, use
 *       chcnav_register_widget_config_by_dir_path. When language is not covered
 *       by your settings via chcnav_register_widget_config_by_dir_path, the configuration set by
 *       chcnav_register_default_widget_config_dir_path is used as fallback.
 * @param widget_config_dir_path: the widget UI configuration directory path.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_register_default_widget_config_dir_path(const char *widget_config_dir_path);

/**
 * @brief Register widget UI configuration file directory path for specific language.
 * @note Different widget UI configurations for several languages must have
 *       the same widget type, index and count.
 * @param app_language: mobile app language type, refer to ::CHCNAV_MOBILE_APP_LANGUAGE_E.
 * @param widget_config_dir_path: the widget UI configuration directory path.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_register_widget_config_by_dir_path(CHCNAV_MOBILE_APP_LANGUAGE_E app_language,
                                                               const char *widget_config_dir_path);

/**
 * @brief Register default widget UI config by binary array configuration.
 * @note In RTOS, most likely there is no file system. Widget config file content can be
 *       expressed as C arrays. Use this function and chcnav_register_widget_config_by_binary_array
 *       to set widget UI configuration. When language is not covered by
 *       settings via chcnav_register_widget_config_by_binary_array, the configuration set by this
 *       function is used as fallback.
 * @param binary_array_config: the binary array config for widget UI configuration.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_register_default_widget_config_by_binary_array(
    const CHCNAV_WIDGET_BINARY_ARRAY_CONFIG_STRUCT *binary_array_config);

/**
 * @brief Register widget UI config by binary array configuration for specific language.
 * @note Different widget UI configurations for several languages must have
 *       the same widget type, index and count.
 * @param app_language: mobile app language type, refer to ::CHCNAV_MOBILE_APP_LANGUAGE_E.
 * @param binary_array_config: the binary array config for widget UI configuration.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_register_widget_config_by_binary_array(
    CHCNAV_MOBILE_APP_LANGUAGE_E app_language,
    const CHCNAV_WIDGET_BINARY_ARRAY_CONFIG_STRUCT *binary_array_config);

/**
 * @brief Register handler list for widgets.
 * @note The handler list defines which widgets the payload provides and how they
 *       respond to user interactions. Each item must have a unique widget_index.
 * @param widget_handler_list: pointer to the widget handler list array.
 * @param item_count: number of items in the handler list.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_register_widget_handler_list(
    const CHCNAV_WIDGET_HANDLER_LIST_ITEM_STRUCT *widget_handler_list,
    uint32_t item_count);

/**
 * @brief Send message to mobile app floating window.
 * @note The message length must not exceed CHCNAV_WIDGET_FLOATING_WINDOW_MSG_MAX_LEN.
 *       The max data bandwidth of floating window messages is 2KB/s.
 * @param str: pointer to the message string (null-terminated).
 * @return Execution result.
 */
chcnav_return_code_t chcnav_floating_window_show_message(const char *str);

#ifdef __cplusplus
}
#endif

#endif /* CHCNAV_WIDGET_H */
