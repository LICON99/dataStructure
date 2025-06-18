#include <stdio.h>

int reverse_num(int N);
int is_equal(int N, int M);

int main()
{
	int n, m;
	int x[100];

	scanf("%d", &n);

	m = reverse_num(n);
	printf("%d %d %d\n", n, m, is_equal(n, m));
	return 0;
}

int reverse_num(int N)
{
	int ret = 0;
	while (N > 0)
	{
		ret = ret * 10 + N % 10;
		N /= 10;
	}
	return ret;
}
int is_equal(int N, int M)
{
	if (N == M)
		return 1;
	else
		return 0;
}