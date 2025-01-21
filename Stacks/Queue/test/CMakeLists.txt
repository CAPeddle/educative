cmake_minimum_required(VERSION 3.14)

# Create test executable
add_executable(MyQueueTest 
    "MyQueueTest.cpp"
)

# Include the directory containing the source headers
target_include_directories(MyQueueTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# target_link_libraries(MyQueueTest gtest_main)
target_link_libraries(MyQueueTest 
    PRIVATE
    gtest_main
    MyQueueLib
)

# target_link_libraries(MyQueueTest gtest_main)
add_test(NAME MyQueueTest COMMAND MyQueueTest)


