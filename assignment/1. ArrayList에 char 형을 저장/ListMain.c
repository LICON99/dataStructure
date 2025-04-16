#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/*** ArrayList�� ���� �� �ʱ�ȭ ***/
	List list;
	char data;
	ListInit(&list);

	/*** 5���� ������ ���� ***/
	LInsert(&list,'1');  LInsert(&list, '1');
	LInsert(&list, '2');  LInsert(&list, '2');
	LInsert(&list, '3');

	/*** ����� �������� ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if(LFirst(&list, &data))    // ù ��° ������ ��ȸ
	{
		printf("%c ", data);
		
		while(LNext(&list, &data))    // �� ��° ������ ������ ��ȸ
			printf("%c ", data);
	}
	printf("\n\n");

	/*** ���� 22�� Ž���Ͽ� ��� ���� ***/
	if(LFirst(&list, &data))
	{
		if (data == '2')
			LRemove(&list);
		
		while(LNext(&list, &data))
		{
			if (data == '2')
				LRemove(&list);
		}
	}

	/*** ���� �� ����� ������ ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%c ", data);
		
		while(LNext(&list, &data))
			printf("%c ", data);
	}
	printf("\n\n");
	return 0;
}