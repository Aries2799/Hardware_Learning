cmake_minimum_required(VERSION 3.0)
project(serial_communication)

# 设置 C++ 版本
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 添加可执行文件并指定源文件
add_executable(serial_communication src/main.cpp src/SerialStream.cpp)
