#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);
	for (int i = 1; i < 7; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			for (int x = 1; x < 7; x++)
			{
				if (i + j + x == n)
					printf("%d %d %d\n", i, j, x);
			}
		}
	}
	return 0;
}