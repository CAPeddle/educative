﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.14)

project(Stacks)

# Include sub-projects.
add_subdirectory ("RemoveDuplicates")
add_subdirectory ("Queue")
