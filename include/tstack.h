// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
    T arr[size];
    int top;
public:
    TStack(): top(-1) {}
    void push(T value) {
        if (isFull())
            throw std::string("Stack is Full!");
        else arr[++top] = value;
    }
    const T& pop() {
        if (isEmpty())
            throw std::string("Stack is Empty!");
        else return arr[top--];
    }
    const T& peek() {
        if (isEmpty())
            throw std::string("Stack is Empty!");
        else return arr[top];
    }
    bool isEmpty() const {
        return -1 == top;
    }
    bool isFull() const {
        return top == size - 1;
    }
};

#endif  // INCLUDE_TSTACK_H_
