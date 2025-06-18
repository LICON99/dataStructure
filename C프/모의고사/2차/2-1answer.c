int main()
{
	int N, M, num, i, j;
	int cnt = 0, flag;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);

		flag = 0;
		for (j = 2; j < num; j++)
		{
			if (num % j == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0 && num > 1)
		{
			printf("%d ", num);
			cnt++;
			if (cnt % 3 == 0)
				printf("*\n");
		}
	}
	if (cnt % 3 != 0)
		printf("*\n");

	return 0;
}