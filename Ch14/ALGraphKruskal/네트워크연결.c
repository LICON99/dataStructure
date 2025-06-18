/*
네트워크 연결

시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	256 MB	41488	27112	17635	65.526%
문제
도현이는 컴퓨터와 컴퓨터를 모두 연결하는 네트워크를 구축하려 한다. 하지만 아쉽게도 허브가 있지 않아 컴퓨터와 컴퓨터를 직접 연결하여야 한다. 그런데 모두가 자료를 공유하기 위해서는 모든 컴퓨터가 연결이 되어 있어야 한다. (a와 b가 연결이 되어 있다는 말은 a에서 b로의 경로가 존재한다는 것을 의미한다. a에서 b를 연결하는 선이 있고, b와 c를 연결하는 선이 있으면 a와 c는 연결이 되어 있다.)

그런데 이왕이면 컴퓨터를 연결하는 비용을 최소로 하여야 컴퓨터를 연결하는 비용 외에 다른 곳에 돈을 더 쓸 수 있을 것이다. 이제 각 컴퓨터를 연결하는데 필요한 비용이 주어졌을 때 모든 컴퓨터를 연결하는데 필요한 최소비용을 출력하라. 모든 컴퓨터를 연결할 수 없는 경우는 없다.

입력
첫째 줄에 컴퓨터의 수 N (1 ≤ N ≤ 1000)가 주어진다.

둘째 줄에는 연결할 수 있는 선의 수 M (1 ≤ M ≤ 100,000)가 주어진다.

셋째 줄부터 M+2번째 줄까지 총 M개의 줄에 각 컴퓨터를 연결하는데 드는 비용이 주어진다. 이 비용의 정보는 세 개의 정수로 주어지는데, 만약에 a b c 가 주어져 있다고 하면 a컴퓨터와 b컴퓨터를 연결하는데 비용이 c (1 ≤ c ≤ 10,000) 만큼 든다는 것을 의미한다. a와 b는 같을 수도 있다.

출력
모든 컴퓨터를 연결하는데 필요한 최소비용을 첫째 줄에 출력한다.

예제 입력 1
6
9
1 2 5
1 3 4
2 3 2
2 4 7
3 4 6
3 5 11
4 5 3
4 6 8
5 6 8
예제 출력 1
23*/

#include <stdio.h>

typedef struct Node
{ // 간선을 담을 구조체
	int x;
	int y;
	int v;
} Node;

void shell(Node v[], int m)
{ // shell 정렬
	int i, j, gap = m / 2;
	Node key;

	while (1)
	{
		if (gap % 2 == 0)
			gap++;
		for (i = gap; i < m; i++)
		{
			key = v[i];
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (key.v < v[j].v)
					v[j + gap] = v[j];
				else
					break;
			}
			v[j + gap] = key;
		}
		if (gap == 1)
			break;
		gap >>= 1;
	}
}

int find(int p[], int x)
{ // 노드가 속한 부분집합의 대표노드 찾기
	if (p[x] == x)
		return x;
	return p[x] = find(p, p[x]);
}

void merge(int p[], int x, int y)
{ // 두개의 노드의 부분집합 합치기
	x = find(p, x);
	y = find(p, y);
	if (x != y)
		p[x] = y;
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	int p[n + 1];
	Node v[m];
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &v[i].x, &v[i].y, &v[i].v);

	shell(v, m);

	int ans = 0;
	for (int i = 0; i < m; i++)
	{ // Krustal 알고리즘
		if (find(p, v[i].x) != find(p, v[i].y))
		{
			ans += v[i].v;
			merge(p, v[i].x, v[i].y);
		}
	}
	printf("%d", ans);
}