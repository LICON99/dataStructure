#include <stdio.h>

int func1(int x)
{
	return x * x * 2 - 5 * x + 1;
}
int main()
{
	int x;

	scanf("%d",&x);

	printf("%d",func1(x));
	return 0;
}