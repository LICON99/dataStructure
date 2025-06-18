#include <stdio.h>

int main()
{
	int n;
	int sum = 0;
	scanf("%d", &n);

	for (int i = 1;; i++)
	{
		sum += i;
		if (sum == (n + 1) * n / 2)
			break;
	}
	printf("%d", sum);
}