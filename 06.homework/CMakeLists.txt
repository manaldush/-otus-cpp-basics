cmake_minimum_required(VERSION 3.5)

project(containers)

add_executable(containers
    src/containers.cpp
)

target_include_directories(containers PRIVATE include)

set_target_properties(containers PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

install(TARGETS containers
        RUNTIME DESTINATION install)