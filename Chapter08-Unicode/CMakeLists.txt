cmake_minimum_required(VERSION 3.30)
project(Chapter08_Unicode C)

set(CMAKE_C_STANDARD 23)

add_executable(Chapter08_Unicode main.c)
add_executable(Morse_Code_Filter morse_code_filter.c)
add_executable(Extended_ASCII extended_ascii.c)
add_executable(Locale_Function locale_function.c)
add_executable(Hello_WWorld01 hello_wworld01.c)
