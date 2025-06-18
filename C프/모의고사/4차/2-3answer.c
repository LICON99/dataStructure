int reverse_num(int x);
int del_dupnum(int x);

int main()
{
	int i, n, cnt = 0;
	int dup[100], org[100], rev[100];
	int maxv, orgmaxv;
	int mem1, mem2;
	int diff;
	while (1)
	{
		scanf("%d", &n);
		if (n < 0)
			break;
		org[cnt] = n;
		rev[cnt] = reverse_num(n);
		dup[cnt] = del_dupnum(rev[cnt]);
		if (cnt == 0)
		{
			diff = org[cnt] - dup[cnt];
			if (diff < 0)
				diff = diff * -1;
			maxv = diff;
			mem1 = org[cnt];
		}
		diff = org[cnt] - dup[cnt];
		if (diff < 0)
			diff = diff * -1;
		if (maxv < diff)
		{
			maxv = diff;
			mem1 = org[cnt];
		}

		cnt++;
	}
	for (i = 0; i < cnt; i++)
		printf(" %d", dup[i]);
	printf("\n%d %d", mem1, maxv);
}

int del_dupnum(int n)
{
	int i, j, sum = 0, cnt = 0;
	int x[10], r[10], cnt1 = 0;
	while (n != 0)
	{
		x[cnt++] = n % 10;
		n /= 10;
	}

	for (i = cnt - 1; i >= 0; i--)
	{
		for (j = cnt - 1; j > i; j--)
			if (x[i] == x[j])
				break;
		if (i == j)
			r[cnt1++] = x[i];
	}

	for (i = 0; i < cnt1; i++)
	{
		sum = sum * 10 + r[i];
	}
	return sum;
}
int reverse_num(int x)
{
	int sum = 0;

	while (x != 0)
	{
		sum = sum * 10 + x % 10;
		x /= 10;
	}
	return sum;
}