#include "DoublyLinkedList.h"

#include <iostream>

DoublyLinkedList::DoublyLinkedList()
{}

void DoublyLinkedList::AddNode(int value, int position, ErrorCode& err)
{
	err = OK;

	if (position < 0)
	{
		err = INVALID_INPUT_PARAM;
		return;
	}

	if (position >= _size)
	{
		position = _size;
	}

	auto& prevNode = GetNode(position - 1);
	auto& postNode = GetNode(position);
	auto newNode = std::make_shared<Node>(value);

	if (prevNode == nullptr && postNode == nullptr)
	{
		_head = newNode;
		_tail = newNode;
	}
	else if (prevNode == nullptr)
	{
		_head = newNode;
		_head->nextPtr = postNode;
		postNode->prevPtr = _head;
	}
	else if (postNode == nullptr)
	{
		_tail = newNode;
		_tail->prevPtr = prevNode;
		prevNode->nextPtr = newNode;
	}
	else
	{
		newNode->nextPtr = postNode;
		newNode->prevPtr = prevNode;
		prevNode->nextPtr = newNode;
		postNode->prevPtr = newNode;
	}
	_size++;
}

std::shared_ptr<Node> DoublyLinkedList::GetNode(int position)
{
	if (position < 0 && position >= _size)
	{
		return nullptr;
	}

	auto tmpNode = _head;

	for (auto i = 0; i < position; i++)
	{
		tmpNode = tmpNode->nextPtr;
	}

	return tmpNode;
}

int DoublyLinkedList::Size()
{
	return _size;
}