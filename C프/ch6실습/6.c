#include <stdio.h>

int main()
{
	int n;
	int cnt = 1;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		printf(" ");
		for (int j = i; j < n + i; j++)
			printf("%d ", j% 10);

		printf("\n");
	}
}