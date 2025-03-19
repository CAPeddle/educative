#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include <memory>
#include <iostream>
#include <vector>

class LinkedListNode final
{
public:
    LinkedListNode() = delete;
    LinkedListNode(LinkedListNode &other) = delete;
    LinkedListNode(const LinkedListNode &other) = delete;

    explicit LinkedListNode(int d) : data{d}, next{nullptr}
    {
        // std::cout << "Create node with data: " << data << '\n';
    }

    ~LinkedListNode()
    {
        if (next)
        {
            std::vector<std::unique_ptr<LinkedListNode>> nodes;
            // std::cout << "Capture node with data: " << data << '\n';
            nodes.push_back(std::move(next));
            while (nodes.back()->next)
            {
                // std::cout << "Capture node with data: " << nodes.back()->data << '\n';
                nodes.push_back(nodes.back()->next);
            }
        }

        // std::cout << "Destroy final node with data: " << data << '\n';
    }

    // friend std::ostream &operator<<(std::ostream &os, const LinkedListNode &node)
    // {
    //     os << "[";
    //     os << node.data << ' ';

    //     LinkedListNode *next_node = (node.next).get();
    //     while (next_node)
    //     {
    //         os << next_node->data << ' ';
    //         next_node = next_node->next.get();
    //     }
    //     os << "]";
    //     return os;
    // }

    // friend std::ostream &operator<<(std::ostream &os, const std::unique_ptr<LinkedListNode> &node)
    // {
    //     LinkedListNode *head = node.get();
    //     os << "[";
    //     while (head)
    //     {
    //         os << head->data << ' ';
    //         head = head->next.get();
    //     }
    //     os << "]";
    //     return os;
    // }

    friend class LinkedList;

    int data;
    std::unique_ptr<LinkedListNode> next;
private:

    // LinkedListNode(LinkedListNode &&other) : data(0), next(nullptr)
    // {
    //     data = other.data;
    //     next = std::move(other.next);

    //     other.data = 0;
    //     other.next = nullptr;
    // }

    // LinkedListNode &operator=(LinkedListNode &&other)
    // {
    //     if (this != &other)
    //     {
    //         next.release();

    //         data = other.data;
    //         next = std::move(other.next);

    //         other.data = 0;
    //         other.next = nullptr;
    //     }
    //     return *this;
    // }
};

#endif