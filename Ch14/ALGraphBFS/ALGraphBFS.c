#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphBFS.h"	   // 그래프 관련 헤더
#include "DLinkedList.h"   // 이중 연결 리스트 관련 헤더
#include "CircularQueue.h" // 원형 큐 관련 헤더

int WhoIsPrecede(int data1, int data2); // 정렬 기준 함수 선언

// 그래프 초기화
void GraphInit(ALGraph *pg, int nv)
{
	int i;

	// 정점 수 만큼 인접 리스트 배열 생성
	pg->adjList = (List *)malloc(sizeof(List) * nv);
	pg->numV = nv;
	pg->numE = 0; // 간선 수는 처음에 0

	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));				  // 각 리스트 초기화
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede); // 정렬 기준 함수 설정 (오름차순)
	}

	// 방문 정보를 저장할 배열을 할당하고 0으로 초기화
	pg->visitInfo = (int *)malloc(sizeof(int) * pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

// 그래프 메모리 해제
void GraphDestroy(ALGraph *pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList); // 인접 리스트 메모리 해제

	if (pg->visitInfo != NULL)
		free(pg->visitInfo); // 방문 정보 메모리 해제
}

// 간선 추가 (무방향 그래프이므로 양쪽에 모두 추가)
void AddEdge(ALGraph *pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV); // fromV -> toV
	LInsert(&(pg->adjList[toV]), fromV); // toV -> fromV
	pg->numE += 1;						 // 간선 수 증가
}

// 그래프의 간선 정보 출력
void ShowGraphEdgeInfo(ALGraph *pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c의 인접 정점: ", i + 65); // 정점 이름을 알파벳으로 출력

		if (LFirst(&(pg->adjList[i]), &vx)) // 첫 번째 정점 출력
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx)) // 다음 정점들 출력
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

// 인접 정점 정렬 기준 함수 (작은 값을 우선)
int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}

// 정점 방문 처리 함수
int VisitVertex(ALGraph *pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0) // 아직 방문하지 않았다면
	{
		pg->visitInfo[visitV] = 1;	// 방문 처리
		printf("%c ", visitV + 65); // 정점 출력
		return TRUE;
	}
	return FALSE; // 이미 방문한 경우
}

// BFS: 너비 우선 탐색
void BFShowGraphVertex(ALGraph *pg, int startV)
{
	Queue queue;
	int visitV = startV;
	int nextV;

	QueueInit(&queue); // 큐 초기화

	VisitVertex(pg, visitV); // 시작 정점 방문

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) // 인접 정점 탐색 시작
	{
		if (VisitVertex(pg, nextV) == TRUE)
			Enqueue(&queue, nextV); // 방문한 정점은 큐에 삽입

		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
		{
			if (VisitVertex(pg, nextV) == TRUE)
				Enqueue(&queue, nextV); // 나머지 인접 정점들도 큐에 삽입
		}

		if (QIsEmpty(&queue) == TRUE) // 큐가 비었으면 탐색 종료
			break;
		else
			visitV = Dequeue(&queue); // 큐에서 다음 정점을 꺼냄
	}

	// 방문 정보 초기화 (다음 탐색을 위해)
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}