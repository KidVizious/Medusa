cmake_minimum_required(VERSION 3.14)
project(medusa C CXX)

add_executable(medusa)
target_include_directories(medusa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(medusa PRIVATE main.cpp medusa.cpp)
