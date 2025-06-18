int main(void)
{
	char ch, x[100];
	int i = 0, N, flag, cnt = 0;

	scanf("%c", &ch);
	while (ch != '*')
	{
		if (ch >= 'A' && ch <= 'Z')
		{
			x[i] = ch - 'A' + 'a';
			i++;
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			x[i] = ch - 'a' + 'A';
			i++;
		}
		scanf("%c", &ch);
	}
	N = i;

	for (i = 0; i < N; i++)
	{
		printf("%c", x[i]);
	}
	printf("\n");

	for (i = 0; i < N - 2; i++)
	{
		flag = 0;
		if (x[i] >= 'A' && x[i] <= 'Z' && x[i] != 'A' && x[i] != 'E' && x[i] != 'I' && x[i] != 'O' && x[i] != 'U')
		{
			flag++;
		}
		if (x[i + 1] >= 'a' && x[i + 1] <= 'z' && (x[i + 1] == 'a' || x[i + 1] == 'e' || x[i + 1] == 'i' || x[i + 1] == 'o' || x[i + 1] == 'u'))
		{
			flag++;
		}
		if (x[i + 2] >= 'a' && x[i + 2] <= 'z' && x[i + 2] != 'a' && x[i + 2] != 'e' && x[i + 2] != 'i' && x[i + 2] != 'o' && x[i + 2] != 'u')
		{
			flag++;
		}
		if (flag == 3)
		{
			cnt++;
		}
	}

	printf("%d\n", cnt);
	return 0;
}