#include <stdio.h>

int main()
{
	int n, m;
	int max = 0;

	scanf("%d %d", &n, &m);

	for (int i = 1; n / i != 0 && m / i != 0; i++)
	{
		if (n % i == 0 && m % i == 0)
			max = i;
	}
	printf("%d\n", max);
	return 0;
}