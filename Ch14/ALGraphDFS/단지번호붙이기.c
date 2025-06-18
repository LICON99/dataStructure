/*단지번호붙이기 성공

시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	128 MB	218570	100006	63469	43.613%
문제
<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.



입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.*/
#include <stdio.h>
#include <string.h>
int n;
char arr[25][25];
int group[1000] = {0};
int check[25][25] = {0};
int id = 0;
int dx[5] = {-1, 0, 1, 0};
int dy[5] = {0, -1, 0, 1};
char tmp;
void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		// for (int j = 0; j < n; j++)
		// {
		scanf("%s", arr[i]);
		// check[i][j] = 1;
		// }
		// scanf("%c", &tmp);
		getchar();
	}
}
void dfs(int x, int y, int id)
{
	group[id]++;
	arr[x][y] = '0';
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] == '1')
			dfs(nx, ny, id);
	}
	return;
}
#include <stdlib.h>
int cmp(const void *first, const void *second)
{
	if (*(int *)first > *(int *)second)
		return 1;
	else if (*(int *)first < *(int *)second)
		return -1;
}
int main(void)
{
	init();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == '1')
			{
				dfs(i, j, id++);
			}
		}
	qsort(group, id, sizeof(int), cmp);
	printf("%d\n", id);

	for (int k = 0; k < id; k++)
		printf("%d\n", group[k]);
	return 0;
}