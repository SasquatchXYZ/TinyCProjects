cmake_minimum_required(VERSION 3.30)
project(Chapter07_StringUtilities C)

set(CMAKE_C_STANDARD 23)

add_executable(Chapter07_StringUtilities main.c)
add_executable(StringSize string_size.c)
add_executable(Empty-Null empty-null.c)
add_executable(StrCat strcat.c)
add_executable(StrAppend strappend.c)
add_executable(StrUpper strupper.c)
add_executable(StrLower strlower.c)
add_executable(StrCaps strcaps.c)
add_executable(StrRev strrev.c)
