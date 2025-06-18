#include <stdio.h>

int reverse_num(int);
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", reverse_num(n));
	return 0;
}
int reverse_num(int n)
{
	int ret = 0;
	while (n > 0)
	{
		ret = ret * 10 + n % 10;
		n /= 10;
	}
	return ret;
}