#include <stdio.h>
#include <string.h>
#define MAX 1001

int graph[MAX][MAX]; // 인접 행렬로 그래프를 표현
int visited[MAX];	 // 방문 여부를 저장하는 배열
int queue[MAX];		 // BFS를 위한 큐

void DFS(int N, int V); // 깊이 우선 탐색 함수 선언
void BFS(int N, int V); // 너비 우선 탐색 함수 선언

int main()
{
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V); // 정점 수, 간선 수, 시작 정점 입력 받기

	int x, y, i, j;
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &x, &y); // 간선 입력 받기
		graph[x][y] = 1;		// 무방향 그래프이므로 양방향 모두 표시
		graph[y][x] = 1;
	}

	DFS(N, V); // DFS 실행
	printf("\n");
	memset(visited, 0, sizeof(int) * (N + 1)); // visited 배열 초기화
	BFS(N, V);								   // BFS 실행
	return 0;
}

void DFS(int N, int V)
{
	visited[V] = 1;	  // 현재 정점 방문 표시
	printf("%d ", V); // 방문한 정점 출력
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 0 && graph[V][i]) // 인접하고 방문하지 않았다면
		{
			DFS(N, i); // 그 정점으로 DFS 재귀 호출
		}
	}
	return;
}

void BFS(int N, int V)
{
	int front = -1, rear = -1, pop;
	printf("%d ", V);  // 시작 정점 출력
	visited[V] = 1;	   // 시작 정점 방문 표시
	queue[++rear] = V; // 시작 정점을 큐에 삽입

	while (front < rear)
	{
		pop = queue[++front]; // 큐에서 정점 꺼내기
		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == 0 && graph[pop][i]) // 인접하고 방문 안 한 정점
			{
				printf("%d ", i);  // 정점 출력
				visited[i] = 1;	   // 방문 표시
				queue[++rear] = i; // 큐에 삽입
			}
		}
	}
	return;
}