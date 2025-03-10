#include "LinkedList.h"
#include <vector>
#include <string>
#include <memory>
#include <iostream>

LinkedList::LinkedList(std::vector<int> &vec)
{    
    for (auto it = vec.rbegin(); it != vec.rend(); ++it)
    {
        auto node = std::make_unique<LinkedListNode>(*it);
        InsertNodeAtHead(std::move(node));
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
    LinkedListNode *head = list->head.get();
    os << "[";
    while (head)
    {
        os << head->data << ' ';
        head = head->next.get();
    }
    os << "]";
    return os;
}

std::ostream &operator<<(std::ostream &os, const LinkedList &list)
{
    LinkedListNode *head = list.head.get();
    os << "[";
    while (head)
    {
        os << head->data << ' ';
        head = head->next.get();
    }
    os << "]";
    return os;
}