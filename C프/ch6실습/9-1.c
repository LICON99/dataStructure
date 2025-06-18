#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);
	int cnt = 0;
	int mod = 1;
	while (n / mod != 0)
	{
		if (n / mod % 10 == 3)
			cnt++;
		mod *= 10;
	}
	printf("%d\n", cnt);
	return 0;
}