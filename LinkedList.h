#include <iostream> 
using namespace std;

template<typename T>
struct Link {
    T data;
    Link *next;
};

template <typename T>
class LinkedList {
    private:
        Link<T> *head, *tail;
        int nItems;

    public:
        LinkedList();
        void insertFirst(T);
        void insertLast(T);
        void insertAt(int, T);
        void displayList();
        T removeFirst();
        T removeLast();
        T removeAt(int);
        int size();
        int top();
        bool isEmpty();
};

template <typename T> 
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    nItems = 0;
}

template <typename T> 
void LinkedList<T>::insertFirst(T item) {
    Link<T> *newLink = new Link<T>;
    newLink -> data = item;
    newLink -> next = head;
    head = newLink;
    nItems++;
}

template <typename T> 
void LinkedList<T>::insertLast(T item) {
    Link<T> *newLink = new Link<T>;
    newLink -> data = item;
    tail -> next = newLink;
    tail = newLink;
    nItems++;
}

template <typename T> 
void LinkedList<T>::insertAt(int index, T item) {
    Link<T> *newLink = new Link<T>;
    Link<T> *current = new Link<T>;
    Link<T> *prev = new Link<T>;

    current = head;
    for(int i = 0; i <= index; i++) {
        prev = current;
        current = current -> next;
    }

    newLink -> data = item;
    prev -> next = newLink;
    newLink -> next = current;
    nItems++;
}

template <typename T> 
T LinkedList<T>::removeFirst() {
    Link<T> *deleteLink = new Link<T>;
    deleteLink = head;
    head = head -> next;
    T value = deleteLink -> data;
    delete deleteLink;
    nItems--;
    return value;
}

template <typename T> 
T LinkedList<T>::removeLast() {
    Link<T> *current = new Link<T>;
    Link<T> *prev = new Link<T>;
    current = head;

    while(current -> next != nullptr) {
        prev = current;
        current = current -> next;
    }

    tail = prev;
    prev -> next = nullptr;
    T value = current -> data;
    delete current;
    nItems--;
    return value;
}

template <typename T> 
T LinkedList<T>::removeAt(int index) {
    Link<T> *current = new Link<T>;
    Link<T> *prev = new Link<T>;
    current = head;

    for(int i = 0; i < index; i++) {
        prev = current;
        current = current -> next;
    }

    T value = current -> data;
    prev -> next = current -> next;
    nItems--;
    return value;
}

template <typename T> 
int LinkedList<T>::size() {
    return nItems;
}

template <typename T> 
int LinkedList<T>::top() {
    return head -> data;
}

template <typename T> 
void LinkedList<T>::displayList() {
    Link<T> *current = new Link<T>;
    current = head;

    while(current != nullptr) {
        cout<<current -> data<<" ";
        current = current -> next;
    }
}

template <typename T> 
bool LinkedList<T>::isEmpty() {
    return head == nullptr;
}