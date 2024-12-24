cmake_minimum_required(VERSION 3.30)
project(Chapter05_EncodingAndDecoding C)

set(CMAKE_C_STANDARD 23)

add_executable(Chapter05_EncodingAndDecoding main.c)
add_executable(ASCIITable01 asciiTable01.c)
add_executable(BinaryASCIITable01 binaryAsciiTable01.c)
add_executable(CaseTricks01 caseTricks01.c)
add_executable(HexenFilter01 hexenFilter01.c)
add_executable(HexDefilter01 hexDefilter01.c)
add_executable(HexEncode01 hexEncode01.c)
