int reverse_num(int);
int is_palindromic(int);
int del_digit(int, int);

int main()
{
	int N, T;

	scanf("%d %d", &N, &T);
	printf("%d %d %d %d\n", N, reverse_num(N), is_palindromic(N), del_digit(N, T));

	return 0;
}

int reverse_num(int n)
{
	int rnum = 0;

	while (n != 0)
	{
		rnum *= 10;
		rnum += n % 10;
		n /= 10;
	}

	return rnum;
}

int is_palindromic(int n)
{
	return (n == reverse_num(n));
}

int del_digit(int n, int t)
{
	int flag = 0, cnt = 0, deln = n;
	int xn[10];
	int i, t2 = t;

	flag = is_palindromic(n);

	while (n != 0)
	{
		xn[cnt++] = n % 10;
		n /= 10;
	}

	if (flag == 0)
	{
		for (i = t; i < cnt; i++)
			xn[i - 1] = xn[i];
		cnt--;
	}
	else
	{
		t2 = cnt + 1 - t;

		for (i = t2; i < cnt; i++)
			xn[i - 1] = xn[i];
		cnt--;
		for (i = t; i < cnt; i++)
			xn[i - 1] = xn[i];
		cnt--;
	}

	deln = 0;

	for (i = cnt - 1; i >= 0; i--)
	{
		deln *= 10;
		deln += xn[i];
	}

	return deln;
}