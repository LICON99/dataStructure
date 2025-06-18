#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2)
		return 0; // d1�� ���� ������ �ռ���.
	else
		return 1; // d2�� ���� ������ �ռ��ų� ����.
}

int main(void)
{
	// List�� ���� �� �ʱ�ȭ  ////////////
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);

	// 5���� ������ ����  ///////////////
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);
	LInsert(&list, 18);

	// ����� �������� ��ü ��� ////////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// ���� 22�� �˻��Ͽ� ��� ���� ////////////
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

	// ���� �� ����� ������ ��ü ��� ////////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}