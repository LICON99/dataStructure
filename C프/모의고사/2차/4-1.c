#include <stdio.h>

int main()
{
	char c1, c2;
	int flag = 1;
	scanf("%c%c", &c1, &c2);

	// printf("c1: %c, c2: %c", c1, c2);
	for (int i = c1; i <= c2; i++)
	{
		for (int j = c1; j <= c2; j++)
		{
			for (int k = c1; k <= c2; k++)
			{
				if ((i == j && j == k) || (j != 'a' && j != 'e' && j != 'i' && j != 'o' && j != 'u') || !(j >= i && j <= k || j >= k && j <= i))
					continue;
				printf("%c%c%c\n", i, j, k);
				flag = 0;
			}
		}
		}
	if (flag)
		printf("none\n");
	return 0;
}