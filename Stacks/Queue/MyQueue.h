#include "Stack.h"

class MyQueue {

private:
    Stack stack1;
    Stack stack2;

public:
    void push(int x) {
        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }

        stack1.push(x);

        while (!stack2.isEmpty()) {
            stack1.push(stack2.pop());
        }
    }

    int pop() {
        return stack1.pop();
    }

    int peek() {
        return stack1.top();
    }

    bool empty() {
        return stack1.isEmpty();
    }
};