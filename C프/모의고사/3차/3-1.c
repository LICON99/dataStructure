#include <stdio.h>

int main()
{
	int n, m;
	int input[100];
	int min[100], max[100];
	int minIdx = 0, maxIdx = 0;
	int sum = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", input + i);
	}
	for (int i = 0; i < n; i++)
	{
		sum += input[i];
		if (i % 3 == 2)
		{
			for (int j = i - 2; j <= i; j++)
			{
				if ((double)input[j] >= ((double)sum) / 3)
					printf("%d ", input[j]);
			}
			sum = 0;
			// printf("\n");
		}
		else if (i == n - 1)
		{
			for (int j = n - n % 3; j <= i; j++)
			{
				if ((double)input[j] >= ((double)sum) / (n % 3))
					printf("%d ", input[j]);
			}
			sum = 0;
		}
	}
}