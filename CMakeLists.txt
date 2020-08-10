cmake_minimum_required(VERSION 3.11)
project(compute_a_posteriori)

set(CMAKE_CXX_STANDARD 14)

add_executable(compute_a_posteriori main.cpp)
target_link_libraries(compute_a_posteriori ${DEPENDENCIES})
