#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int cnt = m;

	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		if (num == 1)
			continue;
		int flag = 0;
		for (int j = 2; j <= num; j++)
		{
			if (num % j == 0)
			{
				flag++;
			}
		}
		if (flag == 1 && cnt > 0)
		{
			printf("%d ", num);
			cnt--;
		}
	}
	if (cnt == m)
		printf("0\n");
	return 0;
}