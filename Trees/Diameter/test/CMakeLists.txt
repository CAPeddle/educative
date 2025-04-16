cmake_minimum_required(VERSION 3.14)

# Create test executable
add_executable(TreeDiameterTest 
    "TreeDiameterTest.cpp"
)

# Include the directory containing the source headers
target_include_directories(TreeDiameterTest
    PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/..)

# target_link_libraries(LinkedListTest gtest_main)
target_link_libraries(TreeDiameterTest 
    PRIVATE
    gtest_main
    TreeDiameterLib
)

# target_link_libraries(LinkedListTest gtest_main)
add_test(NAME TreeDiameterTest COMMAND TreeDiameterTest)

# Test discovery
include(GoogleTest)
gtest_discover_tests(TreeDiameterTest 
    DISCOVERY_TIMEOUT 60
)

# Force rebuild of tests
set_property(
    TARGET TreeDiameterTest 
    PROPERTY EXCLUDE_FROM_ALL FALSE
)