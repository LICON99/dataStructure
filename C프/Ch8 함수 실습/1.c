#include <stdio.h>

int add(int x, int y)
{
	return x + y;
}
int main()
{
	int n;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		sum = add(sum, i);
	printf("%d",sum);
	return 0;
}