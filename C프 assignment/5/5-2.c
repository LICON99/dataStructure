#include <stdio.h>
int add_digits(int N);

int main()
{
	int N;

	scanf("%d", &N);
	while (N / 10 > 0)
	{
		N = add_digits(N);
	}
	printf("%d", N);
	return 0;
}

int add_digits(int N)
{
	int sum = 0;

	while (N > 0)
	{
		sum += N % 10;
		N /= 10;
	}

	return sum;
}