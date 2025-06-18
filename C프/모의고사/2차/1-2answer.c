
int main()
{

	int N, N_org, M = 0, cnt = 0;
	int min_value = -1, max_value = -1, temp;

	while (1)
	{

		scanf("%d", &N);
		if (N == 0)
			break;

		N_org = N;
		cnt = 0;
		M = 0;
		while (N)
		{
			M = M * 10 + N % 10;
			N /= 10;
			N_org *= 10;
		}
		temp = N_org + M;
		printf("%d ", temp);

		if (min_value == -1 || min_value > temp)
			min_value = temp;
		if (max_value == -1 || max_value < temp)
			max_value = temp;

		while (temp)
		{
			if (temp % 10 == 3)
				cnt++;
			temp /= 10;
		}
		printf("%d ", cnt);
	}

	printf("\n%d %d\n", min_value, max_value);

	return 0;
}