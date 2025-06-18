#include <stdio.h>

int main()
{
	int a[10000], b[10000];
	int aIdx = 0, bIdx = 0;
	int n = 1;
	int isIn;
	while (n >= 0)
	{
		scanf("%d", &n);
		if (n < 0)
			break;
		isIn = 0;
		for (int i = 0; i < aIdx; i++)
		{
			if (a[i] == n)
			{
				// printf("check\n");
				isIn = 1;
				break;
			}
		}
		if (!isIn)
			a[aIdx++] = n;
	}
	n = 1;
	while (n >= 0)
	{
		scanf("%d", &n);
		if (n < 0)
			break;
		isIn = 0;
		for (int i = 0; i < bIdx; i++)
		{
			if (b[i] == n)
			{
				isIn = 1;
				break;
			}
		}
		if (!isIn)
			a[aIdx++] = n;
	}

	int ret[10000];
	int retIdx = 0;
	for (int i = 0; i < aIdx; i++)
	{
		n = a[i];
		isIn = 0;
		for (int j = 0; j < retIdx; j++)
		{
			if (ret[j] == n)
			{
				isIn = 1;
				break;
			}
		}
		if (!isIn)
			ret[retIdx++] = n;
	}
	for (int i = 0; i < bIdx; i++)
	{
		n = b[i];
		isIn = 0;
		for (int j = 0; j < retIdx; j++)
		{
			if (ret[j] == n)
			{
				isIn = 1;
				break;
			}
		}
		if (!isIn)
			ret[retIdx++] = n;
	}

	int imp;
	for (int i = 0; i < retIdx - 1; i++)
	{
		for (int j = 0; j < retIdx - 1 - i; j++)
		{
			if (ret[j] > ret[j + 1])
			{
				imp = ret[j];
				ret[j] = ret[j + 1];
				ret[j + 1] = imp;
			}
		}
	}
	for (int i = 0; i < retIdx; i++)
	{
		printf("%d ", ret[i]);
	}
	return 0;
}