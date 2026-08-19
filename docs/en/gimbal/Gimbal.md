# Gimbal Features
The header file for PSDK gimbal functionality is `chcnav_gimbal.h`. This document describes the key information and usage of structures and function prototypes in the `chcnav_gimbal.h` file.

- Enum
  * CHCNAV_GIMBAL_ERROR_FLAGS_E
  * CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_E
  * CHCNAV_GIMBAL_RESET_MODE_E
- Struct
  * CHCNAV_GIMBAL_INFORMATION_STRUCT
  * CHCNAV_GIMBAL_ATTITUDE_STATUS_STRUCT
  * CHCNAV_GIMBAL_SET_ATTITUDE_STRUCT
  * CHCNAV_GIMBAL_COMMON_HANDLER_STRUCT
- Function
  * chcnav_gimbal_init
  * chcnav_gimbal_deinit
  * chcnav_gimbal_register_common_handler
## Enum
### CHCNAV_GIMBAL_ERROR_FLAGS_E
  Failure flags for gimbal-class devices.
  ```
    typedef enum {
        /* No gimbal error */
        CHCNAV_GIMBAL_NO_ERROR = 0,
        /* Gimbal device is constrained by the hardware roll limit */
        CHCNAV_GIMBAL_ERROR_FLAGS_AT_ROLL_LIMIT=1,
        /* Gimbal device is constrained by the hardware pitch limit */
        CHCNAV_GIMBAL_ERROR_FLAGS_AT_PITCH_LIMIT=2,
        /* Gimbal device is constrained by the hardware yaw limit. */
        CHCNAV_GIMBAL_ERROR_FLAGS_AT_YAW_LIMIT=4,
        /* Gimbal gimbal encoder error */
        CHCNAV_GIMBAL_ERROR_FLAGS_ENCODER_ERROR=8,
        /* Gimbal power error */
        CHCNAV_GIMBAL_ERROR_FLAGS_POWER_ERROR=16,
        /* Gimbal gimbal motor fault */
        CHCNAV_GIMBAL_ERROR_FLAGS_MOTOR_ERROR=32,
        /* Gimbal software error */
        CHCNAV_GIMBAL_ERROR_FLAGS_SOFTWARE_ERROR=64,
        /* Gimbal communication error */
        CHCNAV_GIMBAL_ERROR_FLAGS_COMMS_ERROR=128,
        /* Gimbal gimbal device is currently calibrating */
        CHCNAV_GIMBAL_ERROR_FLAGS_CALIBRATION_RUNNING=256,
        /* Gimbal gimbal device is not assigned to a gimbal manager */
        CHCNAV_GIMBAL_ERROR_FLAGS_NO_MANAGER=512,
        /* End marker for gimbal error enumeration */
        CHCNAV_GIMBAL_ERROR_FLAGS_ENUM_END=513,
    } CHCNAV_GIMBAL_ERROR_FLAGS_E;
  ```
### CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_E
  Gimbal attitude compensation.
  ```
    typedef enum
    {
      /* Disable gimbal attitude compensation */
      CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_DISABLE = 0,
      /* Gimbal angle compensation */
      CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_ANGLE = 1,
      /* Gimbal angular velocity compensation */
      CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_VELOCITY = 2,
      /* Gimbal angle and angular velocity compensation simultaneously */
      CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_ANGLE_AND_VELOCITY = 3,*/
    } CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_E;
  ```
### CHCNAV_GIMBAL_RESET_MODE_E
  Reset modes for gimbal-class devices.
  ```
    typedef enum {
        /* Gimbal yaw centering */
        CHCNAV_GIMBAL_RESET_MODE_YAW = 1,
        /* Gimbal pitch and yaw centering */
        CHCNAV_GIMBAL_RESET_MODE_PITCH_AND_YAW = 3,
        /* Gimbal yaw centering with pitch axis pointing downward */
        CHCNAV_GIMBAL_RESET_MODE_PITCH_DOWNWARD_UPWARD_AND_YAW = 11,
        /* Gimbal pitch axis pointing downward */
        CHCNAV_GIMBAL_RESET_MODE_PITCH_DOWNWARD_UPWARD = 12,
    } CHCNAV_GIMBAL_RESET_MODE_E;
  ```

## Struct
### CHCNAV_GIMBAL_INFORMATION_STRUCT
  Basic information for gimbal-class devices.
  ```
    typedef struct {
        /* UID of the gimbal gimbal hardware (0 if unknown) */
        uint64_t uid;
        /* Timestamp (time since system boot) */
        uint32_t time_boot_ms;
        /* Gimbal firmware version, encoded as (Dev & 0xff) << 24 | (Patch & 0xff) << 16 |
            (Minor & 0xff) << 8 | (Major & 0xff) */
        uint32_t firmware_version;
        /* Gimbal hardware version, encoded as (Dev & 0xff) << 24 | (Patch & 0xff) << 16 |
            (Minor & 0xff) << 8 | (Major & 0xff) */
        uint32_t hardware_version;
        /* Minimum hardware roll angle (positive: roll right, negative: roll left). NAN if unknown */
        float roll_min;
        /* Maximum hardware roll angle (positive: roll right, negative: roll left). NAN if unknown */
        float roll_max;
        /* Minimum hardware pitch angle (positive: up, negative: down). NAN if unknown */
        float pitch_min;
        /* Maximum hardware pitch angle (positive: up, negative: down). NAN if unknown */
        float pitch_max;
        /* Minimum hardware yaw angle (positive: right, negative: left). NAN if unknown */
        float yaw_min;
        /* Maximum hardware yaw angle (positive: right, negative: left). NAN if unknown */
        float yaw_max;
        /* Bitmap of gimbal capability flags */
        uint16_t cap_flags;
        /* Bitmap for gimbal-specific feature flags */
        uint16_t custom_cap_flags;
        /* Name of the gimbal vendor */
        char vendor_name[32];
        /* Gimbal model name */
        char model_name[32];
        /* Custom name assigned to the gimbal by the user */
        char custom_name[32];
    } CHCNAV_GIMBAL_INFORMATION_STRUCT;
  ```
### CHCNAV_GIMBAL_ATTITUDE_STATUS_STRUCT
  Attitude of gimbal-class devices.
  ```
    typedef struct {
        /* Timestamp (time since system boot) */
        uint32_t time_boot_ms;
        /* Quaternion components w, x, y, z (1 0 0 0 is zero rotation) */
        float q[4];
        /* X component of angular velocity (positive: roll right). NAN if unknown, unit: rad/s */
        float angular_velocity_x;
        /* Y component of angular velocity (positive: pitch up). NAN if unknown, unit: rad/s */
        float angular_velocity_y;
        /* Z component of angular velocity (positive: yaw right). NAN if unknown, unit: rad/s */
        float angular_velocity_z;
        /* Failure flags; see CHCNAV_GIMBAL_ERROR_FLAGS_E for details */
        uint32_t failure_flags;
        /* Currently set gimbal flags */
        uint16_t flags;
        /* Yaw angle associated with the quaternion in earth and body coordinate frames. NAN if unknown, unit: rad */
        float delta_yaw;
        /* Yaw angular velocity associated with angular velocity in earth and body coordinate frames. NAN if unknown, unit: rad/s */
        float delta_yaw_velocity;
    } CHCNAV_GIMBAL_ATTITUDE_STATUS_STRUCT;
  ```
### CHCNAV_GIMBAL_SET_ATTITUDE_STRUCT
  Set the attitude of gimbal-class devices.
  ```
    typedef struct {
        /* Quaternion components w, x, y, z (1 0 0 0 is zero rotation; frame depends on whether flags are set) */
        float q[4];
        /* X component of angular velocity; positive means roll right, NaN is ignored, unit: rad/s */
        float angular_velocity_x;
        /* Y component of angular velocity; positive means pitch up, NaN is ignored, unit: rad/s */
        float angular_velocity_y;
        /* Z component of angular velocity; positive means yaw right, NaN is ignored, unit: rad/s */
        float angular_velocity_z;
        /* Advanced gimbal manager flags to use */
        uint16_t flags;
    } CHCNAV_GIMBAL_SET_ATTITUDE_STRUCT;
  ```
### CHCNAV_GIMBAL_COMMON_HANDLER_STRUCT
  Gimbal control. Use the functions in this structure to implement gimbal control callbacks, including:
  - Get gimbal device information
  - Get current gimbal state
  - Set gimbal attitude
  - Set gimbal operating mode
  - Get gimbal operating mode
  - Reset gimbal parameters
  - Restore factory settings
  - Gimbal attitude compensation
  ```
    typedef struct {
        /**
        * @brief Get gimbal device information
        * @param gimbal_information: Pointer to a structure for storing gimbal-class payload device information
        * @return Execution result
        */
        chcnav_return_code_t (*get_gimbal_information)(
            CHCNAV_GIMBAL_INFORMATION_STRUCT *gimbal_information);

        /**
        * @brief Get current gimbal state
        * @param system_state: Pointer to a structure for storing gimbal-class payload device state
        * @return Execution result
        */
        chcnav_return_code_t (*get_gimbal_attitude_state)(
            CHCNAV_GIMBAL_ATTITUDE_STATUS_STRUCT *system_state);

        /**
        * @brief Set gimbal attitude
        * @param attitude: Pointer to a structure for storing gimbal-class payload device attitude information
        * @return Execution result
        */
        chcnav_return_code_t (*set_gimbal_attitude)(
            CHCNAV_GIMBAL_SET_ATTITUDE_STRUCT *attitude);

        /**
        * @brief Set gimbal operating mode
        * @param mode: Enumeration for storing the gimbal-class payload device operating mode
        * @return Execution result
        */
        chcnav_return_code_t (*set_gimbal_mode)(CHCNAV_GIMBAL_MODE_E mode);

        /**
        * @brief Get gimbal operating mode
        * @param mode: Enumeration for storing the gimbal-class payload device operating mode
        * @return Execution result
        */
        chcnav_return_code_t (*get_gimbal_mode)(CHCNAV_GIMBAL_MODE_E *mode);

        /**
        * @brief Reset gimbal parameters
        * @param mode: Enumeration for storing the gimbal-class payload device reset mode
        * @return Execution result
        */
        chcnav_return_code_t (*reset_mode)(CHCNAV_GIMBAL_RESET_MODE_E mode);

        /**
        * @brief Restore gimbal factory settings
        * @return Execution result
        */
        chcnav_return_code_t (*reset_factory_settings)(void);

        /**
        * @brief Set gimbal attitude compensation
        * @return Execution result
        */
        chcnav_return_code_t (*set_gimbal_attitude_compansation_mode)(CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_E mode);

        /**
        * @brief Get gimbal attitude compensation
        * @return Execution result
        */
        chcnav_return_code_t (*get_gimbal_attitude_compansation_mode)(CHCNAV_GIMBAL_ATTITUDE_COMPENSATION_E *mode);
    } CHCNAV_GIMBAL_COMMON_HANDLER_STRUCT;
  ```
## Function
### chcnav_gimbal_init
  Call this interface to initialize the gimbal module before using gimbal control functionality.
### chcnav_gimbal_deinit
  Deinitialize the gimbal module.
### chcnav_gimbal_register_common_handler
  Register callbacks for gimbal control.
