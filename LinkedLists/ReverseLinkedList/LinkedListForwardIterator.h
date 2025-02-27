#ifndef LINKEDLISTFORWARDITERATOR_H
#define LINKEDLISTFORWARDITERATOR_H

#include <iostream>
#include <iterator>
#include <vector>
class SquareIterator
{
public:
    using iterator_category =
        std::forward_iterator_tag;
    using value_type = int;
    using difference_type = std::ptrdiff_t;
    using pointer = int *;
    using reference = int &;

    explicit SquareIterator(pointer ptr) : ptr(ptr) {}

    value_type operator*() const { return (*ptr) * (*ptr); }
    pointer operator->() { return ptr; }
    SquareIterator &operator++()
    {
        ++ptr;
        return *this;
    }

    SquareIterator operator++(int)
    {
        SquareIterator tmp = *this;
        ++ptr;
        return tmp;
    }

    SquareIterator &operator+=(difference_type diff)
    {
        ptr += diff;
        return *this;
    }
    SquareIterator operator+(difference_type diff) const
    {
        return SquareIterator(ptr + diff);
    }
    value_type operator[](difference_type diff) const
    {
        return *(ptr + diff) * *(ptr + diff);
    }
    bool operator!=(const SquareIterator &other) const
    {
        return ptr != other.ptr;
    }

private:
    pointer ptr;
};

#endif