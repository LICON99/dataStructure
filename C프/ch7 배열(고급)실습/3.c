#include <stdio.h>

int main()
{
	int a[5];
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}

	int first = a[0], second = a[1];

	if (second > first)
	{
		int temp = first;
		first = second;
		second = temp;
	}

	for (int i = 2; i < 5; i++)
	{
		if (a[i] > first)
		{
			second = first;
			first = a[i];
		}
		else if (a[i] > second)
		{
			second = a[i];
		}
	}

	printf("%d\n%d", first, second);
	return 0;
}