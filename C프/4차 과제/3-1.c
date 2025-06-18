#include <stdio.h>

int main()
{
	int a[20];
	int imp;
	int m;

	for (int i = 0; i < 20; i++)
		a[i] = i + 1;

	scanf("%d", &m);
	for (int i = 19; i > 19 - m + 1; i--)
	{
		imp = a[i];
		a[i] = a[i - 1];
		a[i - 1] = imp;
	}
	for (int i = 0; i < 20; i++)
		printf("%d ", a[i]);

	return 0;
}