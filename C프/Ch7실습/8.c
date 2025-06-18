#include <stdio.h>

int main()
{
	int x[10];
	int n;
	int idx = 0;
	scanf("%d", &n);

	while (n != 0)
	{
		x[idx++] = n % 10;
		n /= 10;
	}
	for(int i=0;i<idx;i++)
	{
		printf("%d ",x[i]);
	}
	return 0;
}