# CMakeList.txt : CMake project for SearchInARotatedArray, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

# Define the project name
project(SearchInARotatedArray)

# Create library from source files
add_library(SearchInARotatedArrayLib 
    "SearchInARotatedArray.cpp"
    "SearchInARotatedArray.h"
)

# Add source to this project's executable.
add_executable (SearchInARotatedArray "main.cpp")
target_link_libraries(SearchInARotatedArray PRIVATE SearchInARotatedArrayLib)

# Add the test subdirectory
add_subdirectory(test)