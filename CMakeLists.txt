cmake_minimum_required(VERSION 3.28.3)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)

set(SDL3_DIR "/home/deku/Projetos/libs/SDL3-3.2.4")

include_directories(${SDL3_DIR}/include)

link_directories(${SDL3_DIR}/build)

add_executable(Calculator src/main.cpp)

target_link_libraries(Calculator SDL3)