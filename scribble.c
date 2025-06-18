#include <stdio.h>

int main()
{
	int num;
	int *p, ar[5];
	ar[0] = 1;
	ar[1] = 2;
	int *q = &ar;
	printf("%lu %lu\n", *ar, *q);
	return 0;
}