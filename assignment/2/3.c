#include <stdio.h>

int main()
{
	char ch;
	int i;

	scanf(" %c %d", &ch, &i); // 앞에 공백: 개행 문자 무시

	if (ch >= 'a' && ch <= 'z')
	{
		// 소문자: 'a' 기준으로 회전 (총 26글자)
		printf("%c", 'a' + (ch - 'a' + i) % 26);
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		// 대문자: 'A' 기준으로 회전 (총 26글자)
		printf("%c", 'A' + (ch - 'A' + i) % 26);
	}
	else
	{
		// 알파벳이 아닌 문자: 그대로 출력
		printf("%c", ch);
	}

	return 0;
}