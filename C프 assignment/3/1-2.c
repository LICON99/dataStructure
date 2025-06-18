#include <stdio.h>

int main()
{
	int n, m;
	int maxCntM;
	int maxCnt = -1;
	// n: 테스트 케이스 수, m: 현재 수, maxCntM: 약수 개수가 가장 많은 수 저장, maxCnt: 해당 개수

	scanf("%d", &n);
	for (int i = 0, cnt; i < n; i++)
	{
		cnt = 0;
		scanf("%d", &m);
		printf("%d: ", m);
		// m 입력받고 출력에 숫자 표시, cnt는 약수 개수 세기용

		for (int j = 1; j <= m; j++)
		{
			if (m % j == 0)
			{
				printf("%d ", j);
				cnt++;
			}
			// 약수이면 출력하고 카운트 증가
		}
		if (maxCnt < cnt)
		{
			maxCntM = m;
			maxCnt = cnt;
		}
		// 현재 약수 개수가 최대라면 값 갱신

		printf("%d\n", cnt);
		// 약수 개수 출력 및 줄바꿈
	}
	printf("%d\n", maxCntM);
	// 약수 개수가 가장 많았던 수 출력

	return 0;
}