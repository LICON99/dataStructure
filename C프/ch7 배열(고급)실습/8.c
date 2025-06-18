#include <stdio.h>

int main()
{
	int n[5];

	for (int i = 0; i < 5; i++)
		scanf("%d", n + i);
	int imp;
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
		{
			if (n[i] > n[j])
			{
				imp = n[i];
				n[i] = n[j];
				n[j] = imp;
			}
		}
	for (int i = 0; i < 5; i++)
		printf("%d\n", n[i]);
	return 0;
}