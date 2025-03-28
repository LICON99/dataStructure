#include <stdio.h>
#include "DLinkedList.h"

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	for (int i = 100; i >= 0; i--)
		LInsert(&list, i);
	printf("number of data: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	printf("number of data: %d \n", LCount(&list));
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	if (LAdd(&list, 99, -99)) //
		printList(&list);	  // print all nodes
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
	if (LAdd(&list, -1, -99)) // when index < 0
		printList(&list);
	else
		printf("LAdd failed\n");
	if (LAdd(&list, 200, -99)) // when index > number of data
		printList(&list);
	else
		printf("LAdd failed\n");
	return 0;
} // 이 텍스트는 한글입니다. 윈도우에서 곧 깨질 텍스트이죠.