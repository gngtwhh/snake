cmake_minimum_required(VERSION 3.25)
project(snake)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)
file(GLOB ALL_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fexec-charset=GBK")
add_executable(snake ${ALL_SOURCES})
