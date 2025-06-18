/*최소 스패닝 트리

시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	128 MB	111237	39891	23366	37.749%
문제
그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.

최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.

입력
첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다. 다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.

그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다. 최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.

출력
첫째 줄에 최소 스패닝 트리의 가중치를 출력한다.

예제 입력 1
3 3
1 2 1
2 3 2
1 3 3
예제 출력 1
3*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100001
#pragma warning(disable : 4996)

typedef struct edge
{ // 그래프 간선 정의
	int start, end, weight;
} edge;

int compare(const void *a, const void *b)
{ // 퀵 정렬 비교 함수 재정의
	struct edge *x = (struct edge *)a;
	struct edge *y = (struct edge *)b;
	return x->weight - y->weight;
}

/* 전역 변수 선언 */
int parent[MAX];
edge E[MAX];

int find(int x)
{
	if (x == parent[x])
	{
		return x;
	}
	else
	{
		return parent[x] = find(parent[x]);
	}
}

void union_find(int a, int b)
{
	a = parent[a];
	b = parent[b];
	parent[a] = b;
}

int main()
{
	int v, e;

	scanf("%d%d", &v, &e);

	for (int i = 0; i < e; i++)
	{ // 간선 삽입
		int temp1, temp2, temp3;
		scanf("%d%d%d", &temp1, &temp2, &temp3);
		E[i].start = temp1;
		E[i].end = temp2;
		E[i].weight = temp3;
	}

	for (int i = 1; i <= v; i++)
	{
		parent[i] = i;
	}

	qsort(E, e, sizeof(struct edge), compare); // 가중치를 기준으로 정렬

	int j = 0;
	int accepted = 0; // 정점 접근
	int a, b;
	int result = 0;
	while (accepted != v - 1)
	{ // 크루스칼 알고리즘 적용
		a = E[j].start;
		b = E[j].end;
		if (find(a) != find(b))
		{
			union_find(a, b);
			accepted++;
			result += E[j].weight;
		}
		j++;
	}
	printf("%d", result);
	return 0;
}