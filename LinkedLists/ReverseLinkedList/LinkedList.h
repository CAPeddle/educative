#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedListNode.h"
#include <vector>
#include <string>
#include <memory>

//https://solarianprogrammer.com/2019/02/22/cpp-17-implementing-singly-linked-list-smart-pointers/

// Template for the linked list
class EduLinkedList
{
public:
    // EduLinkedListNode *head = new EduLinkedListNode(0);

    std::unique_ptr<EduLinkedListNode> head;

    EduLinkedList() { head = nullptr; }
    EduLinkedList(std::unique_ptr<EduLinkedListNode> h) { head = std::move(h); }    

    virtual ~EduLinkedList() {}

    // InsertNodeAtHead() method will insert a LinkedListNode at head
    // of a linked list.
    void InsertNodeAtHead(std::unique_ptr<EduLinkedListNode> node);

    // CreateLinkedList() method will create the linked list using the
    // given integer array with the help of InsertAthead method.
    void CreateLinkedList(std::vector<int> &vec);

    // ToString() method will display the elements of linked list.
    std::string ToString();
};

#endif // LINKEDLIST_H