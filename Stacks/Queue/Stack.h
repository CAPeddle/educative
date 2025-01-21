#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> stackList;

public:
    bool isEmpty() {
        return stackList.empty();
    }

    int top() {
        if (isEmpty()) {
            return -1; // Assuming -1 indicates an empty stack
        }
        return stackList.back();
    }

    int size() {
        return stackList.size();
    }

    void push(int value) {
        stackList.push_back(value);
    }

    int pop() {
        if (isEmpty()) {
            return -1; // Assuming -1 indicates an empty stack
        }
        int top_value = stackList.back();
        stackList.pop_back();
        return top_value;
    }
};
#endif  // STACK_H      stackList.pop_back();