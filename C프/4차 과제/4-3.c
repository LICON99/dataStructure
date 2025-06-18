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
	int maxArr2[1000] = {0}, minArr2[1000] = {0};
	int retIdx = 0;
	int max, min;

	for (int i = 0; i < n; i++)
	{
		maxArr[i] = arr[i];
		minArr[i] = arr[i];
	}
	while (1)
	{
		for (int i = 0; i < n; i++)
		{
			if (i % 3 == 0)
			{

				max = maxArr[i];
				min = minArr[i];
			}
			if (maxArr[i] > max)
				max = maxArr[i];
			if (minArr[i] < min)
				min = minArr[i];
			if (i % 3 == 2 || i == n - 1)
			{
				maxArr2[retIdx] = max;
				minArr2[retIdx] = min;
				retIdx++;
			}
		}
		for (int i = 0; i < retIdx; i++)
		{
			printf("%d ", maxArr2[i]);
		}
		printf("\n");
		for (int i = 0; i < retIdx; i++)
		{
			printf("%d ", minArr2[i]);
		}
		printf("\n");
		if (retIdx == 1)
			break;
		// loop 재설정
		for (int i = 0; i < retIdx; i++)
		{
			maxArr[i] = maxArr2[i];
			minArr[i] = minArr2[i];
		}
		n = retIdx;
		retIdx = 0;
	}
	return 0;
}