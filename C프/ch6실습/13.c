#include <stdio.h>

int main()
{
	int n;
	int sum = 0;
	double m;
	int cnt = 0;
	do
	{
		scanf("%d", &n);
		if (n > 0 && n <= 100)
		{
			sum += n;
			cnt++;
		}
	} while (n > 0);
	m = ((double)(sum)) / cnt;
	printf("%d %.2lf %d", sum, m, cnt);
	return 0;
}