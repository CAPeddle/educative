# CMakeList.txt : CMake project for NoOfIslands, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

# Define the project name
project(NoOfIslands)

# Create library from source files
add_library(NoOfIslandsLib 
    "NoOfIslands.cpp"
    "NoOfIslands.h"
)

# Add source to this project's executable.
add_executable (NoOfIslands "main.cpp")
target_link_libraries(NoOfIslands PRIVATE NoOfIslandsLib)

# Add the test subdirectory
add_subdirectory(test)
