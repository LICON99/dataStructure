#include <stdio.h>

int main()
{
	int n;
	int sum = 1;
	int diver = 0;
	int imp;
	scanf("%d", &n);
	imp = n;
	while (imp != 0)
	{
		sum *= imp % 10;
		imp /= 10;
	}
	int mov = 1;
	int imp2 = sum;
	for (int i = sum; i != 0; i /= 10)
		mov *= 10;
	mov /= 10;
	while (imp2 != 0)
	{
		diver += mov * (imp2 % 10);
		imp2 /= 10;
		mov /= 10;
	}
	printf("%d %d\n", sum, diver);
}