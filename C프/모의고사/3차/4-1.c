#include <stdio.h>

int main()
{
	int n;
	int input[20];
	int rank[20] = {0};
	int rankIdx = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &input[i]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (input[i] < input[j])
				rank[i]++;
		}
	}
	// printf("\ncheck : %d\n", (int)(n * 0.7));
	for (int i = 0; i < n; i++)
	{
		if (rank[i] + 1 <= ((double)n * 0.3))
			printf("%d %d %c\n", input[i], rank[i] + 1, 'A');
		else if (rank[i] + 1 <= ((double)n * 0.7))
			printf("%d %d %c\n", input[i], rank[i] + 1, 'B');
		else
			printf("%d %d %c\n", input[i], rank[i] + 1, 'F');
	}
	return 0;
}