cmake_minimum_required(VERSION 3.20)
project(2)
add_executable(Test Main.cpp Source.hpp)

add_subdirectory(Catch2 Catch2-build)
target_link_libraries(Test PRIVATE Catch2::Catch2)