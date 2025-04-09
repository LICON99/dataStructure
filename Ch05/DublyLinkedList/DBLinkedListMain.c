#include <stdio.h>
#include "DBLinkedList.h"

int main(void)
{
	List list;
	int data;

	// Initialize the list
	ListInit(&list);

	// Insert multiple values into the list
	LInsert(&list, 77);
	LInsert(&list, 77);
	LInsert(&list, 0);
	LInsert(&list, 77);
	LInsert(&list, 0);
	LInsert(&list, 0);
	LInsert(&list, 0);
	LInsert(&list, 0);
	LInsert(&list, 0);
	LInsert(&list, 77);
	LInsert(&list, 0);
	LInsert(&list, 77);
	LInsert(&list, 0);
	LInsert(&list, 0);
	LInsert(&list, 0);
	LInsert(&list, 77);
	LInsert(&list, -1);
	LInsert(&list, 0);
	LInsert(&list, 77);
	LInsert(&list, 77);
	LInsert(&list, 77);

	// Print the list before any deletions
	LPrint(&list, &data);

	// Remove all nodes containing the value 77
	if (LFirst(&list, &data))
	{
		if (data == 77)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 77)
				LRemove(&list);
		}
	}

	// Print the list after removing all 77s
	LPrint(&list, &data);

	// Remove all nodes containing the value 0
	if (LFirst(&list, &data))
	{
		if (data == 0)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 0)
				LRemove(&list);
		}
	}

	// Print the list after removing all 0s; only one node with -1 should remain
	LPrint(&list, &data);

	// Remove the node containing -1
	if (LFirst(&list, &data))
	{
		if (data == -1)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == -1)
				LRemove(&list);
		}
	}

	// Print the list; it should now be empty
	LPrint(&list, &data);
	return 0;
}