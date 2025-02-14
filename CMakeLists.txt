cmake_minimum_required(VERSION 3.10)  # Ensure your CMake version is compatible

project(DistributedFileSystem)  # Project name

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
add_executable(server src/server.cpp src/utils.cpp)
add_executable(client src/client.cpp src/utils.cpp)

# Optionally, include directories if needed
# include_directories(${PROJECT_SOURCE_DIR}/src)