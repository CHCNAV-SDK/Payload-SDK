cmake_minimum_required(VERSION 3.4.1)
project(entry)

set(CMAKE_INSTALL_BIN_RPATH ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(samples/sample_c++/platform/linux/nvidia_jetson)
