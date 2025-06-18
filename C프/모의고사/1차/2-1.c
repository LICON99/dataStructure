#include <stdio.h>

int main()
{
	char ch;
	int upper = 0;
	int down = 0;
	int n = 0;
	int etc = 0;

	scanf("%c", &ch);
	if (ch >= 'A' && ch <= 'Z')
		upper++;
	else if (ch >= 'a' && ch <= 'z')
		down++;
	else if (ch >= '0' && ch <= '9')
		n += ch - '0';
	else if (ch != '*')
		etc++;
	while (ch != '*')
	{
		scanf("%c", &ch);
		if (ch >= 'A' && ch <= 'Z')
			upper++;
		else if (ch >= 'a' && ch <= 'z')
			down++;
		else if (ch >= '0' && ch <= '9')
			n += ch - '0';
		else if (ch != '*')
			etc++;
	}
	printf("%d %d %d %d\n", upper, down, n, etc);

	return 0;
}