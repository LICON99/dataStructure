#include <stdio.h>

int main()
{
	char ch[20];
	int i = 0;
	while (1)
	{
		char c;
		scanf("%c", &c);
		if (c == '#')
			break;
		*(ch + i++) = c;
	}
	i--;
	while (i >= 0)
	{
		printf("%c", *(ch + i--));
	}
	return 0;
}