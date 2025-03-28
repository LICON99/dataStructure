#include <stdio.h>
#include "DLinkedList.h"

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	for (int i = 100; i > 0; i--) // insert data
		LInsert(&list, i);

	printList(&list); // print all data of the list

	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list); // delete nodes if the data of the nodes is 22

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	printList(&list);

	if (LAdd(&list, 99, -99))
		printList(&list); // print all nodes
	else
		printf("LAdd failed\n");
	if (LAdd(&list, 0, -99))
		printList(&list);
	else
		printf("LAdd failed\n");
	if (LAdd(&list, 40, -99))
		printList(&list);
	else
		printf("LAdd failed\n");
	if (LAdd(&list, -1, -99)) // impossible case
		printList(&list);
	else
		printf("LAdd failed\n");
	if (LAdd(&list, 200, -99)) // impossible case
		printList(&list);
	else
		printf("LAdd failed\n");
	return 0;
}