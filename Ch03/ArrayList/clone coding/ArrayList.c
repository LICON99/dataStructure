#include "ArrayList.h"
#include <stdio.h>
// typedef struct __ArrayList
// {
// 	LData arr[LIST_LEN];
// 	int numOfData;
// 	int curPosition;
// } ArrayList;

void ListInit(List *plist)
{
	plist->numOfData = 0;
	plist->curPosition = 0;// -1 이라고 했어야 함
	return;
}

void LInsert(List *plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("Storage lack\n");
		return;
	}
	plist->arr[plist->curPosition++] = data;
	plist->numOfData++;
	return;
}

int LFirst(List *plist, LData *pdata)
{
	if (plist->numOfData <= 0)
		return FALSE;
	plist->curPosition = 0;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

int LNext(List *plist, LData *pdata)
{
	plist->curPosition++;// 조건문 아래로 가야함.
	if (plist->curPosition >= plist->numOfData)
	return FALSE;
	
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List *plist)
{
	if (plist->numOfData <= 0)
		return FALSE;

	int cursor = plist->curPosition;
	LData delData = plist->arr[cursor];

	while (cursor < plist->numOfData - 1)
	{
		plist->arr[cursor] = plist->arr[cursor + 1];
		cursor++;
	}
	plist->numOfData--;
	plist->curPosition--; // 반복문에서 LNext함수로 커서 옮기며 LRemove 실행하는데, LNext함수는 cursor를 먼저 증가시킨 후 조회하기 때문에,
						  // 계속 현재 커서를 유지하며 제거하려면 curPosition - 1 해야 함.
	return delData;
}
int LCount(List *plist)
{
	return plist->numOfData;
}