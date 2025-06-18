#include <stdio.h>

int main()
{
	int m, n;
	int cnt = 1;
	scanf("%d %d", &m, &n);

	for (int i = m; i <= n; i++)
	{
		cnt = 1;
		printf("%d!=", i);
		for (int j = 1; j <= i; j++)
		{
			printf("%d", j);
			if (j != i)
				printf("*");
			cnt = cnt * j;
		}
		printf("=%d\n", cnt);
	}
	return 0;
}