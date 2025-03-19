#ifndef LINKEDLISTFORWARDITERATOR_H
#define LINKEDLISTFORWARDITERATOR_H

#include <memory>
#include <iostream>
#include <iterator>
#include <vector>
#include "LinkedList.h"
#include "LinkedListNode.h"

// https://www.reddit.com/r/cpp_questions/comments/v8ufok/linked_list_and_unique_pointers/

class ListForwardIterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = int; // for now the data type in the list node is an int
    using pointer = value_type *;
    using reference = value_type &;

    // ListForwardIterator(ListForwardIterator &listIterator) : m_list(listIterator.m_list.head) {}
    // ListForwardIterator(const ListForwardIterator &listIterator): m_list(listIterator.m_list.head) {}

    explicit ListForwardIterator(std::unique_ptr<LinkedListNode> &head) : m_list(head)
    {
        std::cout << "ListForwardIterator constructor from unique list node \n";
    }

    value_type operator*() const { return (*ptr) * (*ptr); }
    pointer operator->() { return ptr; }
    ListForwardIterator &operator++();

    // ListForwardIterator operator++(int)
    // {
    //     ListForwardIterator tmp = *this;
    //     ++ptr;
    //     return tmp;
    // }
    ListForwardIterator &operator+=(difference_type diff);
    // ListForwardIterator operator+(difference_type diff) const
    // {
    //     return ListForwardIterator(ptr + diff);
    // }
    value_type operator[](difference_type diff) const;
    bool operator!=(const ListForwardIterator &other) const;

    virtual ~ListForwardIterator()
    {
        // move next pointer back to list
        //  OR go to end and prune/delete it there is no recursive stack
        // https://youtu.be/JfmTagWcqoE?list=TLPQMDQwMzIwMjW_Rz75q4yTkw&t=1219
    }

    static ListForwardIterator begin();
private:
    LinkedList m_list;
    // std::unique_ptr<LinkedListNode> m_node;
    pointer ptr;
};

#endif