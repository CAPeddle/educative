﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.14)

project ("educative")

# Include sub-projects.
add_subdirectory ("HappyNumbers")
# add_subdirectory ("TwoPointers")
add_subdirectory ("LinkedListCycle")
