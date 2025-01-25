# CMakeList.txt : CMake project for RateLimiter, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

# Define the project name
project(RateLimiter)

# Create library from source files
add_library(RateLimiterLib 
    "RateLimiter.cpp"
    "RateLimiter.h"
)

# Add source to this project's executable.
add_executable (RateLimiter "main.cpp")
target_link_libraries(RateLimiter PRIVATE RateLimiterLib)

# Add the test subdirectory
add_subdirectory(test)
