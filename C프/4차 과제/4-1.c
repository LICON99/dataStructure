#include <stdio.h>

int main()
{
	int n;
	int arr[10000];
	int idx = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[idx++]);
	}
	idx--;
	while (idx >= 0)
	{
		printf("%d ", arr[idx--]);
	}
	printf("\n");
	idx++;
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
		if (i % 3 == 2)
		{
			printf("\n");
		}
	}
	return 0;
}