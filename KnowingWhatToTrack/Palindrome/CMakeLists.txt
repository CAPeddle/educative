# CMakeList.txt : CMake project for Palindrome, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

# Define the project name
project(Palindrome)

# Create library from source files
add_library(PalindromeLib 
    "Palindrome.cpp"
    "Palindrome.h"
)

# Add source to this project's executable.
add_executable (Palindrome "main.cpp")
target_link_libraries(Palindrome PRIVATE PalindromeLib)

# Add the test subdirectory
add_subdirectory(test)
