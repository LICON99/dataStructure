#include <iostream>	   // 표준 입출력
#include <queue>	   // 큐 라이브러리 (사용하지 않음)
#include <vector>	   // 벡터 라이브러리 (사용하지 않음)
#include <math.h>	   // 수학 라이브러리 (사용하지 않음)
#define INF 2147483647 // 무한대 값으로 사용 (int 범위의 최대값)
using namespace std;

int n;				   // 도시의 수
int tmp = INF;		   // 현재 최소 비용을 저장할 변수 (초기에는 매우 큰 값으로 설정)
int w[11][11] = {0};   // 도시 간 비용 행렬 (최대 10x10)
int visited[11] = {0}; // 방문 여부를 표시하는 배열

// 입력을 받는 함수
void init()
{
	cin >> n; // 도시 수 입력

	// 비용 행렬 입력 (1-based 인덱스 사용)
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> w[i][j];

	// (주석 처리된 디버깅용 출력 부분)
	// 행렬을 출력해보고 싶을 때 사용할 수 있음
}

// DFS로 모든 가능한 경로를 탐색하며 최소 비용을 구하는 함수
// visited: 방문한 도시 체크 배열
// len: 현재까지 방문한 도시 수
// u: 현재 위치한 도시
// sum: 현재까지의 누적 비용
void dfs(int visited[], int len, int u, int sum)
{
	// 누적 비용이 현재 최소 비용(tmp)보다 크면 더 탐색할 필요 없음
	if (tmp <= sum)
		return;

	// 모든 도시를 방문했고, 시작 도시로 돌아온 경우
	if (len == n && u == w[0][0]) // w[0][0]에는 시작 도시 번호가 저장되어 있음
	{
		tmp = sum; // 최소 비용 갱신
		return;
	}

	// 다음 도시를 선택
	for (int i = 1; i <= n; i++)
	{
		// i번 도시가 현재 도시 u에서 갈 수 있고, 아직 방문하지 않은 도시라면
		if (w[u][i] != 0 && !visited[i])
		{
			visited[i] = 1;							 // i번 도시 방문 처리
			dfs(visited, len + 1, i, sum + w[u][i]); // 다음 도시로 이동하며 DFS
			visited[i] = 0;							 // 백트래킹 (다른 경로 탐색을 위해 방문 해제)
		}
	}
	return;
}

int main()
{
	int ret = INF; // 최종 결과값(최소 비용) 저장용 변수

	init(); // 입력 초기화

	// 각 도시를 출발지로 설정하여 DFS 수행
	for (int i = 1; i <= n; i++)
	{
		w[0][0] = i;		   // 시작 도시를 w[0][0]에 임시로 저장
		dfs(visited, 0, i, 0); // DFS 탐색 시작
		if (ret > tmp)		   // 현재까지의 최소 비용 갱신
			ret = tmp;
	}

	printf("%d\n", ret); // 최소 비용 출력
	return 0;
}