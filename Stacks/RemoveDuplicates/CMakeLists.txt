# CMakeList.txt : CMake project for RemoveDuplicates, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

# Define the project name
project(RemoveDuplicates)

# Create library from source files
add_library(RemoveDuplicatesLib 
    "RemoveDuplicates.cpp"
    "RemoveDuplicates.h"
)

# Add source to this project's executable.
add_executable (RemoveDuplicates "main.cpp")
target_link_libraries(RemoveDuplicates PRIVATE RemoveDuplicatesLib)

# Add the test subdirectory
add_subdirectory(test)
