#include <stdio.h>
int is_prime_number(int num);
int count_prime_number(int cnt, int num);

int main()
{
	int n;
	int cnt = 0;
	int maxCnt, last;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		cnt = count_prime_number(cnt, num);
		if (maxCnt < cnt)
		{
			maxCnt = cnt;
			last = num;
		}
	}
	printf("%d", maxCnt);
	if (maxCnt > 0)
		printf("\n%d", last);
	return 0;
}
int is_prime_number(int num)
{
	if (num < 2)
		return 0;
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return 0;
	}
	return 1;
}

int count_prime_number(int cnt, int num)
{
	if (is_prime_number(num) && num < 100)
		return cnt + 1;
	return 0;
}
