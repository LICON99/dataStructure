#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

// Initialize the list
void ListInit(List *plist)
{
	plist->head = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}

// Insert a new node at the front of the list
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

// Retrieve the first node's data
int LFirst(List *plist, Data *pdata)
{
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;

	return TRUE;
}

// Move to the next node and retrieve its data
int LNext(List *plist, Data *pdata)
{
	if (plist->cur == NULL)
		return LFirst(plist, pdata);

	if (plist->cur->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

// Move to the previous node and retrieve its data
int LPrevious(List *plist, Data *pdata)
{
	if (plist->cur == NULL)
		return FALSE;

	if (plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

// Return the total number of nodes
int LCount(List *plist)
{
	return plist->numOfData;
}

// Remove the current node and return its data
Data LRemove(List *plist)
{
	Node *rpos = plist->cur;
	Data remv = rpos->data;

	// Link the previous and next nodes to bypass the current node
	if (rpos->prev != NULL)
		rpos->prev->next = rpos->next;
	if (rpos->next != NULL)
		rpos->next->prev = rpos->prev;

	// Case: removing the first node (but the list has more than one node)
	if (rpos->next != NULL && rpos->prev == NULL)
		plist->head = rpos->next;

	// Case: removing the last remaining node in the list
	if (rpos->next == NULL && rpos->prev == NULL)
		plist->head = NULL;

	// Move the current pointer to the previous node
	plist->cur = rpos->prev;

	// Free the memory of the removed node
	free(rpos);
	(plist->numOfData)--;
	return remv;
}

// Print all the data in the list
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