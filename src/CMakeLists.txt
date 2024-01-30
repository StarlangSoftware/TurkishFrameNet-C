cmake_minimum_required(VERSION 3.23)
project(FrameNet)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

find_package(xml_parser_c REQUIRED)
find_package(util_c REQUIRED)

add_library(FrameNet FrameElement.c FrameElement.h Frame.c Frame.h FrameNet.c FrameNet.h)
target_link_libraries(FrameNet xml_parser_c::xml_parser_c util_c::util_c)
