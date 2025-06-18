#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 2 * n - 1; i >= 1; i -= 2)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}