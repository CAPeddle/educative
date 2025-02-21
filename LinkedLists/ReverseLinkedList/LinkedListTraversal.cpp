// Template for traversing a linked list


#include "LinkedListNode.h"
#include <iostream>

void TraverseLinkedList(std::unique_ptr<EduLinkedListNode> head){
    
    std::unique_ptr<EduLinkedListNode> current = std::move(head); 

    std::unique_ptr<EduLinkedListNode> nxt = nullptr; 

    while (current != nullptr){
      std::cout << current->data << "-> ";
      nxt = std::move(current->next);
      current = std::move(nxt);
    }
}

