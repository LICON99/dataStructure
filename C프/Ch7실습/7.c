#include <stdio.h>

int main()
{
	int x[10];
	int idx = 0;
	int n;
	int cnt;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &n);

		cnt = 0;
		for (int j = 0; j < idx; j++)
		{
			if (x[j] == n)
			{
				cnt++;
			}
		}
		if (cnt == 0)
			x[idx++] = n;
	}
	for (int i = 0; i < idx; i++)
		printf("%d ", x[i]);
	return 0;
}