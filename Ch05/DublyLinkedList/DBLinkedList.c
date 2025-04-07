#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List * plist)
{
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head;
	if(plist->head != NULL)
		plist->head->prev = newNode;

	newNode->prev = NULL;
	plist->head = newNode;

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if(plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if(plist->cur->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LPrevious(List * plist, Data * pdata)
{
	if(plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

int LCount(List * plist)
{
	return plist->numOfData;
}

Data LRemove(List * plist, Data * data)
{
	Node * rpos = plist->cur;
	Data remv = rpos->data;
	/*case 1 : cur node is front and next is not empty*/
	if(plist->cur == plist->head && plist->cur->next!=NULL)
	{
		printf("case 1\n");
		*data=plist->cur->data;
		plist->head=plist->head->next;
		plist->head->prev == NULL;
		plist->cur=plist->head;
	}
	/* case 2 : prev is present and next is empty*/
	if(plist->cur->prev != NULL && plist->cur->next ==NULL)
	{
		printf("case 2\n");
		plist->cur=plist->cur->prev;
		plist->cur->next=NULL;
	}
	/*case 3 : cur node is only one node*/
	if(plist->cur->next == NULL && plist->cur->prev == NULL)
	{
		printf("case 3\n");
		*data=plist->cur->data;
		plist->cur=NULL;
		plist->head=NULL;
	}
	/*case 4 : prev and next are not empty*/
	if(plist->cur->next != NULL && plist->cur->prev != NULL)
	{
		printf("case 4\n");
		plist->cur->next->prev = plist->cur->prev;
		plist->cur->prev->next = plist ->cur->next;
		plist->cur=plist->cur->prev;
	}
	
	free(rpos);
	(plist->numOfData)--;
	return remv;
}