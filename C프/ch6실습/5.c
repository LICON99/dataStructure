#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= 2 * n - 1; i += 2)
	{
		for (int x = ((2 * n - 1) - i)/2; x >= 0; x--)
			printf(" ");
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}