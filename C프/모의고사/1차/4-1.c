#include <stdio.h>

int main()
{
	char ch;
	char min, max;
	scanf("%c", &ch);
	min = ch;
	max = ch;
	if (ch >= 'a' && ch <= 'z')
	{
		while (ch >= 'a' && ch <= 'z')
		{
			scanf("%c", &ch);
			if ((ch >= 'a' && ch <= 'z') && min < ch)
				min = ch;
		}
		printf("%c", min);
	}
	if (ch >= 'A' && ch <= 'Z')
	{
		while (ch >= 'A' && ch <= 'Z')
		{
			scanf("%c", &ch);
			if (ch >= 'A' && ch <= 'Z' && max > ch)
				max = ch;
		}
		printf("%c", max);
	}
	return 0;
}