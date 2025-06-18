#include <stdio.h>

int reverse_num(int);
int del_dupnum(int n);

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", del_dupnum(n));
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

int del_dupnum(int n)
{
	int arr[100];
	int ret[100];
	int retIdx = 0;
	int idx = 0;
	int imp = n;
	int size = 1;

	while (imp > 0)
	{
		imp /= 10;
		size *= 10;
	}
	size /= 10;
	while (size > 0)
	{
		arr[idx++] = n / size % 10;
		size /= 10;
	}
	// for (int i = 0; i < idx; i++)
	// 	printf("%d", arr[i]);
	for (int i = 0; i < idx; i++)
	{
		int flag = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			ret[retIdx++] = arr[i];
		}
	}
	int sum = 0;
	for (int i = 0; i < retIdx; i++)
	{
		sum = sum * 10 + ret[i];
	}
	return sum;
}