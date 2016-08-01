cmake_minimum_required(VERSION 2.8)
project(echo_server)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=iso9899:1990")

set(SOURCE_FILES main.c init_server.c)
add_executable(echo_server ${SOURCE_FILES})
