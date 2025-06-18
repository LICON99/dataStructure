#include <stdio.h>

int main()
{
	int x[10];
	int max;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", x + i);
	}
	max = x[0];
	for (int i = 0; i < 10; i++)
	{
		if (max < x[i])
			max = x[i];
	}
	printf("%d", max);
	return 0;
}