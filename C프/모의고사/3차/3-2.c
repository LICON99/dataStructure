#include <stdio.h>

int main()
{
	int n, m;
	int input[100];
	int min[100], max[100];
	int mi, mx;
	int minIdx = 0, maxIdx = 0;
	double sum = 0;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", input + i);
	}
	for (int i = 0; i < n; i++)
	{
		sum += input[i];
		if (i != 0 && (i + 1) % m == 0)
		{
			// printf("check\n");
			mi = input[i - m + 1];
			mx = input[i - m + 1];
			// printf("input : %d\n", input[i]);

			for (int j = i - m + 1; j <= i; j++)
			{
				if (mi > input[j])
					mi = input[j];
				if (mx < input[j])
					mx = input[j];
				if ((double)input[j] >= (sum) / m)
					printf("%d ", input[j]);
			}
			min[minIdx++] = mi;
			max[maxIdx++] = mx;
			sum = 0;
			// printf("\n");
		}
		else if (i == n - 1)
		{
			mi = input[n - n % m];
			mx = input[n - n % m];
			for (int j = n - n % m; j <= n - 1; j++)
			{
				if (mi > input[j])
					mi = input[j];
				if (mx < input[j])
					mx = input[j];
				if ((double)input[j] >= (sum) / (n % m))
					printf("%d ", input[j]);
			}
			min[minIdx++] = mi;
			max[maxIdx++] = mx;
			break;
		}
	}
	printf("\n");
	for (int i = 0; i < maxIdx; i++)
		printf("%d ", max[i]);
	printf("\n");
	for (int i = 0; i < minIdx; i++)
		printf("%d ", min[i]);
	return 0;
}
// #include <stdio.h>
// int main()
// {
// 	int n, m, a[100];
// 	int i, j;
// 	int cnt = 0, sum = 0, rem = 0;
// 	double avg = 0;
// 	int max_a[100], min_a[100];
// 	int max = 0, min = 100;

// 	scanf("%d %d", &n, &m);
// 	for (i = 0; i < n; i++)
// 		scanf("%d", &a[i]);

// 	for (i = 0; i < n; i += m)
// 	{
// 		if (i + m - 1 < n)
// 		{
// 			sum = 0, max = 0, min = 100;
// 			for (j = 0; j < m; j++)
// 				sum += a[i + j];
// 			avg = (double)sum / m;
// 			for (j = 0; j < m; j++)
// 			{
// 				if (a[i + j] >= avg)
// 					printf(" %d", a[i + j]);
// 				if (a[i + j] > max)
// 					max = a[i + j];
// 				if (a[i + j] < min)
// 					min = a[i + j];
// 			}
// 			max_a[cnt] = max;
// 			min_a[cnt] = min;
// 			cnt++;
// 		}
// 		else
// 		{
// 			sum = 0, max = 0, min = 100;
// 			rem = n - i;
// 			for (j = 0; j < rem; j++)
// 				sum += a[i + j];
// 			avg = (double)sum / rem;
// 			for (j = 0; j < rem; j++)
// 			{
// 				if (a[i + j] >= avg)
// 					printf(" %d", a[i + j]);
// 				if (a[i + j] > max)
// 					max = a[i + j];
// 				if (a[i + j] < min)
// 					min = a[i + j];
// 			}
// 			max_a[cnt] = max;
// 			min_a[cnt] = min;
// 			cnt++;
// 		}
// 	}
// 	printf("\n");
// 	for (i = 0; i < cnt; i++)
// 	{
// 		printf(" %d", max_a[i]);
// 	}
// 	printf("\n");
// 	for (i = 0; i < cnt; i++)
// 	{
// 		printf(" %d", min_a[i]);
// 	}
// }