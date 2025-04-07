#include <stdio.h>
#include "DBLinkedList.h"

void LPrint(List *list, Data *data);
int main(void)
{
	// ����� ���� ����Ʈ�� ���� �� �ʱ�ȭ  ///////
	List list;
	int data;
	ListInit(&list);

	// 8���� ������ ����  ///////
	LInsert(&list, 1);  LInsert(&list, 2);
	LInsert(&list, 3);  LInsert(&list, 4);
	LInsert(&list, 5);  LInsert(&list, 6);
	LInsert(&list, 7);  LInsert(&list, 8);

	// ����� �������� ��ȸ  ///////
LPrint(&list,&data);

	//LRemove 함수 구현
	if(LFirst(&list, &data))
	{
		while(list.cur->next!=NULL)
		{
			if(data==8 && list.cur == list.head)
			{
				printf("in\n");
				LRemove(&list, &data);
				continue;
			}
			// printf("out\n");
			LNext(&list, &data);
			// printf("numofdata : %d\n",list.numOfData);
			// LPrint(&list,&data);
			// printf(" cur data : %d\n",data);
		}
	}
	return 0;
}
		
void LPrint(List *list, Data *data)
{
	if(LFirst(list, data))
	{
		printf("print start\n");
		printf("%d ", *data);

		while(LNext(list, data)) 
			printf("%d ", *data);
		
		while(LPrevious(list, data))
			printf("%d ", *data);
		
		printf("\n\n");
	}
}