// Helper function that calculates the sum of squared digits.
#include <cmath>
#include <iostream>
#include <vector>

#include "LinkedList.cpp"

bool DetectCycle(EduLinkedListNode* head) {
  // Replace this placeholder return statement with your code

  return false;
}

int main() {
  EduLinkedListNode* head = new EduLinkedListNode(1);
  head->next = new EduLinkedListNode(2);
  head->next->next = new EduLinkedListNode(3);
  head->next->next->next = new EduLinkedListNode(4);
  head->next->next->next->next = new EduLinkedListNode(5);
  head->next->next->next->next->next = new EduLinkedListNode(6);

  // Creating a cycle for testing
  head->next->next->next->next->next->next = head->next->next;

  if (DetectCycle(head)) {
    std::cout << "LinkedList has a cycle." << std::endl;
  } else {
    std::cout << "LinkedList does not have a cycle." << std::endl;
  }

  return 0;
}