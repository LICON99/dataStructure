#include <stdio.h>
#include "DBDLinkedList.h"

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	// 8���� ������ ���� ///////
	LInsert(&list, 1);  LInsert(&list, 2);
	LInsert(&list, 3);  LInsert(&list, 4);
	LInsert(&list, 5);  LInsert(&list, 6);
	LInsert(&list, 7);  LInsert(&list, 8);

	// ����� �������� ��ȸ ///////
	if(LFirst(&list, &data))
	{
		printf("%d ", data);

		while(LNext(&list, &data)) 
			printf("%d ", data);
		
		printf("\n");
	}

	// 2�� ��� ���� ���� ///////


	// ����� �������� �� ��ȸ ///////
	if(LFirst(&list, &data))
	{
		printf("%d ", data);

		while(LNext(&list, &data)) 
			printf("%d ", data);
		
		printf("\n\n");
	}

	return 0;
}