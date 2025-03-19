#include "LinkedList.h"
#include <vector>
#include <memory>
#include <iostream>

LinkedList::LinkedList(std::vector<int> &vec)
{
    for (auto it = vec.rbegin(); it != vec.rend(); ++it)
    {
        InsertNodeAtHead(std::make_unique<LinkedListNode>(*it));
    }
}

std::unique_ptr<LinkedList> LinkedList::CreateLinkedList(std::vector<int> &vec)
{
    auto list = std::make_unique<LinkedList>(vec);
    return list;
}

void LinkedList::InsertNodeAtHead(std::unique_ptr<LinkedListNode> node)
{
    if (head != nullptr)
    {
        node->next = std::move(head);
        head = std::move(node);
    }
    else
    {
        head = std::move(node);
    }
}

std::ostream &operator<<(std::ostream &os, const std::unique_ptr<LinkedList> &list)
{
    os << list->head;
    return os;
}

std::ostream &operator<<(std::ostream &os, const LinkedList &list)
{   
    os << list.head;
   
    return os;
}
