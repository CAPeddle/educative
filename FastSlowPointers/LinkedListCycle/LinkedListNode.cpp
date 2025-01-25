#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

struct EduLinkedListNode {
	int data;
	EduLinkedListNode * next;
	// LinkedListNode() will be used to make a LinkedListNode type object.
	EduLinkedListNode(int d) {
		data = d;
		next = nullptr;
	}
};

#endif // LINKEDLISTNODE_H