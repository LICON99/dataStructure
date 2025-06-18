#include <stdio.h>

int main()
{
	int n;

	do
	{
		scanf("%d", &n); // 사용자로부터 n 입력 받기
		if (n == -1 || n <= 0 || n % 3 == 0)
			break; // -1이거나 0 이하 또는 3의 배수면 종료

		for (int i = 0; i < n; i++) // n줄 출력 반복
		{
			for (int j = 0; j < n - i - 1; j++) // 왼쪽 공백 출력
				printf(" ");
			for (int j = 0; j < 2 * i + 1; j++) // 가운데 X와 O 출력
			{
				if (j == 0 || j == 2 * i || i == n - 1)
					printf("X"); // 줄의 양끝 또는 마지막 줄이면 X 출력
				else
					printf("O"); // 나머지는 O 출력
			}
			printf("\n"); // 줄바꿈
		}
	} while (!(n == -1 || n <= 0 || n % 3 == 0)); // 조건을 만족하지 않으면 계속 반복

	return 0; 
}