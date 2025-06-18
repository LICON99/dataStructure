#include <stdio.h>

char x[200], y[200];
int idx = 0, idy = 0;
char c;

int main()
{
	while (1)
	{
		scanf("%c", &c);
		if (c == '!')
			break;
		x[idx++] = c;
	}
	for (int i = 0; i < idx; i++)
	{
		int isIn = 0;
		for (int j = 0; j < i; j++)
		{
			if (x[i] == x[j])
			{
				isIn = 1;
				break;
			}
		}
		if (isIn == 0)
		{
			y[idy++] = x[i];
		}
	}
	// printf("idy : %d\n", idy);

	for (int i = idy - 1; i >= 0; i--)
	{
		printf("%c", y[i]);
	}
	return 0;
}