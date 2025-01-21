# CMakeList.txt : CMake project for RemoveDuplicates, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

# Define the project name
project(RemoveDuplicates)

# Add source to this project's executable.
add_executable (RemoveDuplicates "main.cpp" "RemoveDuplicates.cpp" "RemoveDuplicates.h")

# Add the test subdirectory
add_subdirectory(test)

# TODO: Add tests and install targets if needed.
