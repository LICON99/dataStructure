#include <stdio.h>

int main()
{
	int cnt = 0;	 // 현재 연속된 같은 부호의 수 카운트
	int n;			 // 입력 받을 정수
	int flag = 1;	 // 이전 수의 부호를 저장하는 플래그 (1: 양수, 0: 음수)
	int maxCnt = -1; // 최대 연속 카운트 저장

	do
	{
		scanf("%d", &n); // 사용자로부터 수 입력 받기

		if (n == 0)
			break; // 입력이 0이면 종료

		if (n > 0)
		{
			if (n > 0 && flag) // 이전 값도 양수였으면
				cnt++;		   // 카운트 증가
			else
				cnt = 1; // 새롭게 시작하는 경우
			flag = 1;	 // 현재 값이 양수임을 표시
		}
		if (n < 0)
		{
			if (n < 0 && !flag) // 이전 값도 음수였으면
				cnt++;			// 카운트 증가
			else
				cnt = 1; // 새롭게 시작
			flag = 0;	 // 현재 값이 음수임을 표시
		}
		if (maxCnt < cnt) // 최대 카운트 갱신
			maxCnt = cnt;
	} while (n != 0); // 0이 입력될 때까지 반복

	printf("%d\n", maxCnt); // 최대 연속 카운트 출력
	return 0;
}