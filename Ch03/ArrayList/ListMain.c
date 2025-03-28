#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/*** ArrayList의 생성 및 초기화 ***/
	List list;
	int data;
	ListInit(&list);

	/*** 5개의 데이터 저장 ***/
	for (int i = 0; i < 94; i++)
		LInsert(&list, 0);

	/*** 저장된 데이터의 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));
	if (LFirst(&list, &data)) // 첫 번째 데이터 조회
	{
		printf("%d ", data);

		while (LNext(&list, &data)) // 두 번째 이후의 데이터 조회
			printf("%d ", data);
	}
	printf("\n\n");

	/*** 숫자 22을 탐색하여 모두 삭제 ***/
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

	/*** 삭제 후 저장된 데이터 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	printf("LADD start - index : %d, data : %d\n", 1, -9);
	if (LAdd(&list, 1, -9))
		printArr(&list);
	else
		printf("LADD failed\n");

	printf("LADD start - index : %d, data : %d\n", 2, -8);
	if (LAdd(&list, 2, -8))
		printArr(&list);
	else
		printf("LADD failed\n");

	printf("LADD start - index : %d, data : %d\n", 0, -1);
	if (LAdd(&list, 0, -1))
		printArr(&list);
	else
		printf("LADD failed\n");

	printf("LADD start - index : %d, data : %d\n", 5, -11);
	if (LAdd(&list, 5, -11))
		printArr(&list);
	else
		printf("LADD failed\n");

	printf("LADD start - index : %d, data : %d\n", 7, -19);
	if (LAdd(&list, 7, -19))
		printArr(&list);
	else
		printf("LADD failed\n");

	printf("LADD start - index : %d, data : %d\n", 98, -99);
	if (LAdd(&list, 98, -99))
		printArr(&list);
	else
		printf("LADD failed\n");
	return 0;
}