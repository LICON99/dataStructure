#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef int HData;
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp *comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph, PriorityComp pc);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data);
HData HDelete(Heap *ph);

#endif
#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "UsefulHeap.h"

typedef Heap PQueue;
typedef HData PQData;

void PQueueInit(PQueue *ppq, PriorityComp pc);
int PQIsEmpty(PQueue *ppq);

void PEnqueue(PQueue *ppq, PQData data);
PQData PDequeue(PQueue *ppq);

#endif
#include "PriorityQueue.h"
#include "UsefulHeap.h"

void PQueueInit(PQueue *ppq, PriorityComp pc)
{
	HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue *ppq)
{
	return HIsEmpty(ppq);
}

void PEnqueue(PQueue *ppq, PQData data)
{
	HInsert(ppq, data);
}

PQData PDequeue(PQueue *ppq)
{
	return HDelete(ppq);
}

#include "UsefulHeap.h"

void HeapInit(Heap *ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap *ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx)
{
	return idx / 2;
}

int GetLChildIDX(int idx)
{
	return idx * 2;
}

int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap *ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData)
		return 0;

	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);

	else
	{
		//	if(ph->heapArr[GetLChildIDX(idx)].pr
		//				> ph->heapArr[GetRChildIDX(idx)].pr)
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)],
					 ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap *ph, HData data)
{
	int idx = ph->numOfData + 1;

	while (idx != 1)
	{
		//	if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
		{
			break;
		}
	}

	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

HData HDelete(Heap *ph)
{
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		//	if(lastElem.pr <= ph->heapArr[childIdx].pr)
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}
#include <stdio.h>
int DataPriorityComp(int ch1, int ch2)
{
	return ch2 - ch1;
}
int main()
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);
	int n;
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &n);
		if (n != 0)
			PEnqueue(&pq, n);
		else
			printf("%d \n", PDequeue(&pq));
	}
	return 0;
}