#include <stdio.h>
char decrypt(char ch, int M);
char encrypt(char ch, int M);

int main()
{
	char str[100];
	int M1, M2;
	char c;
	int i = 0;
	while (1)
	{
		scanf("%c", &c);
		if (c == '*')
			break;
		str[i++] = c;
	}
	scanf("%d %d", &M1, &M2);
	for (int j = 0; j < i; j++)
		printf("%c", decrypt(str[j], M1));
	printf("\n");
	for (int j = 0; j < i; j++)
		printf("%c", encrypt(decrypt(str[j], M1), M2));
	return 0;
}

char decrypt(char ch, int M)
{
	int len = ('z' - 'a' + 1);

	if (!(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z'))
		return ch;
	if (ch >= 'a' && ch <= 'z')
	{
		if ((ch - 'a' - M % len) < 0)
			return (ch - 'a' - M % len) + 'z' + 1;
		return (ch - 'a' - M % len) + 'a';
	}
	if ((ch - 'A' - M % len) < 0)
		return (ch - 'A' - M % len) + 'Z' + 1;
	return (ch - 'A' - M % len) + 'A';
}

char encrypt(char ch, int M)
{
	int len = ('z' - 'a' + 1);

	if (!(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z'))
		return ch;
	if (ch >= 'a' && ch <= 'z')
		return (ch - 'a' + M) % len + 'a';
	return (ch - 'A' + M) % len + 'A';
}