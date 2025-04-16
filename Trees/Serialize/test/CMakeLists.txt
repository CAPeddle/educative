cmake_minimum_required(VERSION 3.14)

# Create test executable
add_executable(SerializeTest 
    "SerializeTest.cpp"
)

# Include the directory containing the source headers
target_include_directories(SerializeTest
    PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/..)

# target_link_libraries(LinkedListTest gtest_main)
target_link_libraries(SerializeTest 
    PRIVATE
    gtest_main
    SerializeLib
)

# target_link_libraries(LinkedListTest gtest_main)
add_test(NAME SerializeTest COMMAND SerializeTest)

# Test discovery
include(GoogleTest)
gtest_discover_tests(SerializeTest 
    DISCOVERY_TIMEOUT 60
)

# Force rebuild of tests
set_property(
    TARGET SerializeTest 
    PROPERTY EXCLUDE_FROM_ALL FALSE
)