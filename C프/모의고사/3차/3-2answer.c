#include <stdio.h>

int main()
{
	int n, m, a[100];
	int i, j;
	int cnt = 0, sum = 0, rem = 0;
	double avg = 0;
	int max_a[100], min_a[100];
	int max = 0, min = 100;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < n; i += m)
	{
		if (i + m - 1 < n)
		{
			sum = 0, max = 0, min = 100;
			for (j = 0; j < m; j++)
				sum += a[i + j];
			avg = (double)sum / m;
			for (j = 0; j < m; j++)
			{
				if (a[i + j] >= avg)
					printf(" %d", a[i + j]);
				if (a[i + j] > max)
					max = a[i + j];
				if (a[i + j] < min)
					min = a[i + j];
			}
			max_a[cnt] = max;
			min_a[cnt] = min;
			cnt++;
		}
		else
		{
			sum = 0, max = 0, min = 100;
			rem = n - i;
			for (j = 0; j < rem; j++)
				sum += a[i + j];
			avg = (double)sum / rem;
			for (j = 0; j < rem; j++)
			{
				if (a[i + j] >= avg)
					printf(" %d", a[i + j]);
				if (a[i + j] > max)
					max = a[i + j];
				if (a[i + j] < min)
					min = a[i + j];
			}
			max_a[cnt] = max;
			min_a[cnt] = min;
			cnt++;
		}
	}
	printf("\n");
	for (i = 0; i < cnt; i++)
	{
		printf(" %d", max_a[i]);
	}
	printf("\n");
	for (i = 0; i < cnt; i++)
	{
		printf(" %d", min_a[i]);
	}
}
