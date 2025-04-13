# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.14)

project ("educative")

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

# Include sub-projects.
add_subdirectory ("FastSlowPointers")
add_subdirectory ("Stacks")
add_subdirectory ("HashMaps")
add_subdirectory ("KnowingWhatToTrack")
add_subdirectory ("Graphs")
add_subdirectory ("SearchInARotatedArray")
add_subdirectory ("LinkedLists")
add_subdirectory ("designpatterns")