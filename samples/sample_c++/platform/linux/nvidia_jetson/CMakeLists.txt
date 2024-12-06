cmake_minimum_required(VERSION 3.4.1)
project(chcnav_psdk_demo CXX)
set(CMAKE_CXX_FLAGS "-std=c++11 -pthread")
set(CMAKE_EXE_LINKER_FLAGS "-pthread")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
execute_process(COMMAND uname -m OUTPUT_VARIABLE DEVICE_SYSTEM_ID)
if (DEVICE_SYSTEM_ID MATCHES x86_64)
    set(TOOLCHAIN_NAME x86_64-linux-gnu-gcc)
elseif (DEVICE_SYSTEM_ID MATCHES aarch64)
    set(TOOLCHAIN_NAME aarch64-linux-gnu-gcc)
else ()
    message(FATAL_ERROR "Invalid platform")
endif ()

message(STATUS
        "TOOLCHAIN_NAME:${TOOLCHAIN_NAME}")
include_directories(
    ../../../modules_sample/payload_camera/
    ../../../modules_sample/camera_manager/
)

file(GLOB GLOB_SRCS
    main.cpp
    hal/*.cpp
    osal/*.cpp
    ../../../modules_sample/payload_camera/*.cpp
    ../../../modules_sample/camera_manager/*.cpp
)


add_executable(${PROJECT_NAME}
        ${GLOB_SRCS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../../../../../psdk_lib/lib/${TOOLCHAIN_NAME}/libpayloadsdk.a)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../../../../../psdk_lib/include)

set_target_properties( ${PROJECT_NAME}
    PROPERTIES
    OUTPUT_NAME               ${PROJECT_NAME}
    RUNTIME_OUTPUT_DIRECTORY  "${EXECUTABLE_OUTPUT_PATH}"
)
