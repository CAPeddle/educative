#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedListNode.h"
#include <vector>
#include <string>
#include <memory>

//https://solarianprogrammer.com/2019/02/22/cpp-17-implementing-singly-linked-list-smart-pointers/

// Template for the linked list
class LinkedList
{
public:
    std::unique_ptr<LinkedListNode> head;

    LinkedList() { head = nullptr; }
    LinkedList(std::unique_ptr<LinkedListNode> h) { head = std::move(h); }    
    LinkedList(std::vector<int> &vec);

    virtual ~LinkedList() {}

    // CreateLinkedList() method will create the linked list using the
    // given integer array with the help of InsertAthead method.
    static std::unique_ptr<LinkedList> CreateLinkedList(std::vector<int> &vec);

    // InsertNodeAtHead() method will insert a LinkedListNode at head
    // of a linked list.
    void InsertNodeAtHead(std::unique_ptr<LinkedListNode> node);



    // ToString() method will display the elements of linked list.
    std::string ToString();

    friend std::ostream& operator<<(std::ostream &os, const LinkedList &list);

};

#endif // LINKEDLIST_H