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
    auto list_from_vec = LinkedList::CreateLinkedList(vec);

    std::stringstream streamed;
    streamed << list_from_vec;

    EXPECT_EQ("[9 8 7 6 5 4 3 2 1 0 ]", streamed.str());
}

class PrintTest : public ::testing::Test
{
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(PrintTest, ListFromVec)
{
    std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    auto list_from_vec = LinkedList::CreateLinkedList(vec);

    std::stringstream streamed;
    streamed << list_from_vec;

    EXPECT_EQ("[9 8 7 6 5 4 3 2 1 0 ]", streamed.str());
}

TEST_F(PrintTest, ListFromVec_HeadNode)
{
    std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    auto list_from_vec = LinkedList::CreateLinkedList(vec);
    auto head_node = list_from_vec->head;

    std::stringstream streamed;
    streamed << head_node;

    EXPECT_EQ("[9 8 7 6 5 4 3 2 1 0 ]", streamed.str());
}

TEST_F(PrintTest, ListFromVec_NextNode)
{
    std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    auto list_from_vec = LinkedList::CreateLinkedList(vec);
    auto next_node = list_from_vec->head->next;

    std::stringstream streamed;
    streamed << next_node;

    EXPECT_EQ("[8 7 6 5 4 3 2 1 0 ]", streamed.str());
}

class DeleteTest : public ::testing::Test
{
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(DeleteTest, CopyNodeOutOfContext)
{
    std::shared_ptr<LinkedListNode> node;
    {
        std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        auto list_from_vec = LinkedList::CreateLinkedList(vec);

        node = list_from_vec->head;
    }

    std::stringstream streamed;
    streamed << node;
    EXPECT_EQ("[9 8 7 6 5 4 3 2 1 0 ]", streamed.str());
}

TEST_F(DeleteTest, DeleteList)
{
    std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    auto list_from_vec = LinkedList::CreateLinkedList(vec);

    EXPECT_GT(list_from_vec->head.use_count(), 0);
    auto copy_of_head = list_from_vec->head;
    EXPECT_EQ(2, list_from_vec->head.use_count());

    copy_of_head.reset();
    EXPECT_EQ(1, list_from_vec->head.use_count()); // use count of 1 use case is flaky in multi threaded
    EXPECT_FALSE(list_from_vec->head.unique());    // deprecated

    std::stringstream streamed;
    streamed << list_from_vec;
    EXPECT_EQ("[9 8 7 6 5 4 3 2 1 0 ]", streamed.str());
}

#include <list>

class STL_List : public ::testing::Test
{
protected:
    void SetUp() override {}
    void TearDown() override {}

    std::list<int> create(std::vector<int> &vec)
    {
        std::list<int> list;

        for (auto it = vec.rbegin(); it != vec.rend(); ++it)
        {
            list.emplace_back(*it);
        }
        return list;
    }
};

TEST_F(STL_List, CheckReference)
{
    std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    auto list_from_vec = create(vec);

    // std::shared_ptr<LinkedListNode> node;
    // // node = list_from_vec->head;
    
    // std::stringstream streamed;
    // streamed << list_from_vec;
    // EXPECT_EQ("[9 8 7 6 5 4 3 2 1 0 ]", streamed.str());
}

// TEST_F(CreationTest, IteratorFromNode) {
//     std::unique_ptr<LinkedListNode> h;
//     std::cout << "Node data: " << h->data << std::endl;
//     LinkedList list_from_node(h);

//     // auto fwd_iterator = list_from_node.begin();
//     // ListForwardIterator fwd_iterator(list_from_node.head);
// }
