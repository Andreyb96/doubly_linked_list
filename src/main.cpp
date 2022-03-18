#include <DoublyLinkedList.h>
#include <cassert>

int main()
{
	ErrorCode err = OK;
	
	{ // AddNode UT
		DoublyLinkedList myList;
		myList.AddNode(1, -1, err);
		assert(err == INVALID_INPUT_PARAM);

		myList.AddNode(1, 0, err);
		assert(myList.GetNode(0)->value == 1);
		assert(err == OK);
		myList.AddNode(2, 1, err);
		assert(myList.GetNode(1)->value == 2);
		assert(err == OK);
		myList.AddNode(9, 2, err);
		assert(myList.GetNode(2)->value == 9);
		assert(err == OK);
		myList.AddNode(10, 3, err);
		assert(myList.GetNode(3)->value == 10);
		assert(err == OK);
		myList.AddNode(3, 2, err);
		assert(myList.GetNode(2)->value == 3);
		assert(err == OK);
		myList.AddNode(4, 3, err);
		assert(myList.GetNode(3)->value == 4);
		assert(err == OK);
		myList.AddNode(7, 4, err);
		assert(myList.GetNode(4)->value == 7);
		assert(err == OK);
		myList.AddNode(8, 5, err);
		assert(myList.GetNode(5)->value == 8);
		assert(err == OK);
		myList.AddNode(5, 4, err);
		assert(myList.GetNode(4)->value == 5);
		assert(err == OK);
		myList.AddNode(6, 5, err);
		assert(myList.GetNode(5)->value == 6);
		assert(err == OK);
		assert(myList.Size() == 10);

		for (auto i = 0; i < 10; i++)
		{
			assert(myList.GetNode(i)->value == i + 1);
			assert(err == OK);
		}
	}

	return 0;
}