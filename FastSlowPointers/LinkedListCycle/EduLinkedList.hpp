#include "EduLinkedListNode.cpp"
#include <vector>
#pragma once
class EduLinkedList {
public:
	EduLinkedListNode* m_head;
	EduLinkedList() { m_head = nullptr; }
	// InsertNodeAtHead() method will insert a LinkedListNode at head
    // of a linked list.
	void InsertNodeAtHead(EduLinkedListNode *node) {
		if(m_head != nullptr){
			node -> next = m_head;
			m_head = node;
		} else {
			m_head = node;
		}
	}
	// CreateLinkedList() method will create the linked list using the
    // given integer array with the help of InsertAthead method.
	void CreateLinkedList(std::vector<int>& vec) {
		for (size_t i = vec.size() - 1; i >= 0; i--) {
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
        EduLinkedListNode *temp = m_head;
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