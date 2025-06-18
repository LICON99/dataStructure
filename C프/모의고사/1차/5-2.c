#include <stdio.h>

int main()
{
	int n;
	int sum = 1;
	int diver = 0;
	int imp;
	scanf("%d", &n);
	imp = n;
	int mov = 1;
	for (int i = n; i != 0; i /= 10)
		mov *= 10;
	mov /= 10;
	while (imp != 0)
	{
		diver += mov * (imp % 10);
		imp /= 10;
		mov /= 10;
	}
	int cnt2 = 0;
	int cnt3 = 0;
	int j = 1;
	for (int i = 1; i <= diver; i++)
	{
		if (i % 2 == 0)
			cnt2++;
		if (i % 3 == 0)
			cnt3++;
	}
	printf("%d\n", diver);
	printf("%d %d\n", cnt2, cnt3);
	return 0;
}