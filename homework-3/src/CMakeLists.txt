cmake_minimum_required(VERSION 3.5)

project(game)

add_executable(
    game
    game.cpp
)

target_include_directories(
        game 
        PRIVATE 
        ${CMAKE_CURRENT_BINARY_DIR}
)

target_include_directories(
        game
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../utilities
)

target_link_libraries(
	game
	PUBLIC
	utility
)

set_target_properties(
    game PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

install(TARGETS game
        RUNTIME DESTINATION install/bin)