cmake_minimum_required(VERSION 3.14)

project(googletest-download NONE)

# configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

# Add googletest directly to our build. This adds the following targets:
# gtest, gtest_main, gmock, gmock_main
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(LinkedListTest LinkedListTest.cpp)
target_link_libraries(LinkedListTest gtest_main)
add_test(NAME LinkedListTest COMMAND LinkedListTest)