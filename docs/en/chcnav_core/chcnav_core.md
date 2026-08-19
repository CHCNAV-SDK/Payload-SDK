# CHCNAV Core
The header file for PSDK Core functionality is `chcnav_core.h`. This document describes the key information and usage of structures and function prototypes in the `chcnav_core.h` file.

## Function
- chcnav_core_init
- chcnav_core_start
- chcnav_core_deinit

# Function
## chcnav_core_init
Initialize the Payload SDK core.
- Notes:
> - Pay special attention to where `chcnav_core_init` is called. It must be invoked after OSAL handler functions and HAL handler functions have been registered, and it must be initialized before calling other functional module interfaces.

## chcnav_core_start
Notify the Payload SDK core application to start. This must be called after all modules have been initialized and their interfaces registered.

## chcnav_core_deinit
Deinitialize Payload SDK Core.
