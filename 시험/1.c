#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node *next;
} Node;

typedef struct _linkedList
{
	Node *head;
	Node *cur;
	Node *before;

	int numOfData;
	int (*comp)(LData d1, LData d2);
} LinkedList;
typedef LinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));
int LAdd(List *plist, int index, LData data);
void printList(List *plist);
int main()
{
    List list;
	int data1;
	ListInit(&list);
    int n,m;
    int dummy;
    int idx;
    scanf("%d %d",&n,&m);
    getchar();
    for(int i=0;i<n;i++)
    {

        scanf("%d",&idx);
        LInsert(&list,idx);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&idx);
        if(idx >=list.numOfData || idx < 0)
        {    printList(&list);
            continue;}
        LFirst(&list,&data1);
    for(int j=0;j<list.numOfData -(idx+1);j++)
        LNext(&list, &data1);
    LRemove(&list);
    printList(&list);

    }
}

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
	Node *newNode = (Node *)malloc(sizeof(Node)); // create new node.

	printf("LAdd start, index : %d, data : %d\n", index, data); // debugging message
	if (index < 0)												// if the index < 0, fail.
	{
		printf("LAdd failed : index < 0\n\n");
		return FALSE;
	}
	if (index >= plist->numOfData) // if the index >= numOfData, fail.
	{
		printf("LAdd failed : index >= numOfData\n\n");
		return FALSE;
	}

	plist->before = plist->head;
	plist->cur = plist->head->next; // reinit before and cur pointer
	for (int i = 0; i < index; i++)
	{
		plist->before = plist->cur;
		plist->cur = plist->cur->next;
	} // move before and cur pointer to index location
	newNode->data = data;
	newNode->next = plist->cur;	   // add a new node at the designated index.
	plist->before->next = newNode; // Link the newNode back and forth to existing nodes.
	plist->numOfData++;
	return TRUE; // if add succeeded, return TRUE
}

void printList(List *plist)
{
	LData data;
    int arr[15000];
    int i=0;
	if (LFirst(plist, &data))
	{
		arr[i++]=data;
		while (LNext(plist, &data))
			arr[i++]=data;
	}
    for(int j=i -1;j>=0;j--)
    printf("%d ",arr[j]);
	printf("\n");
}
