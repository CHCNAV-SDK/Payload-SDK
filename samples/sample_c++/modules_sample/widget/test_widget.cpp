#include "test_widget.h"
#include "chcnav_logger.h"
#include "chcnav_platform.h"
#include "chcnav_widget.h"
#include <cstdio>
#include <cstring>

#ifndef SYSTEM_ARCH_LINUX
#include "file_binary_array_list_en.h"
#endif

#define WIDGET_DIR_PATH_LEN_MAX 512
#define WIDGET_LOG_STRING_MAX_SIZE 64
#define WIDGET_LOG_LINE_MAX_NUM 4

typedef struct {
    bool valid;
    char content[WIDGET_LOG_STRING_MAX_SIZE];
} TestWidgetLogLine;

static bool g_widget_started = false;
static char g_config_dir_path[WIDGET_DIR_PATH_LEN_MAX] = {0};
static int32_t g_widget_value_list[9] = {0};
static chcnav_task_handle_t g_widget_demo_thread = NULL;
static TestWidgetLogLine g_widget_log[WIDGET_LOG_LINE_MAX_NUM] = {{false, {0}}};

static const char *g_widget_type_name[] = {
    "Unknown",
    "Button",
    "Switch",
    "Scale",
    "List",
    "IntInput"
};

static chcnav_return_code_t test_widget_set_value(CHCNAV_WIDGET_TYPE_E widget_type,
                                                   uint32_t index,
                                                   int32_t value,
                                                   void *user_data)
{
    (void)user_data;
    CHCNAV_LOG_INFO(demo, "Set widget: widget_type=%d index=%u value=%d",
           static_cast<int>(widget_type), index, value);

    if (index >= sizeof(g_widget_value_list) / sizeof(g_widget_value_list[0])) {
        return CHCNAV_RETURN_ERR_PARAM;
    }

    const char *type_name = (widget_type <= CHCNAV_WIDGET_TYPE_INT_INPUT)
        ? g_widget_type_name[widget_type] : "Unknown";
    char log_line[WIDGET_LOG_STRING_MAX_SIZE];
    snprintf(log_line, sizeof(log_line), "Set widget: typ %s idx %u val %d",
             type_name, index, value);

    for (int i = 0; i < WIDGET_LOG_LINE_MAX_NUM; ++i) {
        if (!g_widget_log[i].valid) {
            g_widget_log[i].valid = true;
            snprintf(g_widget_log[i].content, sizeof(g_widget_log[i].content), "%s", log_line);
            break;
        }
    }

    g_widget_value_list[index] = value;
    return CHCNAV_RETURN_OK;
}

static chcnav_return_code_t test_widget_get_value(CHCNAV_WIDGET_TYPE_E widget_type,
                                                   uint32_t index,
                                                   int32_t *value,
                                                   void *user_data)
{
    (void)user_data;
    if (value == NULL || index >= sizeof(g_widget_value_list) / sizeof(g_widget_value_list[0])) {
        return CHCNAV_RETURN_ERR_PARAM;
    }

    *value = g_widget_value_list[index];

    CHCNAV_LOG_INFO(demo, "Get widget: widget_type=%d index=%u value=%d",
           static_cast<int>(widget_type), index, *value);

    return CHCNAV_RETURN_OK;
}

static const CHCNAV_WIDGET_HANDLER_LIST_ITEM_STRUCT g_widget_handler_list[] = {
    {0, CHCNAV_WIDGET_TYPE_BUTTON,     test_widget_set_value, test_widget_get_value, NULL},
    {1, CHCNAV_WIDGET_TYPE_LIST,       test_widget_set_value, test_widget_get_value, NULL},
    {2, CHCNAV_WIDGET_TYPE_SWITCH,     test_widget_set_value, test_widget_get_value, NULL},
    {3, CHCNAV_WIDGET_TYPE_SCALE,      test_widget_set_value, test_widget_get_value, NULL},
    {4, CHCNAV_WIDGET_TYPE_BUTTON,     test_widget_set_value, test_widget_get_value, NULL},
    {5, CHCNAV_WIDGET_TYPE_SCALE,      test_widget_set_value, test_widget_get_value, NULL},
    {6, CHCNAV_WIDGET_TYPE_INT_INPUT,  test_widget_set_value, test_widget_get_value, NULL},
    {7, CHCNAV_WIDGET_TYPE_SWITCH,     test_widget_set_value, test_widget_get_value, NULL},
    {8, CHCNAV_WIDGET_TYPE_LIST,       test_widget_set_value, test_widget_get_value, NULL},
};

#ifdef SYSTEM_ARCH_LINUX
static int get_dir_path_from_file_path(const char *file_path, char *dir_path, size_t dir_path_len)
{
    if (file_path == NULL || dir_path == NULL || dir_path_len == 0) {
        return -1;
    }

    size_t len = strlen(file_path);
    if (len == 0) {
        return -1;
    }

    size_t i = len;
    while (i > 0) {
        --i;
        if (file_path[i] == '/') {
            size_t dir_len = i + 1;
            if (dir_len + 1 > dir_path_len) {
                return -1;
            }
            memcpy(dir_path, file_path, dir_len);
            dir_path[dir_len] = '\0';
            return 0;
        }
    }

    return -1;
}

static void get_widget_module_dir(char *out, size_t out_len)
{
    if (g_config_dir_path[0] != '\0') {
        snprintf(out, out_len, "%s", g_config_dir_path);
        return;
    }

    if (get_dir_path_from_file_path(__FILE__, out, out_len) != 0) {
        snprintf(out, out_len, ".");
    }
}

static void build_widget_config_path(char *out, size_t out_len, const char *sub_dir)
{
    char module_dir[WIDGET_DIR_PATH_LEN_MAX];
    get_widget_module_dir(module_dir, sizeof(module_dir));
    snprintf(out, out_len, "%s/widget_file/%s", module_dir, sub_dir);
}
#endif

static void *widget_demo_task(void *arg)
{
    (void)arg;
    CHCNAV_OSAL_HANDLER_STRUCT *osal = chcnav_platform_get_osal_handler();
    if (osal == NULL) {
        return NULL;
    }

    char message[CHCNAV_WIDGET_FLOATING_WINDOW_MSG_MAX_LEN + 1];

    while (g_widget_started) {
        uint32_t time_ms = 0;
        osal->get_time_ms(&time_ms);

        snprintf(message, sizeof(message),
                 "System time : %u ms\r\n%s\r\n%s\r\n%s\r\n%s\r\n",
                 time_ms,
                 g_widget_log[0].valid ? g_widget_log[0].content : "",
                 g_widget_log[1].valid ? g_widget_log[1].content : "",
                 g_widget_log[2].valid ? g_widget_log[2].content : "",
                 g_widget_log[3].valid ? g_widget_log[3].content : "");

        chcnav_floating_window_show_message(message);
        osal->task_sleep_ms(200);
    }

    return NULL;
}

chcnav_return_code_t chcnav_test_widget_set_config_file_path(const char *path)
{
    if (path == NULL) {
        return CHCNAV_RETURN_ERR_PARAM;
    }

    memset(g_config_dir_path, 0, sizeof(g_config_dir_path));
    size_t copy_len = strlen(path);
    if (copy_len > sizeof(g_config_dir_path) - 1) {
        copy_len = sizeof(g_config_dir_path) - 1;
    }
    memcpy(g_config_dir_path, path, copy_len);

    return CHCNAV_RETURN_OK;
}

chcnav_return_code_t chcnav_test_widget_start(void)
{
    if (g_widget_started) {
        return CHCNAV_RETURN_OK;
    }

    chcnav_return_code_t ret = chcnav_widget_init();
    if (ret != CHCNAV_RETURN_OK) {
        CHCNAV_LOG_ERROR(demo, "chcnav_widget_init failed: %d", ret);
        return ret;
    }

#ifdef SYSTEM_ARCH_LINUX
    char en_path[WIDGET_DIR_PATH_LEN_MAX];
    char cn_path[WIDGET_DIR_PATH_LEN_MAX];
    build_widget_config_path(en_path, sizeof(en_path), "en_big_screen");
    build_widget_config_path(cn_path, sizeof(cn_path), "cn_big_screen");

    CHCNAV_LOG_INFO(demo, "widget en config dir: %s", en_path);
    CHCNAV_LOG_INFO(demo, "widget cn config dir: %s", cn_path);

    ret = chcnav_register_default_widget_config_dir_path(en_path);
    if (ret != CHCNAV_RETURN_OK) {
        CHCNAV_LOG_ERROR(demo, "chcnav_register_default_widget_config_dir_path failed: %d", ret);
        chcnav_widget_deinit();
        return ret;
    }

    ret = chcnav_register_widget_config_by_dir_path(CHCNAV_MOBILE_APP_LANGUAGE_ENGLISH, en_path);
    if (ret != CHCNAV_RETURN_OK) {
        CHCNAV_LOG_ERROR(demo, "chcnav_register_widget_config_by_dir_path(en) failed: %d", ret);
        chcnav_widget_deinit();
        return ret;
    }

    ret = chcnav_register_widget_config_by_dir_path(CHCNAV_MOBILE_APP_LANGUAGE_CHINESE, cn_path);
    if (ret != CHCNAV_RETURN_OK) {
        CHCNAV_LOG_ERROR(demo, "chcnav_register_widget_config_by_dir_path(cn) failed: %d", ret);
        chcnav_widget_deinit();
        return ret;
    }
#else
    CHCNAV_WIDGET_BINARY_ARRAY_CONFIG_STRUCT en_widget_binary_array_config;
    en_widget_binary_array_config.binary_array_count = g_en_binary_array_count;
    en_widget_binary_array_config.file_binary_array_list = g_en_file_binary_array_list;

    ret = chcnav_register_default_widget_config_by_binary_array(&en_widget_binary_array_config);
    if (ret != CHCNAV_RETURN_OK) {
        CHCNAV_LOG_ERROR(demo, "chcnav_register_default_widget_config_by_binary_array failed: %d", ret);
        chcnav_widget_deinit();
        return ret;
    }
#endif

    ret = chcnav_register_widget_handler_list(
        g_widget_handler_list,
        sizeof(g_widget_handler_list) / sizeof(g_widget_handler_list[0]));
    if (ret != CHCNAV_RETURN_OK) {
        CHCNAV_LOG_ERROR(demo, "chcnav_register_widget_handler_list failed: %d", ret);
        chcnav_widget_deinit();
        return ret;
    }

    CHCNAV_OSAL_HANDLER_STRUCT *osal = chcnav_platform_get_osal_handler();
    g_widget_started = true;
    if (osal != NULL) {
        if (osal->task_create("widget_demo_task", widget_demo_task, 2048, NULL,
                              &g_widget_demo_thread) != CHCNAV_RETURN_OK) {
            CHCNAV_LOG_ERROR(demo, "widget demo task create failed");
            g_widget_demo_thread = NULL;
        }
    }

    return CHCNAV_RETURN_OK;
}

void chcnav_test_widget_stop(void)
{
    if (!g_widget_started) {
        return;
    }

    g_widget_started = false;

    CHCNAV_OSAL_HANDLER_STRUCT *osal = chcnav_platform_get_osal_handler();
    if (osal != NULL && g_widget_demo_thread != NULL) {
        osal->task_destroy(g_widget_demo_thread);
        g_widget_demo_thread = NULL;
    }

    chcnav_widget_deinit();
}
