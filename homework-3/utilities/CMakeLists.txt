cmake_minimum_required(VERSION 3.5)

project(utilities)

add_library(
	utility

	SHARED

	utility.cpp
	utility.h
)

set_target_properties(
	utility PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	WINDOWS_EXPORT_ALL_SYMBOLS ON
)

install(TARGETS utility
        RUNTIME DESTINATION install/bin)