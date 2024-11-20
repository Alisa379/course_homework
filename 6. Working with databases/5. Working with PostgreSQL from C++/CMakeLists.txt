cmake_minimum_required(VERSION 3.20)
set(PostgreSQL_ADDITIONAL_VERSIONS "15")
project(MyProject)

add_subdirectory("D:/informatics/libpqxx-7.8.1" libpqxx-build)
add_executable(MyProject main.cpp "Header.h" "Source.cpp")
target_compile_features(MyProject PRIVATE cxx_std_17)
target_link_libraries(MyProject pqxx)