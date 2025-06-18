#include <stdio.h>

int main()
{
	int n[5];
	int idx[5];
	int rank[5];

	for (int i = 0; i < 5; i++)
	{
		idx[i] = i;
	}
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", n + i);
		rank[i] = n[i];
	}

	int imp;
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
		{
			if (rank[i] > rank[j])
			{
				imp = rank[i];
				rank[i] = rank[j];
				rank[j] = imp;

				imp = idx[i];
				idx[i] = idx[j];
				idx[j] = imp;
			}
		}

	for (int i = 4; i >= 1; i--)
	{
		if (rank[i] == rank[i - 1])
			idx[i] = idx[i - 1];
	}
	for (int i = 0; i < 5; i++)
	{
		printf("rank[%d]:%d\n", i, rank[i]);
	}
	for (int i = 0; i < 5; i++)

		printf("idx[%d]:%d\n", i, idx[i]);

	for (int i = 0; i < 5; i++)
	{
		printf("%d=r%d\n", n[i], 5 - idx[i]);
	}
	return 0;
}