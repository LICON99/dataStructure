
int main()
{
	char ch1, ch2, t1, t2, t3, m1 = 'a' - 1, m2 = 'a' - 1, m3 = 'a' - 1;
	int i, j, k, flag = 0;

	scanf("%c%c-%c%c%c", &ch1, &ch2, &t1, &t2, &t3);

	for (i = ch1; i <= ch2; i++)
	{
		for (j = ch1; j <= ch2; j++)
		{
			for (k = ch1; k <= ch2; k++)
			{
				if ((j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u') &&
					(i <= j && j <= k || k <= j && j <= i) && (i != j || j != i || i != k))
				{
					printf("%c%c%c\n", i, j, k);
					flag = 1;
					if ((m1 < i || m1 == i && m2 < j || m1 == i && m2 == j && m3 < k) && (i < t1 || i == t1 && j < t2 || i == t1 && j == t2 && k < t3))
					{
						m1 = i;
						m2 = j;
						m3 = k;
					}
				}
			}
		}
	}

	if (flag == 0)
		printf("none\n");

	if (m1 == 'a' - 1 || m2 == 'a' - 1 || m3 == 'a' - 1)
		printf("none\n");
	else
		printf("%c%c%c\n", m1, m2, m3);

	return 0;
}
