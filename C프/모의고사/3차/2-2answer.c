#include <stdio.h>
int main()
{
	int n, i, max, max_idx;
	int a[50], cnt[50] = {0};

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	cnt[0] = 1;
	for (i = 1; i < n; i++)
	{
		if (a[i] * a[i - 1] < 0)
			cnt[i] = cnt[i - 1] + 1;
		else
			cnt[i] = 1;
	}

	max = cnt[0];
	max_idx = 0;

	for (i = 1; i < n; i++)
	{
		if (max <= cnt[i])
		{
			max = cnt[i];
			max_idx = i;
		}
	}

	printf("%d\n", max);
	for (i = max_idx - max + 1; i <= max_idx; i++)
		printf(" %d", a[i]);

	return 0;
}