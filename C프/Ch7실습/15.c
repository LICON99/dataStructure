#include <stdio.h>

int main()
{
	char x[10];

	for (int i = 0; i < 10; i++)
	{
		scanf("%c", x + i);
	}
	for (int i = 0; i < 10; i++)
	{
		int flag = 0;
		for (int j = 0; j < 10; j++)
		{
			if (x[j] == x[i])
				flag++;
		}
		if (flag == 1)
			printf("%c ", x[i]);
	}
	return 0;
}