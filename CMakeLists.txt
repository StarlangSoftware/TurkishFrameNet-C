cmake_minimum_required(VERSION 3.23)
project(FrameNet C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(FrameNet src/FrameElement.c src/FrameElement.h src/Frame.c src/Frame.h src/FrameNet.c src/FrameNet.h)
target_link_libraries(FrameNet ${CONAN_LIBS})
add_executable(FrameElementTest src/FrameElement.c src/FrameElement.h src/Frame.c src/Frame.h src/FrameNet.c src/FrameNet.h Test/FrameElementTest.c)
target_link_libraries(FrameElementTest ${CONAN_LIBS})
add_executable(FrameNetTest src/FrameElement.c src/FrameElement.h src/Frame.c src/Frame.h src/FrameNet.c src/FrameNet.h Test/FrameNetTest.c)
target_link_libraries(FrameNetTest ${CONAN_LIBS})
