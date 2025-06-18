#include <stdio.h>

int main()
{
	int n;
	int first[20], second[20];
	double mean[20];
	int rank[20] = {0};
	int rankIdx = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &first[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &second[i]);

	for (int i = 0; i < n; i++)
		mean[i] = (double)first[i] * 0.4 + (double)second[i] * 0.6;

	int imp1, imp2;
	double dimp;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (mean[j] < mean[j + 1])
			{
				imp1 = first[j];
				imp2 = second[j];
				dimp = mean[j];
				first[j] = first[j + 1];
				second[j] = second[j + 1];
				mean[j] = mean[j + 1];
				mean[j + 1] = dimp;
				first[j + 1] = imp1;
				second[j + 1] = imp2;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mean[i] < mean[j])
				rank[i]++;
		}
	}
	// printf("\ncheck : %d\n", (int)(n * 0.7));
	for (int i = 0; i < n; i++)
	{
		if (rank[i] + 1 <= (n * 0.3))
			printf("%d %d %.1lf %d %c\n", first[i], second[i], mean[i], rank[i] + 1, 'A');
		else if (rank[i] + 1 <= (n * 0.7) || second[i] >= 60)
			printf("%d %d %.1lf %d %c\n", first[i], second[i], mean[i], rank[i] + 1, 'B');
		else
			printf("%d %d %.1lf %d %c\n", first[i], second[i], mean[i], rank[i] + 1, 'F');
	}
	return 0;
}