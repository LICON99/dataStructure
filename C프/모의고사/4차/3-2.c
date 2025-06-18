#include <stdio.h>

int odd_number(int num);
int prime_number(int num);
int count_number(int cnt, int num);

int main()
{
	int n;
	int x[100];
	int idx = 0;
	int start = 0;
	int mstart, mend;
	int cnt = 0;
	int maxCnt = 0;

	while (1)
	{
		scanf("%d", &n);
		if (n <= 0)
			break;
		if (odd_number(n) || prime_number(n))
			x[idx++] = n;
	}
	
	for (int i = 0; i < idx; i++)
	{
		cnt = count_number(cnt, x[i]);

		if (cnt == 1)
			start = i;

		if (maxCnt < cnt)
		{
			maxCnt = cnt;
			mstart = start;
			mend = i;
		}
	}
	// printf("maxcnt : %d\n", maxCnt);
	if (maxCnt == 0)
	{
		printf("0\n");
		return 0;
	}
	for (int i = mstart; i <= mend; i++)
		printf("%d ", x[i]);
	return 0;
}
int prime_number(int num)
{
	int isPrime = 1;

	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			isPrime = 0;
			break;
		}
	}
	return isPrime;
}

int odd_number(int num)
{
	int isOdd = 1;
	while (num > 0)
	{
		if (num % 10 % 2 == 0)
		{
			isOdd = 0;
			break;
		}
		num /= 10;
	}
	return isOdd;
}

int count_number(int cnt, int num)
{
	if (odd_number(num) && prime_number(num))
	{
		return cnt + 1;
	}
	else
		return 0;
}