cmake_minimum_required(VERSION 3.0.2)
project(Test)

add_compile_options(-std=c++11)

add_compile_options(-march=native)
add_compile_options(-lpthread)

include_directories(inc)

set(SRCS 
    src/CanManager.cpp
    src/Math.cpp
    src/M2006.cpp
    src/Pid.cpp
    src/M3508.cpp
    src/M6020.cpp
    src/DM4310.cpp
    )

add_executable(Test main.cpp ${SRCS})

target_link_libraries(Test pthread)