// https://www.educative.io/module/page/ovPPvKJYVy7s6xGY0PZV7l/5864882417434624/6674134241247232/5362666220683264

#include "LinkedList.h"
// #include "LinkedListForwardIterator.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    // std::unique_ptr<LinkedListNode> h;
    // LinkedList list_from_node(h);

    auto list_from_vec = LinkedList::CreateLinkedList(vec);
    std::cout << "Hello, World! " << list_from_vec << std::endl;

    // ListForwardIterator fwd_iterator(list_from_node.head);
}

/*
TODO:

Create iterator class to enable STL algos to work on linked list.
1st. Sort which then needs


*/