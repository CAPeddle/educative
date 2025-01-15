#pragma once
struct EduLinkedListNode {
	int data;
	EduLinkedListNode * next;
	// LinkedListNode() will be used to make a LinkedListNode type object.
	EduLinkedListNode(int d) {
		data = d;
		next = nullptr;
	}
};