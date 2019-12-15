cmake_minimum_required(VERSION 3.13.2)
project(project C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)

add_executable(project
        inc/backend.h
        inc/cmu_packet.h
        inc/cmu_tcp.h
        inc/global.h
        inc/grading.h
        src/backend.c
        src/client.c
        src/cmu_packet.c
        src/cmu_tcp.c
        src/server.c
        test/testing_server.c)
