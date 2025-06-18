#include <stdio.h>
// 6 33
int main()
{
	char x[200], y[200];
	int ix = 0, iy = 0;
	char c;
	char save = 'x';
	while (1)
	{
		scanf("%c", &c);
		if (c == '*' && save == 'y')
			break;
		else if (c == '*')
		{
			save = 'y';
			continue;
		}

		if (save == 'x')
		{
			x[ix++] = c;
		}
		if (save == 'y')
		{
			y[iy++] = c;
		}
	}
	int flag = -1;
	if (iy >= ix)
	{
		for (int i = 0; i < iy; i++)
		{
			if (x[i] < y[i])
			{
				flag = 0;
				break;
			}
			else if (x[i] > y[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag == -1)
			flag = 0;
	}

	if (iy <= ix)
	{
		for (int i = 0; i < iy; i++)
		{
			if (x[i] < y[i])
			{
				flag = 0;
				break;
			}
			else if (x[i] > y[i])
			{
				flag = 1;
				break;
			}
		}
		// 같은경우
		if (flag == -1)
			flag = 1;
	}
	if (flag == 0)
	{
		for (int i = 0; i < ix; i++)
			printf("%c", x[i]);
	}
	if (flag == 1)
	{
		for (int i = 0; i < iy; i++)
			printf("%c", y[i]);
	}
	return 0;
	// y출력하는 경우
}

// int main(void)
// {
// 	char x[100], y[100], ch;
// 	int i, M = 0, N = 0, L;
// 	while (1)
// 	{
// 		scanf("%c", &ch);
// 		if (ch == '*')
// 			break;
// 		x[M] = ch;
// 		M++;
// 	}
// 	while (1)
// 	{
// 		scanf("%c", &ch);
// 		if (ch == '*')
// 			break;
// 		y[N] = ch;
// 		N++;
// 	}
// 	if (M < N)
// 		L = M;
// 	else
// 		L = N;

// 	for (i = 0; i < L; i++)
// 	{
// 		if (x[i] < y[i])
// 		{
// 			for (i = 0; i < M; i++)
// 				printf("%c", x[i]);
// 			printf("\n");
// 			return 0;
// 		}
// 		else if (y[i] < x[i])
// 		{
// 			for (i = 0; i < N; i++)
// 				printf("%c", y[i]);
// 			printf("\n");
// 			return 0;
// 		}
// 	}
// 	if (M <= N)
// 		for (i = 0; i < M; i++)
// 			printf("%c", x[i]); // 같은 경우 길이 비교
// 	else
// 		for (i = 0; i < N; i++)
// 			printf("%c", y[i]);
// 	printf("\n");
// 	return 0;
// }