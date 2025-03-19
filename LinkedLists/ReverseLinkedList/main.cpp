// https://www.educative.io/module/page/ovPPvKJYVy7s6xGY0PZV7l/5864882417434624/6674134241247232/5362666220683264

#include "LinkedList.cpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    auto list_from_vec = EduLinkedList();
    list_from_vec.CreateLinkedList(vec);

    std::cout << "Hello\n";
}