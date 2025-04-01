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
    EduLinkedListNode *m_head = new EduLinkedListNode(0);
    // EduLinkedList() will be used to make a EduLinkedList type object
    EduLinkedList() { m_head = nullptr; }
    EduLinkedList(EduLinkedListNode *h) { m_head = h; }
    // InsertNodeAtHead() method will insert a LinkedListNode at head
    // of a linked list.
    void InsertNodeAtHead(EduLinkedListNode *node)
    {
        if (m_head != nullptr)
        {
            node->next = m_head;
            m_head = node;
        }
        else
        {
            m_head = node;
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
        EduLinkedListNode *temp = m_head;
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
        if (!head || left == right) {
            return head;
        }
    
        EduLinkedListNode* dummy = new EduLinkedListNode(0);
        dummy->next = head;
        EduLinkedListNode* prev = dummy;
    
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }
    
        EduLinkedListNode* curr = prev->next;
    
        for (int i = 0; i < right - left; i++) {
            EduLinkedListNode* nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }
        
        m_head = dummy->next;
        ToString();
        return dummy->next;
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