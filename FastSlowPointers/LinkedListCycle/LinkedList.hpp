#include "LinkedListNode.cpp"
#include <vector>
#pragma once
class EduLinkedList {
public:
	EduLinkedListNode* head;
	EduLinkedList() { head = nullptr; }
	// InsertNodeAtHead() method will insert a LinkedListNode at head
    // of a linked list.
	void InsertNodeAtHead(EduLinkedListNode *node) {
		if(head != nullptr){
			node -> next = head;
			head = node;
		} else {
			head = node;
		}
	}
	// CreateLinkedList() method will create the linked list using the
    // given integer array with the help of InsertAthead method.
	void CreateLinkedList(std::vector<int>& vec) {
		for (int i = vec.size() - 1; i >= 0; i--) {
			EduLinkedListNode *node = new EduLinkedListNode(vec[i]);
			InsertNodeAtHead(node);
		}
	}
	// returns the number of nodes in the linked list
    int GetLength(EduLinkedListNode* h){
        EduLinkedListNode *temp = h;
        int length = 0;
        while(temp!=nullptr){
            length+=1;
            temp = temp->next;
		}	
        return length;
    }

    // returns the node at the specified position(index) of the linked list
    EduLinkedListNode* GetNode(EduLinkedListNode* h, int pos){
        if (pos != -1){
            int p = 0;
            EduLinkedListNode* ptr = h;
            while (p < pos){
                ptr = ptr->next;
                p += 1;
            }
            return ptr;
        }
        return h;
    }


	// ToString() method will display the elements of linked list.
    std::string ToString(){
        std::string result = "";
        EduLinkedListNode *temp = head;
        while (temp != nullptr){
            result += std::to_string(temp->data);
            temp = temp->next;
            if (temp != nullptr){
                result += ", ";
            }
        }
        result += "";
        return result;
    }
};