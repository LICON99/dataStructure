#include <stdio.h>

int main()
{
	char c[5];

	for (int i = 0; i < 5; i++)
	{
		scanf("%c", &c[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 5 - i; j < 10 - i; j++)
		{
			printf("%c", c[j % 5]);
		}
		printf("\n");
	}
	return 0;
}