int main()
{
	int n, a[100];
	int i, j;
	int cnt = 0;
	double avg = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < n; i += 3)
	{
		if (i + 2 < n)
		{
			avg = (double)(a[i] + a[i + 1] + a[i + 2]) / 3;
			for (j = 0; j < 3; j++)
			{
				if (a[i + j] >= avg)
					printf(" %d", a[i + j]);
			}
		}
		else if (i + 2 == n)
		{
			avg = (double)(a[i] + a[i + 1]) / 2;
			for (j = 0; j < 2; j++)
			{
				if (a[i + j] >= avg)
					printf(" %d", a[i + j]);
			}
		}
		else if (i + 1 == n)
		{
			avg = a[i];
			if (a[i] >= avg)
				printf(" %d", a[i]);
		}
	}
}