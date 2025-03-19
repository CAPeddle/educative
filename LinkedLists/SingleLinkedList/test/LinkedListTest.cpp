#include <gtest/gtest.h>

#include "LinkedList.h"
// #include "LinkedListForwardIterator.h"
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
    // auto list_from_vec = LinkedList::CreateLinkedList(vec);

    // std::stringstream streamed;
    // streamed << list_from_vec;

    // EXPECT_EQ("[9 8 7 6 5 4 3 2 1 0 ]", streamed.str());
}

class PrintTest : public ::testing::Test
{
protected:
    void SetUp() override {}
    void TearDown() override {}
};


class DeleteTest : public ::testing::Test
{
protected:
    void SetUp() override {}
    void TearDown() override {}
};


// #include <list>

// class STL_List : public ::testing::Test
// {
// protected:
//     void SetUp() override {}
//     void TearDown() override {}

//     std::list<int> create(std::vector<int> &vec)
//     {
//         std::list<int> list;

//         for (auto it = vec.rbegin(); it != vec.rend(); ++it)
//         {
//             list.emplace_back(*it);
//         }
//         return list;
//     }
// };


