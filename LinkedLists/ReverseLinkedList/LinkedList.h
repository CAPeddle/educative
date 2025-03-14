#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// #include "LinkedListForwardIterator.h"
#include "LinkedListNode.h"
#include <vector>
#include <string>
#include <memory>

// https://solarianprogrammer.com/2019/02/22/cpp-17-implementing-singly-linked-list-smart-pointers/

class LinkedList
{
public:
    LinkedList() { head = nullptr; }
    LinkedList(std::unique_ptr<LinkedListNode> &h) { head = std::move(h); }
    LinkedList(std::shared_ptr<LinkedListNode> &h) { head = h; }
    LinkedList(std::vector<int> &vec);
    LinkedList(LinkedList &list) = delete;
    LinkedList(const LinkedList &list) = delete;

    virtual ~LinkedList()
    {
        // TODO confirm this uses iterative instead of recursive destroy
        // std::cout << "destroying linkedlist \n";
    }

    static std::unique_ptr<LinkedList> CreateLinkedList(std::vector<int> &vec);

    void InsertNodeAtHead(std::shared_ptr<LinkedListNode> node);

    friend std::ostream &operator<<(std::ostream &os, const LinkedList &list);
    friend std::ostream &operator<<(std::ostream &os, const std::unique_ptr<LinkedList> &list);

    std::shared_ptr<LinkedListNode> head;
private:
};

#endif // LINKEDLIST_H