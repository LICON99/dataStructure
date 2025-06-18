// 2 29
#include <stdio.h>

int main()
{
	char c;
	char input[1000];
	int idx = 0;

	while (1)
	{
		scanf("%c", &c);
		if (c == '*')
			break;
		if (!(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'))
			continue;
		input[idx++] = c;
	}
	for (int i = 0; i < idx; i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z')
			input[i] -= ('a' - 'A');
		else if (input[i] >= 'A' && input[i] <= 'Z')
			input[i] += ('a' - 'A');
	} // 변환 완료

	int cnt = 1;
	int words = 0;

	for (int i = 0; i < idx; i++)
	{
		// printf("cnt : %d\n", cnt);
		if (cnt == 1 && !(input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') && input[i] >= 'A' && input[i] <= 'Z')
			cnt++;
		else if (cnt == 2 && (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u'))
			cnt++;
		else if (cnt == 3 && !(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') && input[i] >= 'a' && input[i] <= 'z')
		{
			words++;
			cnt = 1;
		}
		else
			cnt = 1;
		// printf("check\n");
	}

	for (int i = 0; i < idx; i++)
		printf("%c", input[i]);
	printf("\n");
	printf("%d\n", words);
	return 0;
}