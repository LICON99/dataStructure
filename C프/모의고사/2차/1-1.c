#include <stdio.h>
#pragma warning(disable : 4996)
int main()
{
	int n;
	int ivt = 0;

	scanf("%d", &n);

	int mod = 1;
	for (int i = n; i != 0; i /= 10)
	{
		mod *= 10;
	}
	mod /= 10;
	while (n != 0)
	{
		ivt += mod * (n % 10);
		n /= 10;
		mod /= 10;
	}
	int m2 = 0, m3 = 0;

	for (int i = 1; i <= ivt; i++)
	{
		if (i % 2 == 0)
			m2++;
		if (i % 3 == 0)
			m3++;
	}
	printf("%d\n%d %d\n", ivt, m2, m3);
	return 0;
}