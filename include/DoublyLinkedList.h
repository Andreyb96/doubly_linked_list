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
	std::shared_ptr<Node> prevPtr = nullptr;
	std::shared_ptr<Node> nextPtr = nullptr;
};

class DoublyLinkedList
{
public:
	DoublyLinkedList();
	int Size();
	void AddNode(int value, int position, ErrorCode& err);
	void RemoveNode(int position, ErrorCode& err);
	void PrintList();
	std::shared_ptr<Node> Find(int value, ErrorCode& err);
	std::shared_ptr<Node> GetNode(int position);
	
private:
	int _size = 0;
	std::shared_ptr<Node> _head = nullptr;
	std::shared_ptr<Node> _tail = nullptr;
};

#endif // DOUBLY_LINKED_LIST_H