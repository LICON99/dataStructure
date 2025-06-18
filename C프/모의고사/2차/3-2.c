#include <stdio.h>

int main()
{
	int n;
	int maxrow = 0;
	int maxnum = -1;
	int cnt = 0;
	int isNothing = 1;
	int num;
	int latestNum;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (num == 1 || num > 100)
		{
			if (cnt > maxrow)
			{
				maxrow = cnt;
				maxnum = latestNum;
			}
			cnt = 0;
			continue;
		}
		int flag = 0;
		for (int j = 2; j <= num; j++)
		{
			if (num % j == 0)
			{
				flag++;
			}
		}
		if (flag == 1)
		{
			// printf("%d ", num);
			cnt++;
			isNothing = 0;
			latestNum = num;
		}
		else
		{
			if (cnt > maxrow)
			{
				maxrow = cnt;
				maxnum = latestNum;
			}
			cnt = 0;
		}
	}
	if (cnt > maxrow)
	{
		maxrow = cnt;
		maxnum = latestNum;
		cnt = 0;
	}
	if (isNothing)
		printf("0");
	else
	{
		printf("%d\n%d\n", maxrow, maxnum);
	}
	return 0;
}