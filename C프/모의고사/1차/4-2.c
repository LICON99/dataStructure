#include <stdio.h>

int main()
{
	char ch;
	char lower, upper;
	scanf("%c", &ch);
	int lflag = 0;
	int uflag = 0;
	if (ch >= 'a' && ch <= 'z')
	{
		lower = ch;
		lflag = 1;
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		upper = ch;
		uflag = 1;
	}
	if (ch >= 'a' && ch <= 'z')
	{
		while (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		{
			scanf("%c", &ch);
			if ((ch >= 'a' && ch <= 'z') && lower < ch)
				lower = ch;
			if (ch >= 'A' && ch <= 'Z' && lflag == 1)
			{
				upper = ch;
				lflag = 0;
			}
			if (ch >= 'A' && ch <= 'Z' && upper > ch)
				upper = ch;
		}
		printf("%c", lower);
		if (upper >= 'A' && upper <= 'Z')
			printf("%c", upper);
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		while (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		{
			scanf("%c", &ch);
			if (ch >= 'A' && ch <= 'Z' && upper > ch)
				upper = ch;
			if (ch >= 'a' && ch <= 'z' && uflag == 1)
			{
				lower = ch;
				uflag = 0;
			}
			if (ch >= 'a' && ch <= 'z' && lower < ch)
				lower = ch;
		}
		printf("%c", upper);
		if (lower >= 'a' && lower <= 'z')
			printf("%c", lower);
	}
	return 0;
}