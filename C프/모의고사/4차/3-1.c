#include <stdio.h>

int main()
{
	int n;
	int x[100];
	int idx = 0;

	while (1)
	{
		scanf("%d", &n);
		if (n <= 0)
			break;
		int isOdd = 1;
		int isPrime = 1;
		int imp = n;
		while (imp > 0)
		{
			if (imp % 10 % 2 == 0)
			{
				isOdd = 0;
				break;
			}
			imp /= 10;
		}
		imp = n;

		for (int i = 2; i < imp; i++)
		{
			if (imp % i == 0)
			{
				isPrime = 0;
				break;
			}
		}
		if (isOdd || isPrime)
			x[idx++] = n;
	}

	if (idx == 0)
	{
		printf("0\n");
		return 0;
	}
	for (int i = idx - 1; i >= 0; i--)
		printf("%d ", x[i]);
	return 0;
}