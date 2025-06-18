#include <stdio.h> 

int main()
{
	int n, m;
	scanf("%d %d", &n, &m); // 입력: 범위의 시작 n과 끝 m

	int maxDivisorCount = -1;	  // 현재까지의 최대 약수 개수
	int maxPrimeExponentSum = -1; // 최대 약수 개수일 때의 소인수 지수 총합
	int numberWithMaxDivisors;	  // 약수 개수가 최대인 수

	for (int i = n; i <= m; i++) // n부터 m까지 반복
	{
		if (i == 1)
			continue; // 1은 약수가 1개라서 제외

		int divisorCount = 1;	  // 약수 개수는 곱셈으로 계산하므로 1로 시작
		int primeExponentSum = 0; // 소인수의 지수 합 초기화
		int temp = i;			  // 나눗셈을 위한 임시 변수

		for (int factor = 2; factor <= temp; factor++) // 2부터 i까지 나눠봄
		{
			int exponent = 0;
			while (temp % factor == 0) // factor로 나누어질 때마다
			{
				exponent++;		// 지수 증가
				temp /= factor; // 나눠진 몫으로 갱신
			}
			if (exponent > 0)
			{
				divisorCount *= (exponent + 1); // 약수 개수 공식 반영
				primeExponentSum += exponent;	// 지수 합 누적
			}
		}

		if (divisorCount > maxDivisorCount) // 최대 약수 개수 갱신 조건
		{
			maxDivisorCount = divisorCount;			// 최대 약수 개수 갱신
			maxPrimeExponentSum = primeExponentSum; // 해당 시 지수 합도 갱신
			numberWithMaxDivisors = i;				// 해당 수 저장
		}
	}

	printf("%d %d %d\n", numberWithMaxDivisors, maxDivisorCount, maxPrimeExponentSum);
	// 최종 결과 출력: 약수 많은 수, 그 약수 개수, 소인수 지수 합
	return 0; 
}