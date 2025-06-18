int main()
{
	int n, m, i, j, count = 0, num;
	int flag = 0;
	int max = 0, maxprime = -1;
	int maxv, minv;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (i == 0)
		{
			maxv = minv = num;
		}
		if (maxv < num)
			maxv = num;
		if (minv > num)
			minv = num;
		if (num >= 100)
		{
			count = 0;
			continue;
		}
		for (j = 2; j < num; j++)
			if (num % j == 0)
				break;
		if (num == j)
		{
			count++;

			if (max < count)
			{
				max = count;
				maxprime = num;
			}
		}
		else
			count = 0;
	}
	if (max == 0)
		printf("0");
	else
	{
		printf("%d\n", max);
		printf("%d\n", maxprime);
		printf("%d %d\n", maxv, minv);
	}
}