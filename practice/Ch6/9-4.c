#include <stdio.h>

int main()
{
	int x[3]; // 배열 선언
	int *p;	  // 포인터 선언
	int temp;

	// 입력 받기 (포인터를 이용한 반복)
	for (p = x; p < x + 3; p++)
	{
		scanf("%d", p);
	}

	// 정렬 (포인터만 사용)
	for (p = x; p < x + 2; p++) // 2번만 반복 (3개 정렬이므로)
	{
		int *q;
		for (q = x; q < x + 2; q++)
		{
			if (*q > *(q + 1))
			{
				temp = *q;
				*q = *(q + 1);
				*(q + 1) = temp;
			}
		}
	}

	// 중앙값 출력
	printf("%d\n", *(x + 1)); // 중간 값 출력 (정렬 후 x[1])

	return 0;
}