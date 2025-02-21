cmake_minimum_required(VERSION 3.14)

# Create test executable
add_executable(SearchInARotatedArrayTest 
    "SearchInARotatedArrayTest.cpp"
)

# Include the directory containing the source headers
target_include_directories(SearchInARotatedArrayTest
    PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/..)

# target_link_libraries(SearchInARotatedArrayTest gtest_main)
target_link_libraries(SearchInARotatedArrayTest 
    PRIVATE
    gtest_main
    SearchInARotatedArrayLib
)

# target_link_libraries(SearchInARotatedArrayTest gtest_main)
add_test(NAME SearchInARotatedArrayTest COMMAND SearchInARotatedArrayTest)

# Test discovery
include(GoogleTest)
gtest_discover_tests(SearchInARotatedArrayTest 
    DISCOVERY_TIMEOUT 60
)

# Force rebuild of tests
set_property(
    TARGET SearchInARotatedArrayTest 
    PROPERTY EXCLUDE_FROM_ALL FALSE
)