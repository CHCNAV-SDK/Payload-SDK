# Custom Widgets
The header file for PSDK custom widget functionality is `chcnav_widget.h`. This document describes the key information and usage of macro definitions, structures, and function prototypes in the `chcnav_widget.h` file.

- Definition
  * CHCNAV_WIDGET_FLOATING_WINDOW_MSG_MAX_LEN
- Enum
  * CHCNAV_WIDGET_TYPE_E
  * CHCNAV_WIDGET_BUTTON_STATE_E
  * CHCNAV_WIDGET_SWITCH_STATE_E
- Struct
  * CHCNAV_WIDGET_FILE_BINARY_ARRAY_STRUCT
  * CHCNAV_WIDGET_BINARY_ARRAY_CONFIG_STRUCT
  * CHCNAV_WIDGET_HANDLER_LIST_ITEM_STRUCT
- Function
  * chcnav_widget_init
  * chcnav_widget_deinit
  * chcnav_register_default_widget_config_dir_path
  * chcnav_register_widget_config_by_dir_path
  * chcnav_register_default_widget_config_by_binary_array
  * chcnav_register_widget_config_by_binary_array
  * chcnav_register_widget_handler_list
  * chcnav_floating_window_show_message


## Definition
### CHCNAV_WIDGET_FLOATING_WINDOW_MSG_MAX_LEN
  Maximum length of a floating window message, in bytes.
  ```
    #define CHCNAV_WIDGET_FLOATING_WINDOW_MSG_MAX_LEN  255
  ```

## Enum
### CHCNAV_WIDGET_TYPE_E
  Custom widget types.
  ```
    typedef enum {
        CHCNAV_WIDGET_TYPE_BUTTON = 1,      /* Button */
        CHCNAV_WIDGET_TYPE_SWITCH = 2,      /* Switch */
        CHCNAV_WIDGET_TYPE_SCALE = 3,       /* Slider */
        CHCNAV_WIDGET_TYPE_LIST = 4,        /* List */
        CHCNAV_WIDGET_TYPE_INT_INPUT = 5,   /* Integer input box */
    } CHCNAV_WIDGET_TYPE_E;
  ```
### CHCNAV_WIDGET_BUTTON_STATE_E
  Button widget states.
  ```
    typedef enum {
        CHCNAV_WIDGET_BUTTON_STATE_RELEASE_UP = 0, /* Button released */
        CHCNAV_WIDGET_BUTTON_STATE_PRESS_DOWN = 1, /* Button pressed */
    } CHCNAV_WIDGET_BUTTON_STATE_E;
  ```
### CHCNAV_WIDGET_SWITCH_STATE_E
  Switch widget states.
  ```
    typedef enum {
        CHCNAV_WIDGET_SWITCH_STATE_OFF = 0, /* Off */
        CHCNAV_WIDGET_SWITCH_STATE_ON = 1,  /* On */
    } CHCNAV_WIDGET_SWITCH_STATE_E;
  ```

## Struct
### CHCNAV_WIDGET_FILE_BINARY_ARRAY_STRUCT
  Widget binary array file.
  ```
    typedef struct {
        char *file_name;                  /* File name */
        uint32_t file_size;               /* File size, in bytes */
        const uint8_t *file_binary_array; /* File binary C array */
    } CHCNAV_WIDGET_FILE_BINARY_ARRAY_STRUCT;
  ```
### CHCNAV_WIDGET_BINARY_ARRAY_CONFIG_STRUCT
  Widget custom widget binary array configuration file.
  ```
    typedef struct {
        uint16_t binary_array_count;                               /* Number of binary array widget files */
        CHCNAV_WIDGET_FILE_BINARY_ARRAY_STRUCT *file_binary_array_list; /* List of binary array widget files */
    } CHCNAV_WIDGET_BINARY_ARRAY_CONFIG_STRUCT;
  ```
### CHCNAV_WIDGET_HANDLER_LIST_ITEM_STRUCT
  Widget handler functions.
  ```
    typedef struct {
        uint32_t widget_index;   /* Custom widget index, numbered from 0, must be unique */
        CHCNAV_WIDGET_TYPE_E widget_type; /* Widget type; see CHCNAV_WIDGET_TYPE_E */
        /**
         * @brief Set widget value
         * @param widget_type: Widget type
         * @param index: Widget index
         * @param value: Widget value
         * @param user_data: User data pointer
         * @return Execution result
         */
        chcnav_return_code_t (*set_widget_value)(CHCNAV_WIDGET_TYPE_E widget_type, uint32_t index,
                                                 int32_t value, void *user_data);
        /**
         * @brief Get widget value
         * @param widget_type: Widget type
         * @param index: Widget index
         * @param value: Output widget value
         * @param user_data: User data
         * @return Execution result
         */
        chcnav_return_code_t (*get_widget_value)(CHCNAV_WIDGET_TYPE_E widget_type, uint32_t index,
                                                 int32_t *value, void *user_data);
        void *user_data; /* User data pointer */
    } CHCNAV_WIDGET_HANDLER_LIST_ITEM_STRUCT;
  ```

## Function
### chcnav_widget_init
  Initialize the custom widget module. This interface must be called before using any Widget functionality.
### chcnav_widget_deinit
  Deinitialize the custom widget module and release resources allocated by the module.
### chcnav_register_default_widget_config_dir_path
  Register the default path for custom widget configuration files.
  - Only payload devices developed on Linux support this interface.
  - On Linux, use `chcnav_register_default_widget_config_dir_path()` and `chcnav_register_widget_config_by_dir_path()` to set the path to custom widget configuration files.
  - When multi-language widget configuration is not required, only use `chcnav_register_default_widget_config_dir_path()` to register the widget configuration file.
  - When multi-language support is required, you must use `chcnav_register_widget_config_by_dir_path()` to specify widget configuration for a particular language. If no configuration exists for the requested language, the configuration registered by `chcnav_register_default_widget_config_dir_path()` is used.
### chcnav_register_widget_config_by_dir_path
  Register the path to custom widget configuration files.
  - Only payload devices developed on Linux support this interface.
  - Widget configurations for different languages must have the same widget types, indices, and counts.
### chcnav_register_default_widget_config_by_binary_array
  Register the default widget configuration via binary array widget files.
  - Only payload devices developed on RTOS support this interface.
  - On RTOS, use this interface and `chcnav_register_widget_config_by_binary_array()` to set widget configuration parameters.
  - If widget configuration matching the system language is not registered with `chcnav_register_widget_config_by_binary_array()`, the configuration from this function is used.
### chcnav_register_widget_config_by_binary_array
  Register widget configuration information via binary array widget files.
  - Only payload devices developed on RTOS support this interface.
  - Widget configurations for different languages must have the same widget types, indices, and counts.
### chcnav_register_widget_handler_list
  Register the custom widget handler function list.
### chcnav_floating_window_show_message
  Send a message to the floating window in SmartGo or a mobile app developed with MSDK.
