#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "ArrayList.h"

int main(void)
{
	List list;
	Point compPos;
	Point * ppos;

	ListInit(&list);

	/*** 4개의 데이터 저장 ***/
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 0);
	LInsert(&list, ppos);

	/*** 저장된 데이터의 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	/*** xpos가 2인 모든 데이터 삭제 ***/
	compPos.xpos=2;
	compPos.ypos=0;

	if(LFirst(&list, &ppos))
	{
		if(PointComp(ppos, &compPos)==1 || PointComp(ppos, &compPos) == 0) // 원래 리턴값 1인 부분만 지웠는데, 이는 작성자가 의도한 바가 아님, x값이 2인 경우 모두 삭제하려면 리턴값 0인 경우도 삭제해야함
		{
			ppos=LRemove(&list);
			free(ppos);
		}
		
		while(LNext(&list, &ppos)) 
		{
			if(PointComp(ppos, &compPos) == 1 || PointComp(ppos, &compPos) == 0)
			{
				ppos=LRemove(&list);
				free(ppos);
			}
		}
	}

	/*** 삭제 후 남은 데이터 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}