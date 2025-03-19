#include <gtest/gtest.h>

#include "LinkedList.cpp"

#include <climits>
#include <sstream>

// TODO remove depends on the << function
class CreationTest : public ::testing::Test
{
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(CreationTest, ListFromVec)
{
    std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    // std::vector<int> vec = {9, 8, 7, 6, 5};
    auto list_from_vec = EduLinkedList();
    list_from_vec.CreateLinkedList(vec);
    std::cout << "list_from_vec: " << list_from_vec.ToString() <<std::endl;

    EXPECT_EQ (list_from_vec.ToString(), "[9,8,7,6,5,4,3,2,1,0]");

    auto new_head = list_from_vec.Reverse(list_from_vec.head);

    auto reversed_list = EduLinkedList(new_head);
    
    std::cout << "reversed_list: " << reversed_list.ToString() <<std::endl;

    EXPECT_EQ (reversed_list.ToString(), "[0,1,2,3,4,5,6,7,8,9]");
}




