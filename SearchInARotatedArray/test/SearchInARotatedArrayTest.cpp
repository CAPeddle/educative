#include <gtest/gtest.h>
#include "SearchInARotatedArray.h"

class SearchInARotatedArrayTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(SearchInARotatedArrayTest, NonRotated) {    
    std::vector<int> arr1 = {0, 1, 2, 3, 4, 5, 6, 7};
    EXPECT_EQ(SearchInARotatedArray::find(arr1, 4), 4);      
}

TEST_F(SearchInARotatedArrayTest, PivotAtMid) {    
    std::vector<int> arr1 = {4, 5, 6, 7, 0, 1, 2, 3};
    EXPECT_EQ(SearchInARotatedArray::find(arr1, 0), 4);  
}


TEST_F(SearchInARotatedArrayTest, PivotBeforeMid) {    
    std::vector<int> arr1 = {5, 6, 7, 0, 1, 2, 3, 4};
    EXPECT_EQ(SearchInARotatedArray::find(arr1, 0), 4);  
}

TEST_F(SearchInARotatedArrayTest, BasicRotatedArray) {
    const std::vector<int> arr{4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(SearchInARotatedArray::find(arr, 0), 4);  // Target at pivot
    EXPECT_EQ(SearchInARotatedArray::find(arr, 3), -1); // Non-existent
    EXPECT_EQ(SearchInARotatedArray::find(arr, 6), 2);  // Before pivot
}

TEST_F(SearchInARotatedArrayTest, EdgeCases) {
    // Empty array
    const std::vector<int> empty;
    EXPECT_EQ(SearchInARotatedArray::find(empty, 1), -1);
    
    // Single element
    const std::vector<int> single{1};
    EXPECT_EQ(SearchInARotatedArray::find(single, 1), 0);
    EXPECT_EQ(SearchInARotatedArray::find(single, 2), -1);
}

TEST_F(SearchInARotatedArrayTest, PivotPositions) {
    // Pivot at start
    const std::vector<int> atStart{1, 2, 3, 4, 5};
    EXPECT_EQ(SearchInARotatedArray::find(atStart, 1), 0);
    
    // Pivot at middle
    const std::vector<int> atMiddle{4, 5, 6, 1, 2, 3};
    EXPECT_EQ(SearchInARotatedArray::find(atMiddle, 1), 3);
    
    // Pivot at end-1
    const std::vector<int> nearEnd{6, 7, 1, 2, 3, 4, 5};
    EXPECT_EQ(SearchInARotatedArray::find(nearEnd, 1), 2);
}

TEST_F(SearchInARotatedArrayTest, DuplicateValues) {
    const std::vector<int> withDupes{2, 2, 2, 3, 1, 2};
    EXPECT_EQ(SearchInARotatedArray::find(withDupes, 1), 4);
    EXPECT_EQ(SearchInARotatedArray::find(withDupes, 4), -1);
}

TEST_F(SearchInARotatedArrayTest, BoundaryConditions) {
    const std::vector<int> arr{INT_MAX, 0, 1, 2, INT_MIN};
    EXPECT_EQ(SearchInARotatedArray::find(arr, INT_MAX), 0);
    EXPECT_EQ(SearchInARotatedArray::find(arr, INT_MIN), 4);
}