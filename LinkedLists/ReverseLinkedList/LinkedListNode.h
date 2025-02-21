#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

struct EduLinkedListNode
{
    EduLinkedListNode() = delete;

    int data;
    std::unique_ptr<EduLinkedListNode> next;
    
    explicit EduLinkedListNode(int d)
    {
        data = d;
        next = nullptr;
    }

};

#endif