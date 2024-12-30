#include "test_gimbal_manager.h"
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include "chcnav_core.h"
#include "chcnav_gimbal_manager.h"
#include "chcnav_error.h"

using namespace std;

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

static const char *g_gimbalManagerSampleSelectList[] = {
    [CHCNAV_TEST_GIMBAL_MANAGER_SAMPLE_SELECT_GIMBAL_MODE]              = "Set gimbal work mode                            |",
    [CHCNAV_TEST_GIMBAL_MANAGER_SAMPLE_SELECT_GIMBAL_RESET_MODE]        = "Set gimbal reset mode                          |",
    [CHCNAV_TEST_GIMBAL_MANAGER_SAMPLE_SELECT_GIMBAL_ROTATE]            = "Set gimbal rotate                               |",
    [CHCNAV_TEST_GIMBAL_MANAGER_SAMPLE_SELECT_GIMBAL_FACTORY]           = "Set gimbal factory                              |",
};

typedef enum {
    TEST_GIMBAL_MANAGER_ROTATE = 0,
    TEST_GIMBAL_MANAGER_RESET,
} TEST_GIMBAL_MANAGER_E;

typedef struct {
    TEST_GIMBAL_MANAGER_E action;
    CHCNAV_GIMBAL_MANAGER_ROTATION_STRUCT rotate;
} TEST_GIMBAL_MANAGER_ROTATE_ST;

static const TEST_GIMBAL_MANAGER_ROTATE_ST g_rotate_list[] =
{
    {.action = TEST_GIMBAL_MANAGER_RESET},
    {.action = TEST_GIMBAL_MANAGER_ROTATE, 30,  0,   0},
    {.action = TEST_GIMBAL_MANAGER_ROTATE, -30, 0,   0},
    {.action = TEST_GIMBAL_MANAGER_ROTATE, 0,   30,  0},
    {.action = TEST_GIMBAL_MANAGER_ROTATE, 0,   -30, 0},
    {.action = TEST_GIMBAL_MANAGER_ROTATE, 0,   0,   30},
    {.action = TEST_GIMBAL_MANAGER_ROTATE, 0,   0,   -30},
    {.action = TEST_GIMBAL_MANAGER_RESET},
};

static void chcnav_gimbal_manager_show_string_list(const char **list, int size)
{
    for (int i = 0; i < size; i++) {
        printf("| [%2d] %s\r\n", i, list[i]);
    }
}

static void chcnav_gimbal_manager_show_sample_list(void)
{
    chcnav_gimbal_manager_show_string_list(g_gimbalManagerSampleSelectList,
                                       ARRAY_SIZE(g_gimbalManagerSampleSelectList));
}

void run_gimbal_manager_sample(CHCNAV_MOUNT_POSITION_E position, CHCNAV_TEST_GIMBAL_MANAGER_SAMPLE_E sample)
{
    chcnav_return_code_t ret;
    CHCNAV_OSAL_HANDLER_STRUCT *osal_handler = chcnav_platform_get_osal_handler();
    switch(sample)
    {
        case CHCNAV_TEST_GIMBAL_MANAGER_SAMPLE_SELECT_GIMBAL_MODE:
        {
            printf("--> Function: Set gimbal mode to LOCK...\n");
            ret = chcnav_gimbal_manager_set_mode(position, CHCNAV_GIMBAL_MODE_LOCK);
            if (ret != CHCNAV_RETURN_OK)
            {
                printf("set gimbal mode to lock mdoe fialed.\n");
            }
            osal_handler->task_sleep_ms(2 * 1000);
            printf("--> Function: Set gimbal mode to FOLLOW...\n");
            ret = chcnav_gimbal_manager_set_mode(position, CHCNAV_GIMBAL_MODE_YAW_FOLLOW);
            if (ret != CHCNAV_RETURN_OK)
            {
                printf("set gimbal mode to follow mdoe fialed.\n");
            }
            osal_handler->task_sleep_ms(2 * 1000);
            break;
        }
        case CHCNAV_TEST_GIMBAL_MANAGER_SAMPLE_SELECT_GIMBAL_RESET_MODE:
        {
            printf("--> Function: Set gimbal reset mode to YAW...\n");
            ret = chcnav_gimbal_manager_reset(position, CHCNAV_GIMBAL_RESET_MODE_YAW);
            if (ret != CHCNAV_RETURN_OK)
            {
                printf("set gimbal reset mode to yaw fialed.\n");
            }
            osal_handler->task_sleep_ms(2 * 1000);
            printf("--> Function: Set gimbal reset mode to YAW and PITCH downward...\n");
            ret = chcnav_gimbal_manager_reset(position, CHCNAV_GIMBAL_RESET_MODE_PITCH_DOWNWARD_UPWARD_AND_YAW);
            if (ret != CHCNAV_RETURN_OK)
            {
                printf("set gimbal reset mode to yaw and pitch downward fialed.\n");
            }
            osal_handler->task_sleep_ms(2 * 1000);
            printf("--> Function: Set gimbal reset mode to YAW and PITCH...\n");
            ret = chcnav_gimbal_manager_reset(position, CHCNAV_GIMBAL_RESET_MODE_PITCH_AND_YAW);
            if (ret != CHCNAV_RETURN_OK)
            {
                printf("set gimbal reset mode to pitch and yaw fialed.\n");
            }
            osal_handler->task_sleep_ms(2 * 1000);
            printf("--> Function: Set gimbal reset mode to PITCH downward...\n");
            ret = chcnav_gimbal_manager_reset(position, CHCNAV_GIMBAL_RESET_MODE_PITCH_DOWNWARD_UPWARD);
            if (ret != CHCNAV_RETURN_OK)
            {
                printf("set gimbal reset mode to pitch downward fialed.\n");
            }
            osal_handler->task_sleep_ms(2 * 1000);
            break;
        }
        case CHCNAV_TEST_GIMBAL_MANAGER_SAMPLE_SELECT_GIMBAL_ROTATE:
        {
            for (int i = 0; i < ARRAY_SIZE(g_rotate_list); i++)
            {
                
                if (g_rotate_list[i].action == TEST_GIMBAL_MANAGER_ROTATE)
                {
                    CHCNAV_GIMBAL_MANAGER_ROTATION_STRUCT rotate;
                    memcpy(&rotate, &g_rotate_list[i].rotate, sizeof(CHCNAV_GIMBAL_MANAGER_ROTATION_STRUCT));
                    printf("--> Function: Set gimbal rotate:[%.1f %.1f %.1f]...\n", rotate.pitch, rotate.roll, rotate.yaw);
                    ret = chcnav_gimbal_manager_rorate(position, rotate);
                    if (ret != CHCNAV_RETURN_OK)
                    {
                        printf("set gimbal rotate fialed.\n");
                    }
                }
                else if (g_rotate_list[i].action == TEST_GIMBAL_MANAGER_RESET)
                {
                    printf("--> Function: Set gimbal reset...\n");
                    ret = chcnav_gimbal_manager_reset(position, CHCNAV_GIMBAL_RESET_MODE_PITCH_AND_YAW);
                    if (ret != CHCNAV_RETURN_OK)
                    {
                        printf("set gimbal reset mode to pitch and yaw fialed.\n");
                    }
                }
                osal_handler->task_sleep_ms(2 * 1000);
            }
            break;
        }
        case CHCNAV_TEST_GIMBAL_MANAGER_SAMPLE_SELECT_GIMBAL_FACTORY:
        {
            printf("--> Function: gimbal factory setting...\n");
            ret = chcnav_gimbal_manager_restore_factory_settings(position);
            if (ret != CHCNAV_RETURN_OK)
            {
                printf("set gimbal reset mode to pitch downward fialed.\n");
            }
            osal_handler->task_sleep_ms(8 * 1000);
            printf("--> Function: gimbal factory setting done...\n");
            break;
        }
        default:
            printf("Unknown test sample..\n");
            break;
    }
}

void chcnav_run_gimbal_manager_sample()
{
    string mountPositionStr;
    CHCNAV_MOUNT_POSITION_E gimbalMountPosition;
    string sampleSelectStr;
    CHCNAV_TEST_GIMBAL_MANAGER_SAMPLE_E gimbalSample;

    printf("chcnav_run_gimbal_manager_sample...\n");
    while(true)
    {
        cout
            << "| Available position:                                                                              |"
            <<
            endl;
        cout
            << "| [1] Select gimbal mount position at NO.1 payload port                                            |"
            <<
            endl;
        cout
            << "| [2] Select gimbal mount position at NO.2 payload port                                            |"
            <<
            endl;
        cout
            << "| [3] Select gimbal mount position at NO.3 payload port                                            |"
            <<
            endl;
        cout
            << "| [q] Quit                                                                                         |"
            <<
            endl;

        cout << "Please input number to select position (input q to quit): ";
        cin >> mountPositionStr;
        if (mountPositionStr == "q") {
            return;
        }

        gimbalMountPosition = static_cast<CHCNAV_MOUNT_POSITION_E>(atoi(mountPositionStr.c_str()));
        if (gimbalMountPosition > CHCNAV_MOUNT_POSITION_PAYLOAD_PORT_NO3 || gimbalMountPosition < CHCNAV_MOUNT_POSITION_PAYLOAD_PORT_NO1) {
            printf("Input mount position is invalid");
            continue;
        } else {
            break;
        }
    }

    bool connect_status = false;
    uint32_t connect_count = 0;

    printf("--> Step 1: Init gimbal manager module\n");
    chcnav_return_code_t ret = chcnav_gimbal_manager_init();
    if (ret != CHCNAV_RETURN_OK)
    {
        printf("Init gimbal manager failed, error code: %d\r\n", ret);
        return;
    }

    while(true)
    {
        chcnav_gimbal_manager_show_sample_list();
        std::cout << "Please input number to select sample (input q to quit): ";
        std::cin >> sampleSelectStr;

        if (sampleSelectStr == "q") {
            goto ExitGimbalManager;
        }

        gimbalSample = (CHCNAV_TEST_GIMBAL_MANAGER_SAMPLE_E)atoi(sampleSelectStr.c_str());

        if (gimbalSample < CHCNAV_TEST_GIMBAL_MANAGER_SAMPLE_SELECT_GIMBAL_MODE ||
            gimbalSample >= CHCNAV_TEST_GIMBAL_MANAGER_SAMPLE_SELECT_INDEX_MAX) {
            printf("Input gimbal sample is invalid\n\n");
            continue;
        }
        printf("Gimbal manager sample start, gimbalManagerSampleSelect %d\r\n", gimbalSample);
        run_gimbal_manager_sample(gimbalMountPosition, gimbalSample);
    }
ExitGimbalManager:
    chcnav_gimbal_manager_deinit();
    printf("Gimbal manager sample end\n\n");
}