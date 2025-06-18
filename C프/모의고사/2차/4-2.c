#include <stdio.h>

int main()
{
	char c1, c2, f1, f2, f3;
	int flag = 1;
	scanf("%c%c-%c%c%c", &c1, &c2, &f1, &f2, &f3);
	char p1 = -1, p2 = -1, p3 = -1;
	// printf("!!!!%c%c%c\n", f1, f2, f3);
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

				if (i < f1 || (i == f1 && j < f2) || (i == f1 && j == f2 && k < f3))
				{
					p1 = i;
					p2 = j;
					p3 = k;
				}
			}
		}
	}
	if (flag)
		printf("none\n");
	if (p1 != -1 && p2 != -1 && p3 != -1)
		printf("%c%c%c\n", p1, p2, p3);
	else
		printf("none\n");
	return 0;
}