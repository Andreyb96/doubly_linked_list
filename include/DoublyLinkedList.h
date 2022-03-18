#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <memory>

#include <ErrorCode.h>

struct Node
{
	Node(int value) :
		value(value)
	{}
		
	int value;
	std::shared_ptr<Node> ptr = nullptr;
};

class DoublyLinkedList
{
public:
	DoublyLinkedList();

private:

private:
	int _size = 0;
	std::shared_ptr<Node> _head = nullptr;
};

#endif // DOUBLY_LINKED_LIST_H