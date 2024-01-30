cmake_minimum_required(VERSION 3.23)
project(FrameNet)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

find_package(xml_parser_c REQUIRED)
find_package(util_c REQUIRED)

add_library(FrameNet src/FrameElement.c src/FrameElement.h src/Frame.c src/Frame.h src/FrameNet.c src/FrameNet.h)
target_link_libraries(FrameNet xml_parser_c::xml_parser_c util_c::util_c)
add_executable(FrameElementTest src/FrameElement.c src/FrameElement.h src/Frame.c src/Frame.h src/FrameNet.c src/FrameNet.h Test/FrameElementTest.c)
target_link_libraries(FrameElementTest xml_parser_c::xml_parser_c util_c::util_c)
add_executable(FrameNetTest src/FrameElement.c src/FrameElement.h src/Frame.c src/Frame.h src/FrameNet.c src/FrameNet.h Test/FrameNetTest.c)
target_link_libraries(FrameNetTest xml_parser_c::xml_parser_c util_c::util_c)
