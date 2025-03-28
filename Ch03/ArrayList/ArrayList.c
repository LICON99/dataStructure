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
		printf("Cannot store more data.\n");
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
	printf("LAdd start, index: %d, data: %d\n", index, data); // debugging message
	if (index < 0)
	{
		printf("LAdd failed : index < 0\n\n"); // Exception handling: index < 0
		return FALSE;
	}
	if (plist->numOfData <= index)
	{
		printf("LAdd failed : index >= numOfData\n\n"); // Exception handling: index >= numOfData
		return FALSE;
	}
	if (plist->numOfData == LIST_LEN)
	{
		printf("LAdd failed : the list has reached its storage limit(100) \n");
		return FALSE;
	}
	for (int i = plist->numOfData; i > index; i--) // Shift the elements of the array one position to the right from the specified index to the end.
		plist->arr[i] = plist->arr[i - 1];
	plist->arr[index] = data; // Add new data into the specified index
	plist->numOfData++;		  // Increase numOfData by 1 after adding.
	return TRUE;
}

void printArr(List *plist) // Print the list
{
	LData data;
	printf("Number of Data : %d \n", LCount(plist));
	if (LFirst(plist, &data))
	{
		printf("%d ", data);
		while (LNext(plist, &data))
			printf("%d ", data);
	}
	printf("\n\n");
}