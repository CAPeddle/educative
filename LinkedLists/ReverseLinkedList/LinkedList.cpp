#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedListNode.cpp"

#include <string>
#include <vector>

// Definition for a Linked List node
// struct EduLinkedListNode {
//     int data;
//     EduLinkedListNode *next;
//     EduLinkedListNode(int d) {
//         data = d;
//         next = nullptr;
//     }
// };

#include <iostream>
#include <string>
#include <vector>

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
        return head;
    }

    EduLinkedListNode *ReverseBetween(EduLinkedListNode *head, int left, int right)
    {

        // Replace this placeholder return statement with your code
        return head;
    }

private:
EduLinkedListNode * TraverseLinkedListUntil(EduLinkedListNode *head, int position)
    {
        EduLinkedListNode *current = head;
        EduLinkedListNode *nxt = nullptr;
        while (current != nullptr)
        {
            std::cout << current->data << "-> ";
            nxt = current->next;
            current = nxt;
        }
        return head;
    }

};

#endif // LINKEDLIST_H