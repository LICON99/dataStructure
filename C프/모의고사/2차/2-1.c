#include <stdio.h>

int main()
{
	int n;
	int cnt = 0;
	scanf("%d", &n);
	int isPre = 0;
	for (int i = 0; i < n; i++)
	{
		int m;
		int flag = 0;
		scanf("%d", &m);
		for (int j = 2; j <= m; j++)
		{
			if (m % j == 0)
				flag++;
		}
		if (flag == 1)
		{
			printf("%d ", m);
			cnt++;
			if (cnt % 3 == 0)
				printf("*\n");
		}
	}
	if (cnt % 3 != 0)
		printf("*");

	return 0;
}