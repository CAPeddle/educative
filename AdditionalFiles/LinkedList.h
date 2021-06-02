#pragma once
#include <iostream>

class Node {
public:
  int data; //Data to store (could be int,string,object etc)
  Node* nextElement; //Pointer to next element

  Node() {
    //Constructor to initialize nextElement of newlyCreated Node
    nextElement = nullptr;
  }
};

class LinkedList {
private:
  Node* head;
public:

  LinkedList() {
    head = nullptr;
  }

  bool isEmpty() {
    if (head == nullptr) //Check whether the head points to null
      return true;
    else
      return false;
  }

  Node* getHead() {
    return head;
  }
  bool printList() {
    if (isEmpty()) {
      std::cout << "List is Empty!";
      return false;
    }
    Node* temp = head;
    std::cout << "List : ";

    while (temp != nullptr) {
      std::cout << temp->data << "->";
      temp = temp->nextElement;
    }
    std::cout << "null " << std::endl;
    return true;
  }

  bool insertAtHead(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->nextElement = head; //Linking newNode to head's nextNode
    head = newNode;
    //	cout << endl << value << " Inserted!    " ;

  }

  void insertAtTail(int value) {
    if (isEmpty()) { // inserting first element in list
      insertAtHead(value);
    }
    else {
      Node* newNode = new Node();
      Node* last = head;

      while (last->nextElement != nullptr) {
        last = last->nextElement;
      }

      newNode->data = value;
      std::cout << value << " Inserted!    ";
      newNode->nextElement = nullptr;
      last->nextElement = newNode;
    }
  }

  bool search(int value) { // function to check if element exists in list
    Node* temp = head;

    while (temp != nullptr) {
      if (temp->data == value) {
        return true;
      }
      temp = temp->nextElement;
    }
    return false;
  }

  bool deleteAtHead(int value) {

    bool deleted = false;
    if (isEmpty()) {
      std::cout << "List is Empty" << std::endl;
      return deleted;
    }
    //if list is not empty, start traversing it from the head
    Node* currentNode = head;
    Node* nextNode = head->nextElement; //nextNode point to head's nextElement

    if (currentNode->data == value) {
      currentNode = nextNode;
      head = currentNode;
      deleted = true;
      return deleted;
    }
    return deleted;
  }

  bool Delete(int value) {
    bool deleted = false; //returns true if the node is deleted, false otherwise

    if (isEmpty()) { //check if the list is empty
      std::cout << "List is Empty" << std::endl;
      return deleted; //deleted will be false
    }

    //if list is not empty, start traversing it from the head
    Node* currentNode = head; //currentNode to traverse the list
    Node* previousNode = nullptr; //previousNode starts from null

    if (currentNode->data == value) { // deleting value of head
      deleted = deleteAtHead(value);
      std::cout << value << " deleted!" << std::endl;
      deleted = true; // true because value found and deleted
      return deleted; //returns true if the node is deleted
    }

    //Traversing/Searching for Node to Delete
    while (currentNode != nullptr) {

      //Node to delete is found
      if (value == currentNode->data) {
        // pointing previousNode's nextElement to currentNode's nextElement
        previousNode->nextElement = currentNode->nextElement;
        deleted = true;
        break;
      }
      previousNode = currentNode;
      currentNode = currentNode->nextElement; // pointing current to current's nextElement
    }
    //deleted is true only when value is found and delted
    if (deleted == false) {
      std::cout << value << " does not exist!" << std::endl;
    }
    else {
      std::cout << value << " deleted!" << std::endl;
    }
    return deleted;
  } //end of delete()
};