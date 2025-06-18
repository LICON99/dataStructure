#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int m;
		int a, b, c;

		scanf("%d", &m);
		if (m < 10000 || m > 99999 || (m % 10 != 0 || m / 10 % 10 != 0))
		{
			printf("none\n");
			continue;
		} // 예외처리
		a = m / 10000;
		b = m / 1000 % 10;
		c = m / 100 % 10;
		if (a == b && b == c || (a != b && a != c && b != c))
		{
			printf("none\n");
			continue;
		} // 예외처리
		if (c == 0 || c == 1 || c == 2)
			printf("CE\n");
		else if (c == 3 || c == 4)
			printf("SW\n");
		else if (c == 5)
			printf("DS\n");
		else
			printf("none\n");
	}
	return 0;
}