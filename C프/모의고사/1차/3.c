#include <stdio.h>

int main()
{
	char ch;
	char first, second;

	scanf("%c", &first);
	// printf("first=%c\n", first);
	scanf("%c", &second);
	// printf("second=%c\n", second);
	ch = first;
	if (first > second)
	{
		ch = first;
		first = second;
		second = ch;
	}
	// printf("first : %c, second : %c\n", first, second);
	while (ch >= 'a' && ch <= 'z')
	{
		scanf("%c", &ch);
		if (ch >= 'a' && ch <= 'z')
		{
			if (first > ch)
			{
				second = first;
				first = ch;
			}
			if (ch > first && ch < second)
			{
				second = ch;
			}
		}
		// printf("first : %c, second : %c\n", first, second);
	}
	printf("%c%c", first, second);
	return 0;
}