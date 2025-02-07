#include <gtest/gtest.h>
#include "SearchInARotatedArray.h"

TEST(SearchInARotatedArrayTest, FindInRotatedArray) {
    // Test case 1: Basic rotated array
    std::vector<int> arr1 = {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(SearchInARotatedArray::find(arr1, 0), 4);  // Target at pivot point
    EXPECT_EQ(SearchInARotatedArray::find(arr1, 3), -1); // Non-existent element
    EXPECT_EQ(SearchInARotatedArray::find(arr1, 6), 2);  // Element before pivot
    
    // Test case 2: Array rotated by 1
    std::vector<int> arr2 = {3, 1, 2};
    EXPECT_EQ(SearchInARotatedArray::find(arr2, 1), 1);
    
    // Test case 3: Non-rotated array
    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    EXPECT_EQ(SearchInARotatedArray::find(arr3, 3), 2);
    
    // Test case 4: Single element array
    std::vector<int> arr4 = {1};
    EXPECT_EQ(SearchInARotatedArray::find(arr4, 1), 0);
    EXPECT_EQ(SearchInARotatedArray::find(arr4, 2), -1);
    
    // Test case 5: Empty array
    std::vector<int> arr5 = {};
    EXPECT_EQ(SearchInARotatedArray::find(arr5, 1), -1);
    
    // Test case 6: Larger rotated array
    std::vector<int> arr6 = {8, 9, 10, 1, 2, 3, 4, 5, 6, 7};
    EXPECT_EQ(SearchInARotatedArray::find(arr6, 1), 3);  // First element after pivot
    EXPECT_EQ(SearchInARotatedArray::find(arr6, 10), 2); // Last element before pivot
    EXPECT_EQ(SearchInARotatedArray::find(arr6, 7), 9);  // Last element
}