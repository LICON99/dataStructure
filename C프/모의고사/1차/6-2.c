#include <stdio.h>

int main()
{
	int n;
	int ce = 0, sw = 0, ds = 0;
	int ce1 = 0, sw1 = 0, ds1 = 0;
	int err = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int m;
		int a, b, c;

		scanf("%d", &m);
		if (m < 10000 || m > 99999 || (m % 10 != 0 || m / 10 % 10 != 0))
		{
			printf("none\n");
			err++;
			continue;
		} // 예외처리
		a = m / 10000;
		b = m / 1000 % 10;
		c = m / 100 % 10;
		if (a == b && b == c || (a != b && a != c && b != c))
		{
			printf("none\n");
			err++;
			continue;
		} // 예외처리
		if (c == 0 || c == 1 || c == 2)
		{
			printf("CE\n");
			ce++;
			if (!err)
				ce1++;
			err = 0;
		}
		else if (c == 3 || c == 4)
		{
			printf("SW\n");
			sw++;
			if (!err)
				sw1++;
			err = 0;
		}
		else if (c == 5)
		{
			printf("DS\n");
			ds++;
			if (!err)
				ds1++;
			err = 0;
		}
		else
		{
			printf("none\n");
			err++;
		}
	}
	printf("%d %d %d\n", ce, sw, ds);
	printf("%d %d %d\n", ce1, sw1, ds1);
	return 0;
}