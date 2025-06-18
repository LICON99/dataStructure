#include <stdio.h>

int main()
{
	int arr[10000];
	int n;
	int idx = 0;
	int isIn;
	while (n >= 0)
	{
		scanf("%d", &n);
		if (n < 0)
			break;
		isIn = 0;
		for (int i = 0; i < idx; i++)
		{
			if (arr[i] == n)
			{
				// printf("check\n");
				isIn = 1;
				break;
			}
		}
		if (isIn == 1)
		{
			printf("0");
		}
		else
		{
			printf("1");
			arr[idx++] = n;
		}
	}
	return 0;
}