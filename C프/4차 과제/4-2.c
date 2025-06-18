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

	int maxArr[1000] = {0}, minArr[1000] = {0};
	int retIdx = 0;
	int max, min;
	for (int i = 0; i < n; i++)
	{
		if (i % 3 == 0)
		{

			max = arr[i];
			min = arr[i];
		}
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
		if (i % 3 == 2 || i == n - 1)
		{
			maxArr[retIdx] = max;
			minArr[retIdx] = min;
			retIdx++;
		}
	}
	for (int i = 0; i < retIdx; i++)
	{
		printf("%d ", maxArr[i]);
	}
	printf("\n");
	for (int i = 0; i < retIdx; i++)
	{
		printf("%d ", minArr[i]);
	}
	return 0;
}