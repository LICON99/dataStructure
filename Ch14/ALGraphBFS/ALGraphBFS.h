#ifndef __AL_GRAPH_BFS__
#define __AL_GRAPH_BFS__

#include "DLinkedList.h"

// 정점의 이름을 상수화
enum
{
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J
};

// 인접 리스트 기반 그래프 구조체 정의
typedef struct _ual
{
	int numV;		// 정점의 수
	int numE;		// 간선의 수
	List *adjList;	// 인접 리스트 배열
	int *visitInfo; // 정점 방문 여부 저장 배열
} ALGraph;

// 그래프 초기화
void GraphInit(ALGraph *pg, int nv);

// 그래프 메모리 해제
void GraphDestroy(ALGraph *pg);

// 간선 추가
void AddEdge(ALGraph *pg, int fromV, int toV);

// 디버깅용 함수: 간선 정보 출력
void ShowGraphEdgeInfo(ALGraph *pg);

// BFS: 너비 우선 탐색
void BFShowGraphVertex(ALGraph *pg, int startV);

#endif