#include <stdio.h>


int main()
{
	int x, a, b, c;

	scanf("%d", &x);
	getchar();
	scanf("%d %d %d", &a, &b, &c);

	printf("%d", func2(x, a, b, c));
	return 0;
}