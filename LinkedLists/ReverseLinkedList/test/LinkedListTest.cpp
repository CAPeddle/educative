#include <gtest/gtest.h>

#include "LinkedList.h"
// #include "LinkedListForwardIterator.h"
#include <climits>
#include <sstream>

class CreationTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(CreationTest, ListFromVec) {    
    std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    auto list_from_vec = LinkedList::CreateLinkedList(vec);

    std::stringstream streamed;
    streamed << list_from_vec;
    
    EXPECT_EQ("[9 8 7 6 5 4 3 2 1 0 ]", streamed.str());      
}


TEST_F(CreationTest, IteratorFromNode) {    
    std::unique_ptr<LinkedListNode> h;
    std::cout << "Node data: " << h->data << std::endl;
    LinkedList list_from_node(h);
       
    // auto fwd_iterator = list_from_node.begin();
    // ListForwardIterator fwd_iterator(list_from_node.head);
}


