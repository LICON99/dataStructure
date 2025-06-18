#include <stdio.h>

int main()
{
	int a[10];
	int cnt[10] = {0};
	for (int i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 10; i++)

	{
		cnt[a[i]]++;
	}
	for (int i = 0; i < 10; i++)
	{
		if (cnt[i] > 0)
		{
			printf("%d:", i);
			for (int j = 0; j < cnt[i]; j++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}