#include <stdio.h>

int main()
{
	char a[10];

	for (int i = 0; i < 7; i++)
		scanf("%c", a + i);
	int cnt = 0;
	int ret = 0;
	for (int i = 0; i < 7; i++)
	{
		if (cnt == 0 && a[i] == 'c')
			cnt++;

		else if (cnt == 1 && a[i] == 'a')
			cnt++;

		else if (cnt == 2 && a[i] == 't')
		{
			cnt = 0;
			ret++;
		}
		else
			cnt = 0;
	}
	printf("%d", ret);
	return 0;
}