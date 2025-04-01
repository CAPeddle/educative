#include <gtest/gtest.h>

#include "LinkedList.cpp"

#include <climits>
#include <sstream>

// TODO remove depends on the << function
class ReverseTest : public ::testing::Test
{
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(ReverseTest, Head)
{
    std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    // std::vector<int> vec = {9, 8, 7, 6, 5};
    auto list_from_vec = EduLinkedList();
    list_from_vec.CreateLinkedList(vec);

    EXPECT_EQ(list_from_vec.ToString(), "[9,8,7,6,5,4,3,2,1,0]");

    auto new_head = list_from_vec.Reverse(list_from_vec.m_head);

    auto reversed_list = EduLinkedList(new_head);

    EXPECT_EQ(reversed_list.ToString(), "[0,1,2,3,4,5,6,7,8,9]");
}

TEST_F(ReverseTest, TraverseUntil)
{ //                         1,2,3,4,5,6,7,8,9,0
    std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    auto list_from_vec = EduLinkedList();
    list_from_vec.CreateLinkedList(vec);
    EXPECT_EQ(list_from_vec.ToString(), "[9,8,7,6,5,4,3,2,1,0]");

    auto positionNode = list_from_vec.TraverseLinkedListUntil(list_from_vec.m_head, 6);
    EXPECT_EQ(positionNode->data, 4);

    positionNode = list_from_vec.TraverseLinkedListUntil(list_from_vec.m_head, 1);
    EXPECT_EQ(positionNode->data, 9);

    positionNode = list_from_vec.TraverseLinkedListUntil(list_from_vec.m_head, 10);
    EXPECT_EQ(positionNode->data, 0);
}

TEST_F(ReverseTest, TraverseUntilEdgeCases)
{ //                         1,2,3,4,5,6,7,8,9,0
    std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    auto list_from_vec = EduLinkedList();
    list_from_vec.CreateLinkedList(vec);
    EXPECT_EQ(list_from_vec.ToString(), "[9,8,7,6,5,4,3,2,1,0]");

    EXPECT_THROW(list_from_vec.TraverseLinkedListUntil(list_from_vec.m_head, 0), std::out_of_range);

    EXPECT_THROW(list_from_vec.TraverseLinkedListUntil(list_from_vec.m_head, -1), std::out_of_range);

    EXPECT_THROW(list_from_vec.TraverseLinkedListUntil(list_from_vec.m_head, 11), std::out_of_range);
}

TEST_F(ReverseTest, FromTill)
{ //                     1,2,3,4,5,6,7,8,9,0
    std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    auto list_from_vec = EduLinkedList();
    list_from_vec.CreateLinkedList(vec);

    EXPECT_EQ(list_from_vec.ToString(), "[9,8,7,6,5,4,3,2,1,0]");

    auto new_head = list_from_vec.ReverseBetween(list_from_vec.m_head, 4, 7);

    EXPECT_EQ(list_from_vec.ToString(), "[9,8,7,3,4,5,6,2,1,0]");
}

TEST_F(ReverseTest, FromTillEdgeCases)
{
    {
        //                      1, 2, 3, 4, 5, 6, 7, 8, 9, 0
        std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        auto list_from_vec = EduLinkedList();
        list_from_vec.CreateLinkedList(vec);

        EXPECT_EQ(list_from_vec.ToString(), "[9,8,7,6,5,4,3,2,1,0]");
        auto new_head = list_from_vec.ReverseBetween(list_from_vec.m_head, 4, 4);
        EXPECT_EQ(list_from_vec.ToString(), "[9,8,7,6,5,4,3,2,1,0]");
    }

}

TEST_F(ReverseTest, EducativeTests)
{
    {
        //                      1, 2, 3, 4, 5, 6, 7, 8, 9, 0
        std::vector<int> vec = {1, 2, 3, 4, 5, 4, 3, 2, 1};
        auto list_from_vec = EduLinkedList();
        list_from_vec.CreateLinkedList(vec);

        EXPECT_EQ(list_from_vec.ToString(), "[1,2,3,4,5,4,3,2,1]");
        auto new_head = list_from_vec.ReverseBetween(list_from_vec.m_head, 1, 9);
        EXPECT_EQ(list_from_vec.ToString(), "[1,2,3,4,5,4,3,2,1]");
    }

}
