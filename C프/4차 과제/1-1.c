#include <stdio.h>

int main()
{
	int m1, m2;
	int n;
	int x[1000] = {0};
	int xIdx = 0;

	while (1)
	{
		int y[1000000] = {0};

		scanf("%d", &n);
		if (n <= 0)
			break;

		int idx = 0;
		int impn = n;
		int cnt = 0;

		while (1)
		{

			y[idx++] = impn % 10;
			impn /= 10;
			if (impn == 0)
				break;
		}

		int flag = 1;

		for (int i = 0; i < idx / 2; i++)
		{
			if (y[i] != y[(idx - 1) - i])
				flag = 0;
		}

		if (flag) // valid할 경우 저장
			x[xIdx++] = n;
	}

	if (xIdx == 0)
	{
		printf("none\n");
		return 0;
	}

	for (int i = 0; i < xIdx - 1; i++)
	{
		for (int j = 0; j < xIdx - 1 - i; j++)
		{
			int imp;
			if (x[j] < x[j + 1])
			{
				imp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = imp;
			}
		}
	}

	for (int i = 0; i < xIdx; i++)
		printf("%d ", x[i]);
	return 0;
}