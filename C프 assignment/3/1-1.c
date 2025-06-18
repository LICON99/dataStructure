#include <stdio.h>

int main()
{
	int n, m;
	// n: 테스트 케이스 수, m: 나눌 대상 숫자

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		printf("%d: ", m);
		// m 입력받고 출력에 숫자 표시

		for (int j = 1; j <= m; j++)
		{
			if (m % j == 0)
				printf("%d ", j);
			// m을 나눌 수 있는 약수 출력
		}

		printf("\n");
		// 각 숫자에 대한 결과 줄바꿈
	}

	return 0;
}