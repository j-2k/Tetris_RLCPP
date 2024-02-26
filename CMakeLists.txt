cmake_minimum_required(VERSION 3.8)
project(TetrisRLCPP)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Set the path to Raylib library and include directories
set(RAYLIB_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(RAYLIB_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")

# Add Raylib library and include directories
include_directories("${RAYLIB_INCLUDE_DIR}")
link_directories("${RAYLIB_LIBRARY_DIR}")

# Set the MY_SOURCES src files for your project
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} "${MY_SOURCES}")

# Link Raylib to your project
target_link_libraries(${PROJECT_NAME} raylib)
