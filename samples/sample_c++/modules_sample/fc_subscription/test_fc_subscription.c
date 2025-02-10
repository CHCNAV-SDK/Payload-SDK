#include "test_fc_subscription.h"
#include "chcnav_platform.h"

static chcnav_return_code_t test_fc_subscription_velocity_cb(const uint8_t *data, uint16_t data_size, const CHCNAV_TIMESTAMP_STRUCT *timestamp)
{
    CHCNAV_FC_SUBSCRIPTION_VELOCITY_STRUCT *velocity = (CHCNAV_FC_SUBSCRIPTION_VELOCITY_STRUCT *)data;
    printf("velocity:%f, %f %f\n", velocity->x, velocity->y, velocity->z);
    return CHCNAV_RETURN_OK;
}

static chcnav_return_code_t test_fc_subscription_position_fused_cb(const uint8_t *data, uint16_t data_size, const CHCNAV_TIMESTAMP_STRUCT *timestamp)
{
    CHCNAV_FC_SUBSCRIPTION_POSITION_FUSED_STRUCT *position_fused = (CHCNAV_FC_SUBSCRIPTION_POSITION_FUSED_STRUCT *)data;
    printf("position:%f, %f %f\n", position_fused->latitude, position_fused->longitude, position_fused->altitude);
    return CHCNAV_RETURN_OK;
}

static chcnav_return_code_t test_fc_subscription_gps_time_cb(const uint8_t *data, uint16_t data_size, const CHCNAV_TIMESTAMP_STRUCT *timestamp)
{
    CHCNAV_FC_SUBSCRIPTION_GPS_TIME_STRUCT *gps_time = (CHCNAV_FC_SUBSCRIPTION_GPS_TIME_STRUCT *)data;
    printf("gps time:%u-%u-%u %u:%u:%u\n",
            gps_time->year, gps_time->month, gps_time->day, gps_time->hour, gps_time->minute, gps_time->second);
    return CHCNAV_RETURN_OK;
}

static chcnav_return_code_t test_fc_subscription_gps_pos_cb(const uint8_t *data, uint16_t data_size, const CHCNAV_TIMESTAMP_STRUCT *timestamp)
{
    CHCNAV_FC_SUBSCRIPTION_GPS_POSITION_STRUCT *gps_pos = (CHCNAV_FC_SUBSCRIPTION_GPS_POSITION_STRUCT *)data;
    printf("gps pos:%f %f %f\n",
            gps_pos->latitude, gps_pos->longitude, gps_pos->altitude);
    return CHCNAV_RETURN_OK;
}

static chcnav_return_code_t test_fc_subscription_attitude_cb(const uint8_t *data, uint16_t data_size, const CHCNAV_TIMESTAMP_STRUCT *timestamp)
{
    CHCNAV_FC_SUBSCRIPTION_ATTITUDE_STRUCT *attitude = (CHCNAV_FC_SUBSCRIPTION_ATTITUDE_STRUCT *)data;
    printf("flight attitude -> roll:%f, pitch:%f yaw:%f,roll speed:%f, pitch speed:%f, yaw speed:%f\n",
        attitude->roll, attitude->pitch, attitude->yaw,
        attitude->roll_speed, attitude->pitch_speed, attitude->yaw_speed);
    return CHCNAV_RETURN_OK;
}

void chcnav_run_fc_subscription_sample()
{
    chcnav_return_code_t ret;

    CHCNAV_OSAL_HANDLER_STRUCT *osal_handler = chcnav_platform_get_osal_handler();
    ret = chcnav_fc_subscription_init();
    if (ret != CHCNAV_RETURN_OK)
    {
        printf("init fc subscription module failed\n");
        return;
    }

    /*ret = chcnav_fc_subscription_subscribe_topic(CHCNAV_FC_SUBSCRIPTION_TOPIC_VELOCITY,
                                CHCNAV_SUBSCRIPTION_TOPIC_1_HZ, test_fc_subscription_velocity_cb);
    if (ret != CHCNAV_RETURN_OK)
    {
        printf("subscription velocity topic failed\n");
    }*/

    ret = chcnav_fc_subscription_subscribe_topic(CHCNAV_FC_SUBSCRIPTION_TOPIC_POSITION_FUSED,
                                CHCNAV_SUBSCRIPTION_TOPIC_1_HZ, test_fc_subscription_position_fused_cb);
    if (ret != CHCNAV_RETURN_OK)
    {
        printf("subscription velocity position fused failed\n");
    }

    ret = chcnav_fc_subscription_subscribe_topic(CHCNAV_FC_SUBSCRIPTION_TOPIC_GPS_TIME,
                                CHCNAV_SUBSCRIPTION_TOPIC_1_HZ, test_fc_subscription_gps_time_cb);
    if (ret != CHCNAV_RETURN_OK)
    {
        printf("subscription velocity gps time failed\n");
    }

    ret = chcnav_fc_subscription_subscribe_topic(CHCNAV_FC_SUBSCRIPTION_TOPIC_GPS_POSITION,
                                CHCNAV_SUBSCRIPTION_TOPIC_1_HZ, test_fc_subscription_gps_pos_cb);
    if (ret != CHCNAV_RETURN_OK)
    {
        printf("subscription velocity gps position failed\n");
    }

    ret = chcnav_fc_subscription_subscribe_topic(CHCNAV_FC_SUBSCRIPTION_TOPIC_ATTITUDE,
                                CHCNAV_SUBSCRIPTION_TOPIC_1_HZ, test_fc_subscription_attitude_cb);
    if (ret != CHCNAV_RETURN_OK)
    {
        printf("subscription velocity topic failed\n");
    }

    osal_handler->task_sleep_ms(10 * 1000);

    //chcnav_fc_subscription_unsubscribe_topic(CHCNAV_FC_SUBSCRIPTION_TOPIC_VELOCITY);
    chcnav_fc_subscription_unsubscribe_topic(CHCNAV_FC_SUBSCRIPTION_TOPIC_POSITION_FUSED);
    chcnav_fc_subscription_unsubscribe_topic(CHCNAV_FC_SUBSCRIPTION_TOPIC_GPS_TIME);
    chcnav_fc_subscription_unsubscribe_topic(CHCNAV_FC_SUBSCRIPTION_TOPIC_GPS_POSITION);
    chcnav_fc_subscription_unsubscribe_topic(CHCNAV_FC_SUBSCRIPTION_TOPIC_ATTITUDE);
    osal_handler->task_sleep_ms(2 * 1000);
    chcnav_fc_subscription_deInit();
}