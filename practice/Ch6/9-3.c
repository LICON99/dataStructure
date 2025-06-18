#include <stdio.h>

int main()
{
	int n;
	int arr[50];
	int *pa = arr;
	int cnt = 0;

	scanf("%d", &n);
	for (int *i = pa; i < pa + n; i++)
	{
		scanf("%d", i);
		if (*i == 0)
			break;
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}