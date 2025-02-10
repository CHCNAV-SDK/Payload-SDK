/********************************************************************************
 * Copyright (c) 2024 by Shanghai Huace Navigation Technology Ltd.
 * All rights reserved
 *
 * This file is part of chcnav psdk
 *
 * @file chcnav_fc_subscription.h
 * @brief This is the header file for "chcnav_fc_subscription.cpp",defining the
 *structure and (exported) function prototypes.
 ********************************************************************************/

#ifndef CHCNAV_FC_SUBSCRIPTION_H
#define CHCNAV_FC_SUBSCRIPTION_H

#include "chcnav_typedef.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Name of topics that can be subscribed.
 */
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

/**
 * @brief Flight status of aircraft.
 */
typedef enum {
    CHCNAV_FC_SUBSCRIPTION_FLIGHT_STATUS_STOPED = 0, /* Aircraft is on ground and motors are still. */
    CHCNAV_FC_SUBSCRIPTION_FLIGHT_STATUS_IN_AIR = 2, /* Aircraft is in air or taking off. */
} CHCNAV_FC_SUBSCRIPTION_FLIGHT_STATUS_E;

/**
 * @brief velocity topic data structure, unit: cm/s.
 */
typedef CHCNAV_VECTOR_3F_STRUCT CHCNAV_FC_SUBSCRIPTION_VELOCITY_STRUCT;

/**
 * @brief Fused position topic data structure.
 */
typedef struct {
    chcnav_f64_t longitude; /* Longitude, unit: rad. */
    chcnav_f64_t latitude; /* Latitude, unit: rad. */
    chcnav_f32_t altitude; /* Altitude, WGS 84 reference ellipsoid, unit: m. */
    uint16_t visible_satellite_number; /* Number of visible satellites. */
} CHCNAV_FC_SUBSCRIPTION_POSITION_FUSED_STRUCT;

/**
 * @brief Fused position topic data structure.
 */
typedef struct {
    uint32_t year;
    uint32_t month;
    uint32_t day;
    uint32_t hour;
    uint32_t minute;
    uint32_t second;
} CHCNAV_FC_SUBSCRIPTION_GPS_TIME_STRUCT;

/**
 * @brief Fused position topic data structure.
 */
typedef struct {
    chcnav_f64_t longitude; /* Longitude, unit: rad. */
    chcnav_f64_t latitude; /* Latitude, unit: rad. */
    chcnav_f32_t altitude; /* Altitude, WGS 84 reference ellipsoid, unit: m. */
} CHCNAV_FC_SUBSCRIPTION_GPS_POSITION_STRUCT;

/**
 * @brief Battery information topic data structure.
 */
typedef struct {
    uint32_t capacity; /* Battery capacity, unit: mAh. */
    int32_t voltage; /* Battery voltage, unit: mV. */
    int32_t current; /* Battery current, unit: mA. */
    uint8_t percentage; /* Battery capacity percentage, unit: 1%. */
} CHCNAV_FC_SUBSCRIPTION_BATTERY_INFO_STRUCT;

/**
 * @brief Aircraft attitude topic data structure.
 */
typedef struct {
 chcnav_f32_t roll;         /* Roll angle, unit: rad. */
 chcnav_f32_t pitch;        /* Pitch angle,unit: rad. */
 chcnav_f32_t yaw;          /* Yaw angleunit: rad. */
 chcnav_f32_t roll_speed;   /* Roll angular speed, unit: rad/s. */
 chcnav_f32_t pitch_speed;  /* Pitch angular speed, unit: rad/s. */
 chcnav_f32_t yaw_speed;    /* Yaw angular speed, unit: rad/s. */
} CHCNAV_FC_SUBSCRIPTION_ATTITUDE_STRUCT;

/**
 * @brief Initialise data subscription module. This function has to be called before subscribing any
 * data, to initialize run environment of data subscription module, if need to subscribe data from aircraft.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_fc_subscription_init(void);

/**
 * @brief Deinitialize data subscription module. When data subscription will no longer be used, can call this function
 * to deinitialize the data subscription module. Deinitialization function will help to release all system resource data
 * subscription has occupied.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_fc_subscription_deInit(void);

/**
 * @brief Subscribe a topic. Before subscribing any data from aircraft, chcnav_fc_subscription_init()
 * function has to be called.
 * @details User can subscribe a topic by specifying topic name, push frequency and callback function used to receive
 * data of topic (if needed). After subscribing successfully, the user can call
 * chcnav_fc_subscription_get_latest_value_of_topic() function to get the latest data of the topic have been
 * subscribed and the corresponding timestamp when aircraft sends the data out, and the callback function will be called to
 * push data of the topic and corresponding timestamp if the callback function is specified.
 * @warning Topic to be subscribed can not have been subscribed, that is, one topic can not be subscribed repeatedly.
 * @note User must ensure that types of subscription frequency of all topics have been subscribed is less than or
 * equal to 4. Otherwise, the subscribing topic will fail.
 * @note User must ensure that the data length sum of all topics of the same subscription frequency is less than or equal to 242.
 * @param topic: topic name to be subscribed.
 * @param frequency: subscription frequency of topic to be subscribed. Subscription frequency can not beyond max
 * frequency limitation of the topic and must be the value of enum CHCNAV_SUBSCRIPTION_TOPIC_FREQ_E. And, subscription
 * frequency has to be larger than 0. Different topics support different maximum subscription frequencies. 
 * Please check the document and set a reasonable subscription frequency.
 * @param callback: callback function used to receive data of topic to be subscribed. If the callback function is not needed,
 * this item can be set as NULL.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_fc_subscription_subscribe_topic(CHCNAV_FC_SUBSCRIPTION_TOPIC_E topic,
                                                 CHCNAV_SUBSCRIPTION_TOPIC_FREQ_E frequency,
                                                 CHCNAV_RECEIVE_DATA_OF_TOPIC_CALLBACK callback);

/**
 * @brief Unsubscribe a topic. Before unsubscribing any data from aircraft, chcnav_fc_subscription_init()
 * and chcnav_fc_subscription_subscribe_topic() function has to be called,
 * @details User can unsubscribe a topic by specifying topic name, but the topic must be unsubscribed in the order of subscription.
 * @note Topic to be unsubscribed must have been subscribed.
 * @note Topic to be unsubscribed must be in the order of subscription, similar to a queue, subscription is similar to enqueue,
 * unsubscription is similar to dequeue.
 * @param topic: topic name to be unsubscribed.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_fc_subscription_unsubscribe_topic(CHCNAV_FC_SUBSCRIPTION_TOPIC_E topic);

/**
 * @brief Get the latest data value and timestamp in aircraft time system when sending the data from aircraft of specified
 * topic. If the specified topic has not been subscribed successfully, this function will return the error code.
 * @note After calling this function, user need transfer type of data pointer that pointer to data of topic to
 * corresponding data structure pointer for getting every item of the topic conveniently.
 * @param topicName: topic name.
 * @param data: pointer to memory space used to store data of the topic. The memory space used to store data of topic
 * have to have been allocated correctly and should ensure its size is equal to data structure size corresponding to
 * the topic, otherwise, this function will not be able to return data and timestamp (return error code).
 * @param dataSizeOfTopic: the size of memory space used to store data of topic. Normally, this size is equal to data
 * structure size corresponding to the topic. If this size is not equal to the size of the memory space, may cause memory
 * overflow event
 * @param timestamp: pointer to memory space used to store timestamps. The memory space used to store timestamps
 * have to have been allocated correctly, and should ensure its size is equal to data structure size of timestamp,
 * otherwise, this function will not be able to return data and timestamp (return error code) or even cause memory
 * overflow event. If the user does not need timestamp information, can fill in NULL.
 * @return Execution result.
 */
chcnav_return_code_t chcnav_fc_subscription_get_latest_value_of_topic(CHCNAV_FC_SUBSCRIPTION_TOPIC_E topic,
                                                        uint8_t *data, uint16_t data_size_of_topic,
                                                        CHCNAV_TIMESTAMP_STRUCT *timestamp);
#ifdef __cplusplus
}
#endif
#endif //CHCNAV_FC_SUBSCRIPTION_H