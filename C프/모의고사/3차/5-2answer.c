#include <stdio.h>
int main()
{

	int i, j, k, N1, N2, M, flag, check1, check2, max, max_ind, start;
	char ch, X[100], Y[100], cnt[100];

	scanf("%c", &ch);
	i = 0;
	while (ch != '!')
	{
		X[i] = ch;
		i++;
		scanf("%c", &ch);
	}

	scanf("%d", &M);

	N1 = i;
	k = 0;
	for (i = 0; i < N1; i++)
	{
		flag = 0;
		for (j = 0; j < i; j++)
		{
			if (X[i] == X[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			Y[k] = X[i];
			k++;
		}
	}

	N2 = k;

	for (i = 0; i < N2; i++)
	{
		printf("%c", Y[i]);
	}
	printf("\n");

	for (i = 0; i < N2; i++)
	{

		if (Y[i] >= 'a' && Y[i] <= 'z')
		{
			Y[i] = (Y[i] - 'a' + M) % 26 + 'A';
		}
		else if (Y[i] >= 'A' && Y[i] <= 'Z')
		{
			Y[i] = (Y[i] - 'A' + M) % 26 + 'a';
		}
	}

	for (i = 0; i < N2; i++)
	{
		printf("%c", Y[i]);
	}
	printf("\n");

	cnt[0] = 1;
	flag = 0;
	for (i = 1; i < N2; i++)
	{
		check1 = Y[i - 1] >= 'a' && Y[i - 1] <= 'z' ? -1 : 1;
		check2 = Y[i] >= 'A' && Y[i] <= 'Z' ? 1 : -1;
		if (check1 * check2 < 0)
		{
			cnt[i] = cnt[i - 1] + 1;
			flag = 1;
		}
		else
			cnt[i] = 1;
	}

	if (flag == 0)
	{
		printf("none\n");
		return 0;
	}
	max = cnt[0];
	max_ind = 0;
	for (i = 1; i < N2; i++)
	{
		if (max < cnt[i])
		{
			max = cnt[i];
			max_ind = i;
		}
	}

	if (max == 1)
	{
		printf("none\n");
		return 0;
	}
	for (int i = max_ind - cnt[max_ind] + 1; i <= max_ind; i++)
	{
		printf("%c", Y[i]);
	}
	printf("\n");
	return 0;
}
