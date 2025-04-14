#include <stdio.h>

int main()
{
	int n;
	int sum = 0;

	scanf("%d", &n);
	if (n != 0)
		sum += n;
	while (n != 0)
	{
		scanf("%d", &n);
		if (n != 0)
			sum += n;
	}
	printf("%d\n", sum);
	return 0;
}