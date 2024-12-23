cmake_minimum_required(VERSION 3.30)
project(Chapter04_CaesareanCipher C)

set(CMAKE_C_STANDARD 23)

add_executable(Chapter04_CaesareanCipher main.c)
add_executable(StreamDemo stream_demo.c)
add_executable(Buffering buffering.c
        io_filter.c)
add_executable(IOFilter io_filter.c)
add_executable(Censored censored.c)
add_executable(AllCaps allcaps.c)
