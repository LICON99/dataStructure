#include <stdio.h>

int main()
{
	int n;
	int cnt = 1;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf(" ");
		for (int j = 0; j < n; j++)
			printf("%d ", (cnt++) % 10);

		printf("\n");
	}
}