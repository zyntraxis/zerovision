cmake_minimum_required(VERSION 3.16)
project(zerovision)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(zerovision
    src/main.cpp
    src/zerovuln.cpp
    src/scan_filesystem.cpp
    src/scan_processes.cpp
    src/scan_services.cpp
    src/scan_network.cpp
)

target_include_directories(zerovision PRIVATE include)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_options(zerovision PRIVATE -O3 -march=native)
endif()
