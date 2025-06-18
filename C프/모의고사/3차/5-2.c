#include <stdio.h>

char x[200], y[200];
int idx = 0, idy = 0;
char c;

int main()
{
	while (1)
	{
		scanf("%c", &c);
		if (c == '!')
			break;
		x[idx++] = c;
	}
	for (int i = 0; i < idx; i++)
	{
		int isIn = 0;
		for (int j = 0; j < i; j++)
		{
			if (x[i] == x[j])
			{
				isIn = 1;
				break;
			}
		}
		if (isIn == 0)
		{
			y[idy++] = x[i];
		}
	}
	// printf("idy : %d\n", idy);

	for (int i = 0; i < idy; i++)
	{
		printf("%c", y[i]);
	}
	printf("\n");
	int m;
	scanf("%d", &m);
	for (int i = 0; i < idy; i++)
	{
		if (y[i] >= 'a' && y[i] <= 'z')
		{
			y[i] -= ('a' - 'A');
			y[i] = (y[i] - 'A' + m) % ('z' - 'a' + 1) + 'A';
		}
		else if (y[i] >= 'A' && y[i] <= 'Z')
		{
			y[i] += ('a' - 'A');
			y[i] = (y[i] - 'a' + m) % ('z' - 'a' + 1) + 'a';
		}
	}
	for (int i = 0; i < idy; i++)
	{
		printf("%c", y[i]);
	}
	printf("\n");

	int cnt = 0;
	int maxCnt = 0;
	int idx1, idx2;
	int maxIdx1, maxIdx2;

	for (int i = 0; i < idy; i++)
	{
		if (i == 0)
		{
			idx1 = i;
			cnt++;
			continue;
		}
		if (y[i - 1] >= 'a' && y[i - 1] <= 'z' && y[i] >= 'A' && y[i] <= 'Z' || (y[i - 1] >= 'A' && y[i - 1] <= 'Z' && y[i] >= 'a' && y[i] <= 'z'))
		{
			cnt++;
			if (i == idy - 1 && maxCnt < cnt)
			{
				maxCnt = cnt;
				maxIdx1 = idx1;
				maxIdx2 = i;
			}
		}
		else
		{
			if (maxCnt < cnt)
			{
				maxCnt = cnt;
				maxIdx1 = idx1;
				maxIdx2 = i - 1;
			}
			idx1 = i;
			cnt = 1;
		}
	}
	if (maxCnt == 1)
	{
		printf("none\n");
		return 0;
	}
	for (int i = maxIdx1; i <= maxIdx2; i++)
	{
		printf("%c", y[i]);
	}
	return 0;
}
