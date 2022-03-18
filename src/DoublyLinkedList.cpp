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

void DoublyLinkedList::RemoveNode(int position, ErrorCode& err)
{
	err = OK;
	if (_size == 0)
	{
		err = EMPTY_LIST;
		return;
	}

	if (position < 0 || position >= _size)
	{
		err = INVALID_INPUT_PARAM;
		return;
	}

	auto& tmpNode = GetNode(position);

	if (tmpNode->prevPtr == nullptr)
	{
		_head = GetNode(position + 1);
		tmpNode->nextPtr = nullptr;
	}
	else if (tmpNode->nextPtr == nullptr)
	{
		_tail = GetNode(position + 1);
		tmpNode->prevPtr = nullptr;
	}
	else
	{
		auto& prevNode = GetNode(position - 1);
		auto& postNode = GetNode(position + 1);
		tmpNode->prevPtr = nullptr;
		tmpNode->nextPtr = nullptr;
		prevNode->nextPtr = postNode;
		postNode->prevPtr = prevNode;
	}

	_size--;
}

void DoublyLinkedList::PrintList()
{
	for (auto i = 0; i < _size; i++)
	{
		auto node = GetNode(i);
		std::cout << "Position: " << i << "; Value: " << node->value << std::endl;
	}
}

std::shared_ptr<Node> DoublyLinkedList::Find(int value, ErrorCode& err)
{
	err = OK;
	if (_size == 0)
	{
		err = EMPTY_LIST;
		return nullptr;
	}
	auto node = _head;

	while (node != nullptr)
	{
		if (node->value == value)
		{
			return node;
		}
		node = node->nextPtr;
	}

	return node;
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