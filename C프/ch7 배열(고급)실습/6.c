#include <stdio.h>

int main()
{
	char c[3];
	char input;
	int a[3] = {0};

	for (int i = 0; i < 3; i++)
		scanf("%c", c + i);
	getchar();

	for (int i = 0; i < 5; i++)
	{
		scanf("%c", &input);
		getchar();
		for (int i = 0; i < 3; i++)
		{
			if (c[i] == input)
				a[i] = 1;
		}
		for (int i = 0; i < 3; i++)
		{
			if (a[i])
				printf("%c", c[i]);
			else
				printf("_");
		}
		if(a[0]&&a[1]&&a[2])
		return 0;
	}
	return 0;
}