#include <memory>
#include <iostream>
#include <iterator>
#include <vector>
#include "LinkedList.h"
#include "LinkedListForwardIterator.h"

// ListForwardIterator::ListForwardIterator(ListForwardIterator &listIterator) : m_list(listIterator.m_list.head) {}
    // ListForwardIterator(const ListForwardIterator &listIterator): m_list(listIterator.m_list.head) {}

ListForwardIterator &ListForwardIterator::operator++()
    {
        ++ptr;
        return *this;
    }

    ListForwardIterator &ListForwardIterator::operator+=(difference_type diff)
    {
        ptr += diff;
        return *this;
    }

    ListForwardIterator::value_type ListForwardIterator::operator[](difference_type diff) const
    {
        return *(ptr + diff) * *(ptr + diff);
    }

    bool ListForwardIterator::operator!=(const ListForwardIterator &other) const
    {
        return ptr != other.ptr;
    }

    // ListForwardIterator ListForwardIterator::begin()
    // {
    //     return ListForwardIterator();
    // }
    
// ListForwardIterator LinkedList::begin()
// {
//     return ListForwardIterator(head);
// }