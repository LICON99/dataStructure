#include <stdio.h>

int main()
{
	int oddRes = 0;	 // 홀수 자리 숫자들을 저장할 변수 (역순 누적)
	int evenRes = 0; // 짝수 자리 숫자들을 저장할 변수 (역순 누적)
	int n;

	scanf("%d", &n); // 입력된 수 n을 받음

	while (n != 0)
	{
		if (n % 10 % 2 == 0) // 맨 끝자리 수가 짝수인지 확인
		{
			evenRes += n % 10; // 짝수이면 해당 숫자 더함
			evenRes *= 10;	   // 자릿수 올림 (다음 숫자 붙이기 위해)
		}
		if (n % 10 % 2 == 1) // 홀수인지 확인
		{
			oddRes += n % 10; // 홀수이면 해당 숫자 더함
			oddRes *= 10;	  // 자릿수 올림
		}
		n /= 10; // 맨 끝자리 제거 후 다음 자리로 이동
	}

	printf("%d %d", evenRes / 10, oddRes / 10); // 마지막 자릿수 보정 후 출력
	return 0;								
}