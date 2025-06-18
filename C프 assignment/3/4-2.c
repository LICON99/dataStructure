#include <stdio.h>

int main()
{
	int t, n;
	int cnt = 0;	 // t와 같은 숫자의 개수
	int smaller = 0; // t보다 작은 숫자의 개수
	int bigger = 0;	 // t보다 큰 숫자의 개수

	scanf("%d", &t); // 기준이 되는 숫자 t 입력

	do
	{
		scanf("%d", &n); // 분석할 숫자 n 입력
		if (n == 0)
			break; // 입력이 0이면 반복 종료

		int impn = n; // 원본 n을 유지하면서 자리수 분석용 변수 생성
		while (impn != 0)
		{
			if (impn % 10 == t)
				cnt++; // t와 같은 숫자 발견 시 카운트 증가
			if (impn % 10 > t)
				bigger++; // t보다 큰 숫자 발견 시 증가
			if (impn % 10 < t)
				smaller++; // t보다 작은 숫자 발견 시 증가
			impn /= 10;	   // 다음 자리수로 이동
		}
	} while (n != 0); // 0이 입력될 때까지 반복

	printf("%d %d %d", cnt, smaller, bigger); // 결과 출력: 같은 수, 작은 수, 큰 수
	return 0;
}