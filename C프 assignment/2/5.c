#include <stdio.h>

int main()
{
	int n;		 // 5자리 양의 정수를 입력받아 저장할 변수
	int a, b, c; // a:제일 큰 두 자리 수, b: 백의 자리, c: 맨 앞 두 자리

	scanf("%d", &n);  // 사용자로부터 네 자리 숫자 입력받음
	a = n / 1000;	  // a: 제일 큰 두 자리 수 추출
	b = n / 100 % 10; // b: 백의 자리 추출
	c = n % 100;	  // c: 맨 앞 두 자리 수 추출

	// 조건: 제일 큰 두 자리(a)가 10이어야 하고, 마지막 두 자리(c)는 00이어야 함
	if (a != 10 || c != 0)
	{
		printf("none\n"); // 조건 만족 안 하면 "none" 출력 후 종료
		return 0;
	}

	// 지역 코드 판별 (백의 자리 b 값에 따라)
	if (b == 0 || b == 1 || b == 2)
		printf("Seoul\n"); // 0~2: 서울
	else if (b == 3 || b == 4)
		printf("Busan\n"); // 3~4: 부산
	else if (b == 5)
		printf("Gwangju\n"); // 5: 광주
	else
		printf("none\n"); // 그 외는 무효 처리
}