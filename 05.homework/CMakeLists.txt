cmake_minimum_required(VERSION 3.5)

project(statistics)

add_executable(statistics
    src/statistics.cpp
    src/Min.cpp
    src/Max.cpp
    src/Mean.cpp
    src/Std.cpp
)

target_include_directories(statistics PRIVATE include)

set_target_properties(statistics PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

install(TARGETS statistics
        RUNTIME DESTINATION install/bin)