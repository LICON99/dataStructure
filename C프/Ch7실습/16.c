#include <stdio.h>

int main()
{
	int n;
	char x[10];

	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%c", x + i);
	}
	for (int i = 0; i < n; i++)
	{
		int m;
		scanf("%d", &m);
		printf("x[%d%%%d]=x[%d]=%c\n", m, n, m % n, x[m % n]);
	}
	return 0;
}