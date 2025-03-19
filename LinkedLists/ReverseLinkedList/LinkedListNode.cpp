#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

struct EduLinkedListNode
{
    int data;
    EduLinkedListNode *next;
    EduLinkedListNode(int d)
    {
        data = d;
        next = nullptr;
    }
};

#endif