cmake_minimum_required(VERSION 3.0.2)
project(Test)

add_compile_options(-std=c++11)

add_compile_options(-march=native)
add_compile_options(-lpthread)

include_directories(inc)

set(SRCS 
    src/CanManager.cpp
    src/Math.cpp
    src/Pid.cpp
    src/DM4310.cpp
    )

add_executable(Test main.cpp ${SRCS})

target_link_libraries(Test pthread)