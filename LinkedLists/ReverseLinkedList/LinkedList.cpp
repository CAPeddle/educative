#include "LinkedListNode.h"
#include "LinkedList.h"
#include <vector>
#include <string>
#include <memory>

void EduLinkedList::InsertNodeAtHead(std::unique_ptr<EduLinkedListNode> node)
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

void EduLinkedList::CreateLinkedList(std::vector<int> &vec)
{
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        auto node = std::make_unique<EduLinkedListNode>( new EduLinkedListNode(vec[i]));
        InsertNodeAtHead(std::move(node));
    }
}

std::string EduLinkedList::ToString()
{
    std::string result = "[";
    std::unique_ptr<EduLinkedListNode> temp = head;
    while (temp != nullptr)
    {
        result += std::to_string(temp->data);
        temp = temp->next;
        if (temp != nullptr)
        {
            result += ",";
        }
    }
    result += "]";
    return result;
}
