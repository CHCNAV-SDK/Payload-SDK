# Data Subscription
This document describes the key information and usage of structures and function prototypes in the `chcnav_fc_subscription.h` file.
- Enum
  * CHCNAV_FC_SUBSCRIPTION_TOPIC_E
  * CHCNAV_FC_SUBSCRIPTION_FLIGHT_STATUS_E
- Struct
  * CHCNAV_FC_SUBSCRIPTION_VELOCITY_STRUCT
  * CHCNAV_FC_SUBSCRIPTION_POSITION_FUSED_STRUCT
  * CHCNAV_FC_SUBSCRIPTION_GPS_TIME_STRUCT
  * CHCNAV_FC_SUBSCRIPTION_GPS_POSITION_STRUCT
  * CHCNAV_FC_SUBSCRIPTION_BATTERY_INFO_STRUCT
  * CHCNAV_FC_SUBSCRIPTION_ATTITUDE_STRUCT
- Function
  * chcnav_fc_subscription_init
  * chcnav_fc_subscription_deInit
  * chcnav_fc_subscription_subscribe_topic
  * chcnav_fc_subscription_unsubscribe_topic
  * chcnav_fc_subscription_get_latest_value_of_topic

## Enum
### CHCNAV_FC_SUBSCRIPTION_TOPIC_E
  ```
  typedef enum {
    /*!
     * @brief Velocity of aircraft topic name. Velocity topic provides aircraft's velocity in a ground-fixed NED frame.
     * Please refer to ::CHCNAV_FC_SUBSCRIPTION_VELOCITY_STRUCT for information about data structure.
     * @datastruct CHCNAV_FC_SUBSCRIPTION_VELOCITY_STRUCT
     */
    CHCNAV_FC_SUBSCRIPTION_TOPIC_VELOCITY = 4,
    /*!
     * Fused position of aircraft topic name. Please refer to ::CHCNAV_FC_SUBSCRIPTION_POSITION_FUSED_STRUCT for information
     * about data structure.
     * @datastruct CHCNAV_FC_SUBSCRIPTION_POSITION_FUSED_STRUCT
     */
    CHCNAV_FC_SUBSCRIPTION_TOPIC_POSITION_FUSED = 12,
    /*!
     * @brief GPS time topic name. Please refer to ::CHCNAV_FC_SUBSCRIPTION_GPS_TIME_STRUCT for information about data structure.
     * @datastruct CHCNAV_FC_SUBSCRIPTION_GPS_TIME_STRUCT
     */
    CHCNAV_FC_SUBSCRIPTION_TOPIC_GPS_TIME = 14,
    /*!
     * @brief GPS position topic name. Please refer to ::CHCNAV_FC_SUBSCRIPTION_GPS_POSITION_STRUCT for information about data structure.
     * @datastruct CHCNAV_FC_SUBSCRIPTION_GPS_POSITION_STRUCT
     */
    CHCNAV_FC_SUBSCRIPTION_TOPIC_GPS_POSITION = 15,
    /*!
     * @brief Flight status topic name. Please refer to ::CHCNAV_FC_SUBSCRIPTION_FLIGHT_STATUS_E for information about data structure.
     * @datastruct CHCNAV_FC_SUBSCRIPTION_FLIGHT_STATUS_E
     */
    CHCNAV_FC_SUBSCRIPTION_TOPIC_STATUS_FLIGHT = 28,
    /*!
     * @brief Aircraft attitude topic name. Please refer to ::CHCNAV_FC_SUBSCRIPTION_ATTITUDE_STRUCT for information about data structure.
     * @datastruct CHCNAV_FC_SUBSCRIPTION_ATTITUDE_STRUCT
     */
    CHCNAV_FC_SUBSCRIPTION_TOPIC_ATTITUDE = 50,
} CHCNAV_FC_SUBSCRIPTION_TOPIC_E;
  ```
### CHCNAV_FC_SUBSCRIPTION_FLIGHT_STATUS_E
  UAV status information.
  ```
    typedef enum {
        CHCNAV_FC_SUBSCRIPTION_FLIGHT_STATUS_STOPED = 0, /* Aircraft is on the ground. */
        CHCNAV_FC_SUBSCRIPTION_FLIGHT_STATUS_IN_AIR = 2, /* Aircraft is taking off or in the air. */
    } CHCNAV_FC_SUBSCRIPTION_FLIGHT_STATUS_E;
  ```

## Struct
### CHCNAV_FC_SUBSCRIPTION_VELOCITY_STRUCT
  Velocity information.
  ```
    typedef CHCNAV_VECTOR_3F_STRUCT CHCNAV_FC_SUBSCRIPTION_VELOCITY_STRUCT;
  ```
### CHCNAV_FC_SUBSCRIPTION_POSITION_FUSED_STRUCT
  Fused position information.
  ```
    typedef struct {
        chcnav_f64_t longitude; /* Longitude, unit: rad. */
        chcnav_f64_t latitude; /* Latitude, unit: rad. */
        chcnav_f32_t altitude; /* Altitude above the WGS 84 ellipsoid, unit: m. */
        uint16_t visible_satellite_number; /* Number of visible satellites. */
    } CHCNAV_FC_SUBSCRIPTION_POSITION_FUSED_STRUCT;
  ```
### CHCNAV_FC_SUBSCRIPTION_GPS_TIME_STRUCT
  GPS time. This time is not adjusted for time zone or daylight saving time.
  ```
    typedef struct {
        uint32_t year;
        uint32_t month;
        uint32_t day;
        uint32_t hour;
        uint32_t minute;
        uint32_t second;
    } CHCNAV_FC_SUBSCRIPTION_GPS_TIME_STRUCT;
  ```
### CHCNAV_FC_SUBSCRIPTION_GPS_POSITION_STRUCT
  GPS position information.
  ```
    typedef struct {
        chcnav_f64_t longitude; /* Longitude, unit: rad. */
        chcnav_f64_t latitude; /* Latitude, unit: rad. */
        chcnav_f32_t altitude; /* Altitude above the WGS 84 ellipsoid, unit: m. */
    } CHCNAV_FC_SUBSCRIPTION_GPS_POSITION_STRUCT;
  ```
### CHCNAV_FC_SUBSCRIPTION_BATTERY_INFO_STRUCT
  Battery information.
  ```
    typedef struct {
        uint32_t capacity; /* Battery capacity, unit: mAh. */
        int32_t voltage; /* Battery voltage, unit: mV. */
        int32_t current; /* Battery current, unit: mA. */
        uint8_t percentage; /* Battery capacity percentage, unit: 1%. */
    } CHCNAV_FC_SUBSCRIPTION_BATTERY_INFO_STRUCT;
  ```
### CHCNAV_FC_SUBSCRIPTION_ATTITUDE_STRUCT
  UAV attitude information.
   ```
    typedef struct {
    chcnav_f32_t roll;         /* Roll angle, unit: rad. */
    chcnav_f32_t pitch;        /* Pitch angle, unit: rad. */
    chcnav_f32_t yaw;          /* Yaw angle, unit: rad. */
    chcnav_f32_t roll_speed;   /* Roll angular speed, unit: rad/s. */
    chcnav_f32_t pitch_speed;  /* Pitch angular speed, unit: rad/s. */
    chcnav_f32_t yaw_speed;    /* Yaw angular speed, unit: rad/s. */
    } CHCNAV_FC_SUBSCRIPTION_ATTITUDE_STRUCT;
  ```

## Function
### chcnav_fc_subscription_init
  **Function**: Initialize the data subscription module.
  > Note: Call this interface to initialize the data subscription module before subscribing to UAV data.
  The payload module or control-side module must be initialized before calling this interface; otherwise, data subscription module initialization will fail.

  ```
    chcnav_return_code_t chcnav_fc_subscription_init(void);
  ```
  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_fc_subscription_deInit
  **Function**: Deinitialize the data subscription module.
  ```
    chcnav_return_code_t chcnav_fc_subscription_deInit(void);
  ```
  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_fc_subscription_subscribe_topic
  **Function**: Subscribe to data.
  > Note:
   Duplicate subscriptions are not allowed.
   Subscription frequency must not exceed the maximum allowed rate.
   No more than 4 topic types may be subscribed at once.

  ```
   chcnav_return_code_t chcnav_fc_subscription_subscribe_topic(CHCNAV_FC_SUBSCRIPTION_TOPIC_E topic,
                                                 CHCNAV_SUBSCRIPTION_TOPIC_FREQ_E frequency,
                                                 CHCNAV_RECEIVE_DATA_OF_TOPIC_CALLBACK callback);
  ```
  **Parameters**
  * topic: Topic type to subscribe to.
  * frequency: Subscription frequency.
  * callback: Callback for receiving subscribed data. Set to NULL if no callback is needed.
  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_fc_subscription_unsubscribe_topic
  **Function**: Unsubscribe from data.
  ```
   chcnav_return_code_t chcnav_fc_subscription_unsubscribe_topic(CHCNAV_FC_SUBSCRIPTION_TOPIC_E topic);
  ```
  **Parameters**
  * topic: Topic type to unsubscribe from.
  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
### chcnav_fc_subscription_get_latest_value_of_topic
  **Function**: Get the latest subscribed data and timestamp.
  > Note: Ensure the data has been subscribed before calling this interface; otherwise it will return failure.
  ```
   chcnav_return_code_t chcnav_fc_subscription_get_latest_value_of_topic(CHCNAV_FC_SUBSCRIPTION_TOPIC_E topic,
                                                        uint8_t *data, uint16_t data_size_of_topic,
                                                        CHCNAV_TIMESTAMP_STRUCT *timestamp);
  ```
  **Parameters**
  * topic: Topic type to subscribe to.
  * data: Buffer for storing subscribed data.
  * data_size_of_topic: Size of the buffer for subscribed data. Under normal circumstances, this value equals the length of the subscribed item.
  * timestamp: Buffer for storing the timestamp. Set to NULL if the timestamp is not needed.
  **Return Value**: Returns the corresponding value based on execution result. See `CHCNAV_ERROR_CODE_E` for details.
