cmake_minimum_required(VERSION 3.30)
project(ASimpleGreeting C)

set(CMAKE_C_STANDARD 23)

add_executable(ASimpleGreeting main.c
        greet02.c)
