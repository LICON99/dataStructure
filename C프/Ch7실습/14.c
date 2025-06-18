#include <stdio.h>

int main()
{
	int x[10], y[10];

	for (int i = 0; i < 10; i++)
	{
		scanf("%c", x + i);
	}
	getchar();
	for (int i = 0; i < 10; i++)
	{
		scanf("%c", y + i);
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%c ", x[i]);
		printf("%c ", y[i]);
	}
	return 0;
}