cmake_minimum_required(VERSION 3.16)

project(CrowHello)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Crow)

add_executable(CrowHello main.cpp)

target_link_libraries(CrowHello PRIVATE Crow::Crow)