# cmake_minimum_required(VERSION <specify CMake version here>)
project(final)

set(CMAKE_CXX_STANDARD 11)

set(GCC_ENABLE_WARNINGS "-O0 -Wall -Werror -Wno-unused-result")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_ENABLE_WARNINGS}")

add_executable(final
        board.c
        board.h
        main.c
        move.c
        move.h
        structs.h
        win.c
        win.h)
