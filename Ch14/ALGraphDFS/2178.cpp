/*
미로 탐색 성공

시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	192 MB	241188	113619	71025	45.415%
문제
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.*/
#include <stdio.h>
using namespace std;

/*

4 6
101111
101010
101111
111011

*/

int N, M;
char Map[101][101];	 // 맵
int Visit[101][101]; // 방문 표시
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int Min = 10001;

void DFS(int x, int y, int depth)
{

	if (x < 0 || y < 0 || x >= N || y >= M)
		return;					  // 맵의 범위를 벗어 날때
	if (x == N - 1 && y == M - 1) // 도착할때
	{
		if (depth < Min)
			Min = depth;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int Next_x = x + dx[i];
		int Next_y = y + dy[i];
		if (Visit[Next_x][Next_y] == 0 && Map[Next_x][Next_y] == '1')
		{
			Visit[Next_x][Next_y] = 1;
			DFS(Next_x, Next_y, depth + 1);
			Visit[Next_x][Next_y] = 0;
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M); // N세로 M가로

	for (int i = 0; i < N; i++)
	{
		scanf("%s", Map[i]);
	}

	DFS(0, 0, 1);
	printf("%d\n", Min);
}