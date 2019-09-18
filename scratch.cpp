#include <iostream> 
#include "LinkedList.h"

int main() {
    LinkedList<int> list;
    list.insertFirst(4);
    list.insertFirst(10);
    list.displayList();
    return 0;
}