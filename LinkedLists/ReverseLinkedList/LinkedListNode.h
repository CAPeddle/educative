#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include <memory>
#include <iostream>

struct LinkedListNode
{
    LinkedListNode() = delete;

    int data;
    std::unique_ptr<LinkedListNode> next;

    explicit LinkedListNode(int d) : data{d}, next{nullptr}
    {}

    ~LinkedListNode() {std::cout << "Destroy node with data: " << data << '\n';}
};

#endif