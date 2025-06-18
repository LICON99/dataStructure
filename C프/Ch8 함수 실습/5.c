#include <stdio.h>

void print_triangle(int x)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}
}

int main()
{
	int n;

	while (1)
	{
		scanf("%d", &n);
		if (n <= 0)
			return 0;
		print_triangle(n);
	}
	return 0;
}