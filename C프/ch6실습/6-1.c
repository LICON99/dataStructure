#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf(" ");
		for (int j = 0; j < n; j++)
		{
			if (j == i || j == n - i - 1)
				printf("X ");
			else
				printf("O ");
		}
		printf("\n");
	}
}