int main()
{
	int N, i, M = 0, cnt1 = 0, cnt2 = 0;

	scanf("%d", &N);

	while (N)
	{
		M = M * 10 + N % 10;
		N /= 10;
	}
	for (i = 1; i <= M; i++)
	{
		if (i % 2 == 0)
			cnt1++;
		if (i % 3 == 0)
			cnt2++;
	}
	printf("%d\n", M);
	printf("%d %d\n", cnt1, cnt2);

	return 0;
}