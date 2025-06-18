#include <stdio.h>

int reverse_num(int N);
int is_equal(int N, int M);
int del_digit(int N, int T);
int is_palindromic(int N);
int main()
{
	int n, t, m;
	int delnum;
	int x[100];

	scanf("%d %d", &n, &t);

	m = reverse_num(n);
	printf("%d %d %d %d", n, m, is_palindromic(n), del_digit(n, t));
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
int del_digit(int N, int T)
{
	int ret = 0;
	int size = 1;
	int imp = N;
	int x[100];
	int idx = 0;

	while (imp > 0)
	{
		imp /= 10;
		size *= 10;
	}
	size /= 10;
	while (size > 0)
	{
		x[idx++] = N / size % 10;
		size /= 10;
	}

	if (is_palindromic(N))
	{
		// printf("here\n");
		for (int i = 0; i < idx; i++)
		{
			if (i == idx - T || i == T - 1)
			{
				// printf("hi\n");
				continue;
			}
			ret = ret * 10 + x[i];
		}
	}
	else
	{
		for (int i = 0; i < idx; i++)
		{
			if (i == idx - T)
				continue;
			ret = ret * 10 + x[i];
		}
	}
	return ret;
}

int is_palindromic(int N)
{
	if (N == reverse_num(N))
		return 1;
	else
		return 0;
}