#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedListNode.cpp"

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

// Definition for a Linked List node
// struct EduLinkedListNode {
//     int data;
//     EduLinkedListNode *next;
//     EduLinkedListNode(int d) {
//         data = d;
//         next = nullptr;
//     }
// };

// Template for the linked list
class EduLinkedList
{
public:
    EduLinkedListNode *head = new EduLinkedListNode(0);
    // EduLinkedList() will be used to make a EduLinkedList type object
    EduLinkedList() { head = nullptr; }
    EduLinkedList(EduLinkedListNode *h) { head = h; }
    // InsertNodeAtHead() method will insert a LinkedListNode at head
    // of a linked list.
    void InsertNodeAtHead(EduLinkedListNode *node)
    {
        if (head != nullptr)
        {
            node->next = head;
            head = node;
        }
        else
        {
            head = node;
        }
    }
    // CreateLinkedList() method will create the linked list using the
    // given integer array with the help of InsertAthead method.
    void CreateLinkedList(std::vector<int> &vec)
    {
        for (int i = (int)vec.size() - 1; i >= 0; i--)
        {
            EduLinkedListNode *node = new EduLinkedListNode(vec[i]);
            InsertNodeAtHead(node);
        }
        ToString();
    }
    // ToString() method will display the elements of linked list.
    std::string ToString()
    {
        std::string result = "[";
        EduLinkedListNode *temp = head;
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

        m_current_list = result;
        return result;
    }

    EduLinkedListNode *Reverse(EduLinkedListNode *head)
    {
        EduLinkedListNode *current = head;
        EduLinkedListNode *nxt = current->next;
        EduLinkedListNode *previous = nullptr;

        while (nxt != nullptr)
        {
            nxt = current->next;
            current->next = previous;

            previous = current;
            current = nxt;
        }

        head = previous;

        ToString();
        return head;
    }

    // Not zero based, '1' is the start
    EduLinkedListNode *ReverseBetween(EduLinkedListNode *head, int left, int right)
    {
        EduLinkedListNode *beforeleftNode = nullptr;
        EduLinkedListNode *rightNode = nullptr;
        try
        {
            beforeleftNode = TraverseLinkedListUntil(head, left - 1);
            rightNode = TraverseLinkedListUntil(head, right);
        }
        catch (const std::exception &e)
        {
            std::string error_text = std::string("Invalid request, ") + e.what();
            throw std::invalid_argument(error_text);
        }

        if (beforeleftNode == nullptr || rightNode == nullptr)
        {
            throw std::exception("Invalid ");
        }

        EduLinkedListNode *afterRightNode = rightNode->next;
        EduLinkedListNode *current = beforeleftNode->next;
        EduLinkedListNode *nxt = current->next;
        EduLinkedListNode *previous = nullptr;

        while (current != afterRightNode && nxt != nullptr)
        {
            nxt = current->next;
            current->next = previous;

            previous = current;
            current = nxt;
        }
        beforeleftNode->next->next = current;
        beforeleftNode->next = rightNode;

        ToString();
        return head;
    }

    // Not zero based, '1' is the start
    EduLinkedListNode *TraverseLinkedListUntil(EduLinkedListNode *head, int position)
    {
        if (position <= 0)
        {
            throw std::out_of_range("Index starts at 1");
        }

        int current_position{1};
        EduLinkedListNode *current = head;
        EduLinkedListNode *nxt = nullptr;
        while (current != nullptr && current_position < position)
        {
            nxt = current->next;
            current = nxt;
            ++current_position;
        }

        if (current == nullptr)
        {
            throw std::out_of_range("Request past end");
        }
        ToString();
        return current;
    }

private:
    std::string m_current_list;
};

#endif // LINKEDLIST_H