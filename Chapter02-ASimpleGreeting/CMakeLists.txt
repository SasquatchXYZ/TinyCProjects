cmake_minimum_required(VERSION 3.30)
project(Chapter02_ASimpleGreeting C)

set(CMAKE_C_STANDARD 23)

add_executable(Chapter02_ASimpleGreeting main.c
        greet02.c
        time01.c
        time02.c
        greet03.c
        greet04.c
        moon01.c
        pithy01.c
        pithy02.c
        pithy03.c
        pithy04.c
        pithy05.c)
