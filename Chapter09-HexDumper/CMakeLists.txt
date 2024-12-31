cmake_minimum_required(VERSION 3.30)
project(Chapter09_HexDumper C)

set(CMAKE_C_STANDARD 23)

add_executable(Chapter09_HexDumper main.c)
add_executable(ByteSizes byte_sizes.c)
add_executable(Limits limits.c)
add_executable(ByteValues01 byte_values01.c)
add_executable(ByteValues02 byte_values02.c)
add_executable(ByteValues03 byte_values03.c)
