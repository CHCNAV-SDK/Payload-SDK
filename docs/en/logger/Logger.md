# CHCNAV Logger
The header file for PSDK logger management is `chcnav_logger.h`. This document describes the key information and usage of macro definitions, enumerations, structures, and function prototypes in the `chcnav_logger.h` file.

- Definition
  * CHCNAV_LOGGER_CONSOLE_MAX_NUM
  * CHCNAV_LOGGER_MAX_USER_LOG_LEN
- Enum
  * CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_E
- Struct
  * CHCNAV_LOGGER_CONSOLE_STRUCT

## Definition
### CHCNAV_LOGGER_CONSOLE_MAX_NUM
  Maximum number of consoles that can be registered at the same time.
  ```
    #define CHCNAV_LOGGER_CONSOLE_MAX_NUM  8
  ```
### CHCNAV_LOGGER_MAX_USER_LOG_LEN
  Maximum length of user log body (after `fmt` expansion), in bytes. If exceeded, output is still emitted after truncation; the prefix (relative time, module name, level) does not count toward this limit.
  ```
    #define CHCNAV_LOGGER_MAX_USER_LOG_LEN  256
  ```
### Log Output Macros
| Interface | Description |
|---------------|----------|
| CHCNAV_LOG_DEBUG() | Output Debug-level log messages |
| CHCNAV_LOG_INFO() | Output Info-level log messages |
| CHCNAV_LOG_WARN() | Output Warn-level log messages |
| CHCNAV_LOG_ERROR() | Output Error-level log messages |

## Enum
### CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_E
  Console log levels. Higher numeric values indicate greater severity; a message is output to a console only when its level is **≥** that console's configured level.
  ```
    typedef enum {
        CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_DEBUG = 0,
        CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_INFO  = 1,
        CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_WARN  = 2,
        CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_ERROR = 3,
    } CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_E;
  ```

## Struct
### CHCNAV_LOGGER_CONSOLE_STRUCT
  Console registered with the logger.
  ```
    typedef struct {
        CHCNAV_LOGGER_CONSOLE_FUNC func;                 /* Output callback */
        CHCNAV_LOGGER_CONSOLE_LOG_LEVEL_E console_level; /* Minimum severity level allowed for this console */
    } CHCNAV_LOGGER_CONSOLE_STRUCT;
  ```
  Callback prototype:
  ```
    typedef chcnav_return_code_t (*CHCNAV_LOGGER_CONSOLE_FUNC)(const uint8_t *data,
                                                               uint16_t data_len);
  ```

## Function
### chcnav_logger_add_console
  Register a log console. Up to 8 consoles; if the same `func` is registered again, its level is updated.
### chcnav_logger_remove_console
  Remove a registered console.
