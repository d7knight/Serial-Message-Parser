cmake_minimum_required(VERSION 3.2)
project(skyladders)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES serial_adapter.cpp serial_message_parser.cpp serial_adapter.h)
add_executable(skyladders ${SOURCE_FILES} helper.h helper.h helper.cpp)