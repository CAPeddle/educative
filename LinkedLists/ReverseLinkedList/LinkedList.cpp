#include "LinkedList.h"
#include <vector>
#include <string>
#include <memory>
#include <iostream>

LinkedList::LinkedList(std::vector<int> &vec)
{    
    for (size_t i = vec.size() - 1; i >= 0; i--)
    {
        auto node = std::make_unique<LinkedListNode>(vec[i]);
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

// std::string EduLinkedList::ToString()
// {
//     std::string result = "[";
//     EduLinkedListNode* temp = head.get();
//     while (temp != nullptr)
//     {
//         result += std::to_string(temp->data);
//         temp = temp->next.get();
//         if (temp != nullptr)
//         {
//             result += ",";
//         }
//     }
//     result += "]";
//     return result;
// }

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