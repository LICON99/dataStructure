#include <stdio.h>

int main()
{
	int a, b, c;
	int flag = 0; // a,b에 대한 사칙연산으로 c가 나오는지 체크하는 플래그 : flag==0이면 불가능, flag!=0이면 가능

	scanf("%d %d %d", &a, &b, &c); // 사용자로부터 세 정수 입력 (a, b, c)

	if (a + b == c) // a + b = c 인 경우
	{
		printf("+\n");
		flag++; // 일치하는 연산자가 있으면 flag 증가
	}
	if (a - b == c) // a - b = c 인 경우
	{
		printf("-\n");
		flag++;
	}
	if (a * b == c) // a * b = c 인 경우
	{
		printf("*\n");
		flag++;
	}
	if (a / b == c) // a / b = c 인 경우
	{
		printf("/\n");
		flag++;
	}
	if (flag == 0) // 어떤 사칙연산으로도 c가 도출되지 않는 경우
		printf("Incorrect\n");

	return 0; // 프로그램 정상 종료
}