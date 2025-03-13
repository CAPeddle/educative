#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include <memory>
#include <iostream>
#include <vector>

#include "LinkedList.h"

struct LinkedListNode
{
    LinkedListNode() = delete;
    LinkedListNode(LinkedListNode &other) = delete;
    LinkedListNode(const LinkedListNode &other) = delete;

    explicit LinkedListNode(int d) : data{d}, next{nullptr}
    {
        std::cout << "Create node with data: " << data << '\n';
    }

    ~LinkedListNode()
    {        
        if (next)
        {
            std::vector<std::unique_ptr<LinkedListNode>> nodes;
            std::cout << "Capture node with data: " << data << '\n';
            nodes.push_back(std::move(next));
            while (nodes.back()->next)
            {
                std::cout << "Capture node with data: " << nodes.back()->data << '\n';
                nodes.push_back(std::move(nodes.back()->next));
            }
        }
                
        std::cout << "Destroy final node with data: " << data << '\n';
    }

    int data;
    std::unique_ptr<LinkedListNode> next;
};

#endif