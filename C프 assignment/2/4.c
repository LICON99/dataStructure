#include <stdio.h>

int main()
{
	int n;
	int a, b; // a는 십의 자리, b는 일의 자리

	scanf("%d", &n); // 사용자로부터 두 자리 정수 입력 받음
	a = n / 10;		 // 십의 자리 분리
	b = n % 10;		 // 일의 자리 분리

	if (n >= 10 && n <= 19) // 10~19는 예외적인 영어 표현이 필요함
	{
		if (n == 10)
			printf("ten"); // 10
		if (n == 11)
			printf("eleven"); // 11
		if (n == 12)
			printf("twelve"); // 12
		if (n == 13)
			printf("thirteen"); // 13
		if (n == 15)
			printf("fifteen"); // 15
		if (n == 16)
			printf("sixteen"); // 16
		if (n == 17)
			printf("seventeen"); // 17
		if (n == 18)
			printf("eighteen"); // 18
		if (n == 19)
			printf("nineteen"); // 19
	}
	else if (n >= 20 && n <= 99) // 20~99는 십의 자리와 일의 자리로 나누어 처리 가능
	{
		switch (a) // 십의 자리에 따라 접두사 출력
		{
		case 2:
			printf("twenty"); // 20대
			break;
		case 3:
			printf("thirty"); // 30대
			break;
		case 4:
			printf("forty"); // 40대 (주의: fourty 아님)
			break;
		case 5:
			printf("fifty"); // 50대
			break;
		case 6:
			printf("sixty"); // 60대
			break;
		case 7:
			printf("seventy"); // 70대
			break;
		case 8:
			printf("eighty"); // 80대
			break;
		case 9:
			printf("ninety"); // 90대
			break;
		}
		if (b != 0) // 일의 자리가 0이 아니면 하이픈 붙이기
			printf("-");
		switch (b) // 일의 자리 처리
		{
		case 1:
			printf("one"); // 1
			break;
		case 2:
			printf("two"); // 2
			break;
		case 3:
			printf("three"); // 3
			break;
		case 4:
			printf("four"); // 4
			break;
		case 5:
			printf("five"); // 5
			break;
		case 6:
			printf("six"); // 6
			break;
		case 7:
			printf("seven"); // 7
			break;
		case 8:
			printf("eight"); // 8
			break;
		case 9:
			printf("nine"); // 9
			break;
		}
	}
	else
		printf("none"); // 10보다 작거나 99보다 큰 경우에는 출력 없음

	return 0; // 프로그램 종료
}