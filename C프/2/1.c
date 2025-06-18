#include <stdio.h>

int main()
{
	int a, b, c;  // 세 수를 입력받아 저장할 변수
	double m;	  // 세 수의  평균을 저장할 변수
	int min, max; // 세 수 중에서 최대, 최소를 저장할 변수

	scanf("%d %d %d", &a, &b, &c); // 세 수를 입력받아 각각 a,b,c에 저장
	m = (double)(a + b + c) / 3;   // 평균 저장
	/* a, b, c 오름차순 case 6가지*/
	if (a <= b && b <= c) // case 1 : a<=b<=c : min = a, max = c
	{
		min = a;
		max = c;
	}
	if (a <= c && c <= b) // case 2 : a<=c<=b : min = a, max = b
	{
		min = a;
		max = b;
	}
	if (b <= a && a <= c) // case 3 : b<=a<=c : min = b, max = c
	{
		min = b;
		max = c;
	}
	if (b <= c && c <= a) // case 4 : b<=c<=a : min = b, max = a
	{
		min = b;
		max = a;
	}
	if (c <= a && a <= b) // case 5 : c<=a<=b : min = c, max = b
	{
		min = c;
		max = b;
	}
	if (c <= b && b <= a) // case 6 : c<=b<=a : min = c, max = a
	{
		min = c;
		max = a;
	}

	if (m >= 90) // A인 경우
		printf("A\n");
	else if (m >= 80) // B인 경우
		printf("B\n");
	else if (m >= 70) // C인 경우
		printf("C\n");
	else if (m >= 60) // D인 경우
		printf("D\n");
	else
		printf("F\n"); // F인 경우
	/*결과 출력*/
	printf("max: %d\nmin: %d\n", max, min);

	return 0;
}