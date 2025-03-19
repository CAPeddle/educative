cmake_minimum_required(VERSION 3.14)

# Create test executable
add_executable(ReverseLinkedListTest 
    "LinkedListTest.cpp"
)

# Include the directory containing the source headers
target_include_directories(ReverseLinkedListTest
    PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/..)

# target_link_libraries(LinkedListTest gtest_main)
target_link_libraries(ReverseLinkedListTest 
    PRIVATE
    gtest_main
    ReverseLinkedListLib
)

# target_link_libraries(LinkedListTest gtest_main)
add_test(NAME ReverseLinkedListTest COMMAND ReverseLinkedListTest)

# Test discovery
include(GoogleTest)
gtest_discover_tests(ReverseLinkedListTest 
    DISCOVERY_TIMEOUT 60
)

# Force rebuild of tests
set_property(
    TARGET ReverseLinkedListTest 
    PROPERTY EXCLUDE_FROM_ALL FALSE
)