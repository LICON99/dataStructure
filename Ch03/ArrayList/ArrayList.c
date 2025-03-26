#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List *plist, LData data)
{
	if (plist->numOfData + 1 > LIST_LEN)
	{
		printf("더이상 저장할 수 없습니다.\n");
		return;
	}
	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List *plist, LData *pdata)
{
	if (plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List *plist, LData *pdata)
{
	if (plist->curPosition >= (plist->numOfData) - 1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List *plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List *plist)
{
	return plist->numOfData;
}

int LAdd(List *plist, int index, LData data)
{
	if (index < 0)
		return FALSE;
	if (plist->numOfData <= index || plist->numOfData == LIST_LEN)
		return FALSE;
	for (int i = plist->numOfData; i > index; i--)
		plist->arr[i] = plist->arr[i - 1];
	plist->numOfData++;
	plist->arr[index] = data;
	return TRUE;
}

void printArr(List *plist)
{
	LData data;
	printf("Num of Data : %d \n", LCount(plist));
	if (LFirst(plist, &data))
	{
		printf("%d ", data);
		while (LNext(plist, &data))
			printf("%d ", data);
	}
	printf("\n\n");
}