#include <stdio.h>

int main()
{
	int n;
	char c;
	int x[1000], y[1000], cnt[1000] = {0};
	int xIdx = 0, yIdx = 0;

	while (1)
	{
		scanf("%c", &c);
		if (c == '!')
			break;
		if (xIdx == 0)
			y[yIdx++] = c;
		int flag = 1;
		for (int i = 0; i < yIdx; i++)
		{
			if (c == y[i])
				flag = 0;
		}
		if (flag)
			y[yIdx++] = c;
		x[xIdx++] = c;
		cnt[c]++;
	}
	yIdx--;
	while (yIdx >= 0)
	{
		if (cnt[y[yIdx]] > 0)
		{
			printf("%c %d\n", y[yIdx], cnt[y[yIdx]]);
			cnt[y[yIdx]] = 0;
		}
		yIdx--;
	}
	return 0;
}