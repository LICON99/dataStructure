#include <stdio.h>

int main()
{
	int n;
	int maxrow = 0;
	int maxnum = -1;
	int cnt = 0;
	int isNothing = 1;
	int num;
	int max = -2147483648, min = 2147483647;
	// printf("max : %d, min : %d\n", max, min);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (num > max)
			max = num;
		if (num < min)
			min = num;
		if (num == 1 || num >= 100)
		{
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
			if (maxrow < cnt)
			{
				maxrow = cnt;
				maxnum = num;
			}
		}
		else
			cnt = 0;
	}
	if (isNothing)
		printf("0");
	else
	{
		printf("%d\n%d\n", maxrow, maxnum);
		printf("%d %d\n", max, min);
	}
	return 0;
}