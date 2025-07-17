#include "test_camera_manager.h"
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include "chcnav_core.h"
#include "chcnav_camera_manager.h"
#include "chcnav_error.h"

using namespace std;

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

static const char *g_cameraManagerSampleSelectList[] = {
    [CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SET_CAMERA_EXPOSURE_MODE]       = "Set camera exposure mode                            |",
    [CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SET_CAMERA_SHUTTER_SPEED]       = "Set camera shutter speed                            |",
    [CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SET_CAMERA_APERTURE]            = "Set camera aperture                                 |",
    [CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SET_CAMERA_EV]                  = "Set camera ev                                       |",
    [CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SET_CAMERA_ISO]                 = "Set camera iso                                      |",
    [CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_ZOOM]                           = "camera zoom                                         |",
    [CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SHOOT_SINGLE_PHOTO]             = "Shoot single photo                                  |",
    [CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SHOOT_INTERVAL_PHOTO]           = "Shoot interval photo                                |",
    [CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_RECORD_VIDEO]                   = "Record video                                        |",
    [CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SHOW_STORAGE_INFO]              = "Show storage info                                   |",
    [CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_FORMAT_SD_CARD]                 = "Format SD card                                      |",
    [CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_RESET_CAMERA_SETTINGS]          = "Reset camera settings                               |",
    [CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SET_METERING_MODE]              = "Set camera metering mode                            |",
    [CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SET_METERING_POINT]             = "Set and get camera metering point                   |",
};

static void chcnav_camare_manager_show_string_list(const char **list, int size)
{
    for (int i = 0; i < size; i++) {
        printf("| [%2d] %s\r\n", i, list[i]);
    }
}

static void chcnav_camare_manager_show_sample_list(void)
{
    chcnav_camare_manager_show_string_list(g_cameraManagerSampleSelectList,
                                       ARRAY_SIZE(g_cameraManagerSampleSelectList));
}

chcnav_return_code_t test_camera_manager_start_single_photo(CHCNAV_MOUNT_POSITION_E position)
{
    chcnav_return_code_t ret;

    ret = chcnav_camera_manager_set_mode(position, CHCNAV_CAMERA_MANAGER_WORK_MODE_SHOOT_PHOTO);
    if (ret != CHCNAV_RETURN_OK) {
        printf("Set mounted position %d camera's work mode failed, error code: %d\r\n", position, ret);
        return ret;
    }

    return chcnav_camera_manager_start_shoot_photo(position, CHCNAV_CAMERA_MANAGER_SHOOT_PHOTO_MODE_SINGLE);
}

chcnav_return_code_t test_camera_manager_start_interval_photo(CHCNAV_MOUNT_POSITION_E position)
{
    chcnav_return_code_t ret;
    CHCNAV_CAMERA_PHOTO_TIME_INTERVAL_SETTINGS_STRUCT setting;

    printf("Set work mode as shoot photo mode...\n");
    ret = chcnav_camera_manager_set_mode(position, CHCNAV_CAMERA_MANAGER_WORK_MODE_SHOOT_PHOTO);
    if (ret != CHCNAV_RETURN_OK) {
        printf("Set mounted position %d camera's work mode failed, error code: %d\r\n", position, ret);
        return ret;
    }

    setting.capture_count = 5;
    setting.time_interval_seconds = 2;
    printf("Set shoot photo mode interval param...\n");
    ret = chcnav_camera_manager_set_photo_time_interval_settings(position, setting);
    if (ret != CHCNAV_RETURN_OK) {
        printf("Set mounted position %d camera's photo interval failed, error code: %d\r\n", position, ret);
        return ret;
    }

    return chcnav_camera_manager_start_shoot_photo(position, CHCNAV_CAMERA_MANAGER_SHOOT_PHOTO_MODE_INTERVAL);
}

chcnav_return_code_t test_camera_manager_start_video_record(CHCNAV_MOUNT_POSITION_E position)
{
    chcnav_return_code_t ret;

    ret = chcnav_camera_manager_set_mode(position, CHCNAV_CAMERA_MANAGER_WORK_MODE_RECORD_VIDEO);
    if (ret != CHCNAV_RETURN_OK) {
        printf("Set mounted position %d camera's work mode failed, error code: %d\r\n", position, ret);
        return ret;
    }

    return chcnav_camera_manager_start_record_video(position);
}

void run_camera_manager_sample(CHCNAV_MOUNT_POSITION_E position, CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_E sample)
{
    chcnav_return_code_t ret;
    CHCNAV_OSAL_HANDLER_STRUCT *osal_handler = chcnav_platform_get_osal_handler();
    switch(sample)
    {
        case CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SET_CAMERA_EXPOSURE_MODE:
        {
            CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_E mode;
            printf("--> Function: Set camera exposure mode to manual...\n");
            ret = chcnav_camera_manager_get_exposure_mode(position, &mode);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Get mounted position %d camera's exposure mode failed, error code: %d\r\n", position, ret);
                return;
            }

            mode = CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_EXPOSURE_MANUAL;
            ret = chcnav_camera_manager_set_exposure_mode(position, mode);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Set mounted position %d camera's exposure mode failed, error code: %d\r\n", position, ret);
            }
            break;
        }
        case CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SET_CAMERA_SHUTTER_SPEED:
        {
            CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_E shutter = CHCNAV_CAMERA_MANAGER_SHUTTER_SPEED_1_100;
            printf("--> Function: Set camera shutter speed to 1/100 s...\n");
            ret = chcnav_camera_manager_set_exposure_mode(position, CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_EXPOSURE_MANUAL);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Set mounted position %d camera's exposure mode failed, error code: %d\r\n", position, ret);
                return;
            }
            ret = chcnav_camera_manager_set_shutter_speed(position, shutter);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Set mounted position %d camera's shutter speed failed, error code: %d\r\n", position, ret);
            }
            break;
        }
        case CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SET_CAMERA_APERTURE:
        {
            CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_E mode;
            printf("--> Function: Set camera aperture to 2.0...\n");
            mode = CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_EXPOSURE_MANUAL;
            ret = chcnav_camera_manager_set_exposure_mode(position, mode);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Set mounted position %d camera's exposure mode failed, error code: %d\r\n", position, ret);
                return;
            }
            ret = chcnav_camera_manager_set_aperture(position, CHCNAV_CAMERA_MANAGER_APERTURE_F_2);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Set mounted position %d camera's aperture failed, error code: %d\r\n", position, ret);
                return;
            }
            break;
        }
        case CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SET_CAMERA_EV:
        {
            CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_E mode;
            printf("--> Function: Set camera EV to 1.0...\n");
            mode = CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_PROGRAM_AUTO;
            ret = chcnav_camera_manager_set_exposure_mode(position, mode);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Set mounted position %d camera's exposure mode failed, error code: %d\r\n", position, ret);
                return;
            }
            ret = chcnav_camera_manager_set_exposure_compensation(position, CHCNAV_CAMERA_MANAGER_EXPOSURE_COMPENSATION_P_1_0);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Set mounted position %d camera's EV failed, error code: %d\r\n", position, ret);
                return;
            }
            break;
        }
        case CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SET_CAMERA_ISO:
        {
            CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_E mode;
            printf("--> Function: Set camera ISO to 400...\n");
            mode = CHCNAV_CAMERA_MANAGER_EXPOSURE_MODE_EXPOSURE_MANUAL;
            ret = chcnav_camera_manager_set_exposure_mode(position, mode);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Set mounted position %d camera's exposure mode failed, error code: %d\r\n", position, ret);
                return;
            }
            ret = chcnav_camera_manager_set_ISO(position, CHCNAV_CAMERA_MANAGER_ISO_400);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Set mounted position %d camera's ISO failed, error code: %d\r\n", position, ret);
                return;
            }
            break;
        }
        case CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_ZOOM:
        {
            printf("--> Function: camera zoom...\n");
            ret = chcnav_camera_manager_start_continuous_zoom(position, CHCNAV_CAMERA_ZOOM_DIRECTION_IN);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Set mounted position %d camera's zoom in failed, error code: %d\r\n", position, ret);
                return;
            }
            osal_handler->task_sleep_ms(5000);
            ret = chcnav_camera_manager_stop_continuous_zoom(position);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Set mounted position %d camera's stop zoom failed, error code: %d\r\n", position, ret);
                return;
            }
            osal_handler->task_sleep_ms(1000);
            ret = chcnav_camera_manager_start_continuous_zoom(position, CHCNAV_CAMERA_ZOOM_DIRECTION_OUT);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Set mounted position %d camera's zoom out failed, error code: %d\r\n", position, ret);
                return;
            }
            osal_handler->task_sleep_ms(5000);
            ret = chcnav_camera_manager_stop_continuous_zoom(position);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Set mounted position %d camera's stop zoom failed, error code: %d\r\n", position, ret);
                return;
            }
            break;
        }
        case CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SHOOT_SINGLE_PHOTO:
        {
            printf("--> Function: Shoot Single photo...\n");
            ret = test_camera_manager_start_single_photo(position);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Start mounted position %d camera's single photo failed, error code: %d\r\n", position, ret);
                return;
            }
            break;
        }
        case CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SHOOT_INTERVAL_PHOTO:
        {
            printf("--> Function: Shoot Interval photo...\n");
            ret = test_camera_manager_start_interval_photo(position);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Start mounted position %d camera's Interval photo failed, error code: %d\r\n", position, ret);
                return;
            }
            osal_handler->task_sleep_ms(10*1000);
            ret = chcnav_camera_manager_stop_shoot_photo(position);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Stop mounted position %d camera's Interval photo failed, error code: %d\r\n", position, ret);
                return;
            }
            break;
        }
        case CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_RECORD_VIDEO:
        {
            printf("--> Function: recording...\n");
            ret = test_camera_manager_start_video_record(position);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Start mounted position %d camera's record failed, error code: %d\r\n", position, ret);
                return;
            }
            osal_handler->task_sleep_ms(10*1000);
            ret = chcnav_camera_manager_stop_record_video(position);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Stop mounted position %d camera's record failed, error code: %d\r\n", position, ret);
                return;
            }
            break;
        }
        case CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SHOW_STORAGE_INFO:
        {
            CHCNAV_CAMERA_MANAGER_STORAGE_INFO_STRUCT storage_info;
            printf("--> Function: Get storage info...\n");
            ret = chcnav_camera_manager_get_storage_info(position, &storage_info);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Start mounted position %d camera's record failed, error code: %d\r\n", position, ret);
                return;
            }
            printf("total capacity: %d, remainCapcity: %d", storage_info.total_capacity, storage_info.remain_capacity);
            break;
        }
        case CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_FORMAT_SD_CARD:
        {
            printf("--> Function: Format SD Card...\n");
            ret = chcnav_camera_manager_format_storage(position);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Start mounted position %d camera's format SD Card failed, error code: %d\r\n", position, ret);
                return;
            }
            printf("--> Function: Format SD Card successfully...\n");
            break;
        }
        case CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_RESET_CAMERA_SETTINGS:
        {
            printf("--> Function: Reset camera setting...\n");
            ret = chcnav_camera_manager_reset_camera_settings(position);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Start mounted position %d camera's reset setting failed, error code: %d\r\n", position, ret);
                return;
            }
            printf("--> Function: Reset camera setting successfully...\n");
            break;
        }
        case CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SET_METERING_MODE:
        {
            CHCNAV_CAMERA_MANAGER_METERING_MODE_E mode;
            printf("--> Function: Set metering mode...\n");
            mode = CHCNAV_CAMERA_MANAGER_METERING_MODE_AVERAGE;
            ret = chcnav_camera_manager_set_metering_mode(position, mode);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Set mounted position %d camera's metering mode failed, error code: %d\r\n", position, ret);
                return;
            }
            ret = chcnav_camera_manager_get_metering_mode(position, &mode);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Get mounted position %d camera's metering mode failed, error code: %d\r\n", position, ret);
                return;
            }
            printf("current metering mode is :%d\n", mode);
            break;
        }
        case CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SET_METERING_POINT:
        {
            uint8_t hrz_num;
            uint8_t vtc_num;
            uint8_t x, y;
            printf("--> Function: Set spot metering mode point...\n");
            ret = chcnav_camera_manager_set_metering_mode(position, CHCNAV_CAMERA_MANAGER_METERING_MODE_SPOT);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Set mounted position %d camera's metering mode failed, error code: %d\r\n", position, ret);
                return;
            }
            ret = chcnav_camera_manager_get_metering_point_region_range(position, &hrz_num, &vtc_num);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Get mounted position %d camera's spot metering mode range failed, error code: %d\r\n", position, ret);
                return;
            }

            printf("region range: horizon %u, vitical %u\n", hrz_num, vtc_num);
            printf("Input meterting point (x, y) you want to set: ");
            scanf("%hhu %hhu", &x, &y);

            printf("Try to set metering point as (%d, %d)", (uint8_t)x, (uint8_t)y);
            ret = chcnav_camera_manager_set_metering_point(position, x, y);
            if (ret != CHCNAV_RETURN_OK) {
                printf("Set mounted position %d camera's spot metering mode range failed, error code: %d\r\n", position, ret);
                return;
            }
            break;
        }
        default:
            printf("this test not support...\n");
            break;
    }
}

void chcnav_run_camera_manager_sample()
{
    string mountPositionStr;
    CHCNAV_MOUNT_POSITION_E cameraMountPosition;
    string sampleSelectStr;
    CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_E cameraSample;

    CHCNAV_OSAL_HANDLER_STRUCT *osal_handler = chcnav_platform_get_osal_handler();
    printf("chcnav_run_camera_manager_sample...\n");
    while(true)
    {
        cout
            << "| Available position:                                                                              |"
            <<
            endl;
        cout
            << "| [1] Select camera mount position at NO.1 payload port                                            |"
            <<
            endl;
        cout
            << "| [2] Select camera mount position at NO.2 payload port                                            |"
            <<
            endl;
        cout
            << "| [3] Select camera mount position at NO.3 payload port                                            |"
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

        cameraMountPosition = static_cast<CHCNAV_MOUNT_POSITION_E>(atoi(mountPositionStr.c_str()));
        if (cameraMountPosition > CHCNAV_MOUNT_POSITION_PAYLOAD_PORT_NO3 || cameraMountPosition < CHCNAV_MOUNT_POSITION_PAYLOAD_PORT_NO1) {
            printf("Input mount position is invalid");
            continue;
        } else {
            break;
        }
    }

    bool connect_status = false;
    uint32_t connect_count = 0;
    CHCNAV_CAMERA_E camera_type;
    CHCNAV_CAMERA_MANAGER_FIRMWARE_VERSION_STRUCT version;

    printf("--> Step 1: Init camera manager module\n");
    chcnav_return_code_t ret = chcnav_camera_manager_init();
    if (ret != CHCNAV_RETURN_OK)
    {
        printf("Init camera manager failed, error code: %d\r\n", ret);
        return;
    }

    while(!connect_status)
    {
        connect_count++;
        printf("Waiting for the camera to connect.\n");
        chcnav_camera_manager_get_camera_connect_status(cameraMountPosition, &connect_status);
        if (connect_count > 10)
        {
            printf("can not connect to cameras...\n");
            goto ExitCameraManager;
        }
        osal_handler->task_sleep_ms(1000);
    }
    
    printf("--> Step 2: Get camera type and version\n");
    ret = chcnav_camera_manager_get_camera_type(cameraMountPosition, &camera_type);
    if (ret != CHCNAV_RETURN_OK)
    {
        printf("Get mounted position %d camera's type failed, error code: %d\r\n", cameraMountPosition, ret);
        goto ExitCameraManager;
    }
    ret = chcnav_camera_manager_get_firmware_version(cameraMountPosition, &version);
    if (ret != CHCNAV_RETURN_OK) {
        printf("Get mounted position %d camera's firmware version failed, error code: %d\r\n", cameraMountPosition, ret);
        goto ExitCameraManager;
    }
    printf("Mounted position %d camera's firmware is V%02d.%02d.%02d.%02d\r\n", cameraMountPosition,
                  version.firmware_version[0], version.firmware_version[1],
                  version.firmware_version[2], version.firmware_version[3]);
    while(true)
    {
        chcnav_camare_manager_show_sample_list();
        std::cout << "Please input number to select sample (input q to quit): ";
        std::cin >> sampleSelectStr;

        if (sampleSelectStr == "q") {
            goto ExitCameraManager;
        }

        cameraSample = (CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_E)atoi(sampleSelectStr.c_str());

        if (cameraSample < CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_SET_CAMERA_EXPOSURE_MODE ||
            cameraSample >= CHCNAV_TEST_CAMERA_MANAGER_SAMPLE_SELECT_INDEX_MAX) {
            printf("Input camera sample is invalid\n\n");
            continue;
        }
        printf("Camera manager sample start, cameraManagerSampleSelect %d\r\n", cameraSample);
        run_camera_manager_sample(cameraMountPosition, cameraSample);
    }
ExitCameraManager:
    chcnav_camera_manager_deinit();
    printf("Camera manager sample end\n\n");
}