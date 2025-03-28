#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List *plist)
{
	plist->head = (Node *)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List *plist, LData data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

void SInsert(List *plist, LData data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	Node *pred = plist->head;
	newNode->data = data;

	while (pred->next != NULL &&
		   plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}
	newNode->next = pred->next;
	pred->next = newNode;
	(plist->numOfData)++;
}

void LInsert(List *plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List *plist, LData *pdata)
{
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List *plist, LData *pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List *plist)
{
	Node *rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List *plist)
{
	return plist->numOfData;
}

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}

int LAdd(List *plist, int index, LData data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));

	printf("LAdd index : %d, data : %d\n", index, data); // debugging message
	if (index < 0)
		return FALSE;
	if (index >= plist->numOfData)
		return FALSE;
	plist->before = plist->head; // init before and cur
	plist->cur = plist->head->next;
	for (int i = 0; i < index; i++)
	{
		plist->before = plist->cur;
		plist->cur = plist->cur->next;
	} // move to index location
	newNode->data = data;
	newNode->next = plist->cur;
	plist->numOfData++;
	plist->before->next = newNode; // Link the newNode back and forth to existing nodes.
	return TRUE;
}

void printList(List *plist)
{
	LData data;

	printf("Number of data = %d\n", plist->numOfData);
	if (LFirst(plist, &data))
	{
		printf("%d ", data);
		while (LNext(plist, &data))
			printf("%d ", data);
	}
	printf("\n\n");
}