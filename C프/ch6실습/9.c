#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);
	int cnt = 0;
	int mod = 1;

	for (int i = 1; i <= n; i++)
	{
		mod = 1;
		while (i / mod != 0)
		{
			if (i / mod % 10 == 3)
				cnt++;
			mod *= 10;
		}
	}
	printf("%d\n", cnt);
	return 0;
}