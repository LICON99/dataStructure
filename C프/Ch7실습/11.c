#include <stdio.h>

int main()
{
	double x[10];
	double min;
	for (int i = 0; i < 10; i++)
	{
		scanf("%lf", x + i);
	}
	min = x[0];
	for (int i = 0; i < 10; i++)
	{
		if (x[i] < min)
			min = x[i];
	}
	printf("%.1lf", min);
	return 0;
}