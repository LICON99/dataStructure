#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);
	int mod = 1;
	int sum = 0;
	while (n / mod > 0)
	{
		sum += n / mod % 10;
		mod *= 10;
	}
	printf("%d", sum);
	return 0;
}