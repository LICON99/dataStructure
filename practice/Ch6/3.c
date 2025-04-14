#include <stdio.h>

int main()
{
	int n;
	int a;
	int cnt = 0;

	scanf("%d", &n);

	while (1)
	{
		cnt++;
		scanf("%d", &a);
		if (a > n)
			printf("%d>?\n", a);
		if (a < n)
			printf("%d<?\n", a);
		if (a == n)
		{
			printf("%d==?\n", a);
			break;
		}
	}
	printf("%d", cnt);
	return 0;
}