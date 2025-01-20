cmake_minimum_required(VERSION 3.14)

project(googletest-download NONE)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           release-1.10.0
  SOURCE_DIR        "${CMAKE_SOURCE_DIR}/googletest-src"
  BINARY_DIR        "${CMAKE_BINARY_DIR}/googletest-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)

# Add googletest directly to our build. This adds the following targets:
# gtest, gtest_main, gmock, gmock_main
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(TwoPointersTest TwoPointersTest.cpp)
target_link_libraries(TwoPointersTest gtest_main)
add_test(NAME TwoPointersTest COMMAND TwoPointersTest)