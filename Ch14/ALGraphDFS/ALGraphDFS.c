#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2);

// 그래프 초기화
void GraphInit(ALGraph *pg, int nv)
{
	int i;

	// 정점 개수만큼 인접 리스트 배열 생성
	pg->adjList = (List *)malloc(sizeof(List) * nv);
	pg->numV = nv;
	pg->numE = 0; // 초기 간선 수는 0

	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));				  // 각 정점에 대한 리스트 초기화
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede); // 오름차순 정렬
	}

	// 방문 정보 배열 생성 및 초기화 (모든 정점 미방문)
	pg->visitInfo = (int *)malloc(sizeof(int) * pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

// 그래프 메모리 해제
void GraphDestroy(ALGraph *pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

// 간선 추가 (양방향)
void AddEdge(ALGraph *pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV); // from → to
	LInsert(&(pg->adjList[toV]), fromV); // to → from
	pg->numE += 1;
}

// 그래프 간선 정보 출력
void ShowGraphEdgeInfo(ALGraph *pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c와 연결된 정점: ", i + 65); // 정점 번호를 문자로 출력 (A, B, C...)

		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

// 오름차순 정렬 함수: 작은 수가 우선
int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0; // data1이 앞
	else
		return 1; // data2가 앞
}

// 정점 방문 처리 및 출력
int VisitVertex(ALGraph *pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65); // 방문 정점 출력 (A, B, C...)
		return TRUE;
	}

	return FALSE;
}

// 깊이 우선 탐색 (DFS)
void DFShowGraphVertex(ALGraph *pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);

	VisitVertex(pg, visitV); // 시작 정점 방문
	SPush(&stack, visitV);	 // 스택에 push

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE)
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE)
		{
			if (SIsEmpty(&stack) == TRUE) // 스택이 비면 탐색 종료
				break;
			else
				visitV = SPop(&stack); // 이전 정점으로 되돌아감
		}
	}

	// 방문 정보 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}