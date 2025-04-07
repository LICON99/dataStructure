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
	LInsert(&list, 0);
	LInsert(&list, 77);
	LInsert(&list, 77);
	LInsert(&list, 77);

	// Print the list before deletion
	LPrint(&list, &data);

	// Remove all nodes with value 77
	if (LFirst(&list, &data))
	{
		while (1)
		{
			// Continuously remove 77 if found at current position
			while (data == 77 && list.cur != NULL)
				LRemove(&list, &data);

			// Exit if end of list is reached
			if (list.cur == NULL || list.cur->next == NULL)
				break;

			// Move to next 77 to remove
			while (data != 77)
			{
				if (!LNext(&list, &data))
					break;
			}
		}
	}

	// Print the list after removing all 77s
	LPrint(&list, &data);

	// Remove all remaining 0s to make the list empty
	if (LFirst(&list, &data))
	{
		while (1)
		{
			// Continuously remove 0 if found at current position
			while (data == 0 && list.cur != NULL)
				LRemove(&list, &data);

			// Exit if end of list is reached
			if (list.cur == NULL || list.cur->next == NULL)
				break;

			// Move to next 0 to remove
			while (data != 0)
			{
				if (!LNext(&list, &data))
					break;
			}
		}
	}

	// Print the list after removing all 0s; the list now should be empty
	LPrint(&list, &data);

	return 0;
}