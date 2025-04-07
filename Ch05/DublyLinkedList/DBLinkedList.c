#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List *plist)
{
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List *plist, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head;
	if (plist->head != NULL)
		plist->head->prev = newNode;

	newNode->prev = NULL;
	plist->head = newNode;

	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List *plist, Data *pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LPrevious(List *plist, Data *pdata)
{
	if (plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

int LCount(List *plist)
{
	return plist->numOfData;
}

Data LRemove(List *plist, Data *data)
{
	Node *rpos = plist->cur;
	Data remv = rpos->data;

	// If the current node is the head, move the head to the next node
	if (rpos == plist->head)
		plist->head = rpos->next;

	// Connect the previous and next nodes of the current node
	if (rpos->prev != NULL)
		rpos->prev->next = rpos->next;
	if (rpos->next != NULL)
		rpos->next->prev = rpos->prev;

	// Save the data of the next node (if it exists)
	if (plist->cur->next != NULL)
		*data = plist->cur->next->data;

	// Move the current pointer to the next node
	plist->cur = plist->cur->next;

	// Remove the rpos data
	free(rpos);
	(plist->numOfData)--;
	return remv;
}

void LPrint(List *plist, Data *data)
{
	printf("numOfData : %d\n", LCount(plist));

	if (LFirst(plist, data))
	{
		printf("%d ", *data);
		while (LNext(plist, data))
			printf("%d ", *data);
		printf("\n\n");
	}
}