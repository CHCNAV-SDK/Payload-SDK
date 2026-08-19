# Gimbal Management
This document describes the key information and usage of structures and function prototypes in the `chcnav_gimbal_manager.h` file.
- Struct
  * CHCNAV_GIMBAL_MANAGER_ROTATION_STRUCT

- Function
  * chcnav_gimbal_manager_init
  * chcnav_gimbal_manager_deinit
  * chcnav_gimbal_manager_set_mode
  * chcnav_gimbal_manager_reset
  * chcnav_gimbal_manager_rorate
  * chcnav_gimbal_manager_restore_factory_settings

## Struct
### CHCNAV_GIMBAL_MANAGER_ROTATION_STRUCT
  ```
  typedef struct {
    chcnav_f32_t pitch; /* Pitch angle, unit: degree */
    chcnav_f32_t roll; /* Roll angle, unit: degree */
    chcnav_f32_t yaw; /* Yaw angle, unit: degree */
} CHCNAV_GIMBAL_MANAGER_ROTATION_STRUCT;
  ```

## Function
### chcnav_gimbal_manager_init
  **Function**: Initialize the gimbal management module.
  ```
  chcnav_return_code_t chcnav_gimbal_manager_init(void);
  ```
  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_gimbal_manager_deinit
  **Function**: Deinitialize the gimbal management module.
  ```
  chcnav_return_code_t chcnav_gimbal_manager_deinit(void);
  ```
  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_gimbal_manager_set_mode
  **Function**: Set the gimbal operating mode.
  ```
  chcnav_return_code_t chcnav_gimbal_manager_set_mode(CHCNAV_MOUNT_POSITION_E position, CHCNAV_GIMBAL_MODE_E mode);
  ```
  **Parameters**:
  * position: Gimbal mount position.
  * mode: Gimbal operating mode. See `CHCNAV_GIMBAL_MODE_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_gimbal_manager_reset
  **Function**: Reset gimbal attitude; pitch and yaw reset angles can be configured.
  ```
  chcnav_return_code_t chcnav_gimbal_manager_reset(CHCNAV_MOUNT_POSITION_E position, CHCNAV_GIMBAL_RESET_MODE_E reset_mode);
  ```
  **Parameters**:
  * position: Gimbal mount position.
  * reset_mode: Gimbal attitude reset mode. See `CHCNAV_GIMBAL_RESET_MODE_E`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_gimbal_manager_rorate
  **Function**: Control gimbal attitude.
  ```
  chcnav_return_code_t chcnav_gimbal_manager_rorate(CHCNAV_MOUNT_POSITION_E position, CHCNAV_GIMBAL_MANAGER_ROTATION_STRUCT rotation);
  ```
  **Parameters**:
  * position: Gimbal mount position.
  * rotation: Target gimbal rotation angles. See `CHCNAV_GIMBAL_MANAGER_ROTATION_STRUCT`.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_gimbal_manager_restore_factory_settings
  **Function**: Restore gimbal factory settings.
  ```
  chcnav_return_code_t chcnav_gimbal_manager_restore_factory_settings(CHCNAV_MOUNT_POSITION_E position);
  ```
  **Parameters**:
  * position: Gimbal mount position.

  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
