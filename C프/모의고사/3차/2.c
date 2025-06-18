#include <stdio.h>
// 6 55 ~ 7 16
int main()
{
	int n;
	int m[200];
	int cnt = 0;
	int maxCnt = 0;
	int idx1;
	int mIdx1, mIdx2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m[i]);
		if (i == 0)
		{
			idx1 = i;
			mIdx1 = i;
			cnt++;
			continue;
		}
		if (m[i - 1] * m[i] < 0)
		{
			cnt++;
			if (i == n - 1)
			{
				if (maxCnt <= cnt)
				{
					maxCnt = cnt;
					mIdx1 = idx1;
					mIdx2 = i;
				}
			}
		}
		else
		{
			if (maxCnt <= cnt)
			{
				maxCnt = cnt;
				mIdx1 = idx1;
				mIdx2 = i - 1;
			}
			idx1 = i;
			cnt = 1;
		}
	}
	if (maxCnt == 1)
	{
		printf("%d\n", m[n - 1]);
		return 0;
	}
	printf("%d\n", maxCnt);
	for (int i = mIdx1; i <= mIdx2; i++)
	{
		printf("%d ", m[i]);
	}
	return 0;
}
