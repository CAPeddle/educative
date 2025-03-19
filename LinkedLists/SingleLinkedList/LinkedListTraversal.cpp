// Template for traversing a linked list


#include "LinkedListNode.h"
#include <iostream>

void TraverseLinkedList(std::unique_ptr<LinkedListNode> head){
    
    std::unique_ptr<LinkedListNode> current = std::move(head); 

    std::unique_ptr<LinkedListNode> nxt = nullptr; 

    while (current != nullptr){
      std::cout << current->data << "-> ";
      nxt = std::move(current->next);
      current = std::move(nxt);
    }
}

