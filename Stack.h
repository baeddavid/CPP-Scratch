#include <stdio.h>      /* printf, fopen */
#include <stdlib.h>  
#include <iostream>
#define SIZE 10

template <typename T> 
class Stack {
    private:
        T *arr;
        int top;
        int capacity;
    public:
        Stack(int size = SIZE);
        void push(T);
        T pop();
        T peek();
        int size();
        bool isEmpty();
        bool isFull();
};

template <typename T> 
Stack<T>::Stack(int size) {
    arr = new T[size];
    capacity = size;
    top = -1;
}

template <typename T> 
void Stack<T>::push(T item) {
    if(isFull())
        exit(EXIT_FAILURE);
    arr[++top] = item;
}

template <typename T> 
T Stack<T>::pop() {
    if(isEmpty())
        exit(EXIT_FAILURE);
    return arr[top--];
}

template <typename T> 
T Stack<T>::peek() {
    if(!isEmpty())
        return arr[top];
}

template <typename T> 
bool Stack<T>::isEmpty() {
    return top == -1;
}

template <typename T> 
bool Stack<T>::isFull() {
    return top == capacity - 1;
}