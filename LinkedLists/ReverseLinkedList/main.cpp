//https://www.educative.io/module/page/ovPPvKJYVy7s6xGY0PZV7l/5864882417434624/6674134241247232/5362666220683264

#include "LinkedList.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = { 7, 8, 9, 0, 3, 5, 6 };

    LinkedListNode* node = new LinkedListNode(4);

    auto list = LinkedList::CreateLinkedList(vec);
    std::cout << "Hello, World!" << list << std::endl;
}
