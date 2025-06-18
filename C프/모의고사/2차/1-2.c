#include <stdio.h>
#include <limits.h>
#pragma warning(disable : 4996)
int main()
{
	long long n;
	long long ivt;
	long long max = -1, min = -1;

	do
	{
		scanf("%d", &n);
		if (n == 0)
			continue;
		long long mod = 1;
		for (long long i = n; i != 0; i /= 10)
		{
			mod *= 10;
		}
		mod /= 10;

		long long impn = n;
		long long impmod = mod;
		ivt = 0;
		// prlong longf("impmod : %d\n", impmod);
		while (impn != 0)
		{
			ivt += impmod * (impn % 10);
			impn /= 10;
			impmod /= 10;
		}

		// 여기까지 인버팅 완료
		// prlong longf("ivt : %d\n", ivt);
		mod *= 10;
		long long com = ivt + mod * n;
		long long impcom = com;
		long long cnt = 0;
		while (impcom != 0)
		{
			if (impcom % 10 == 3)
				cnt++;
			impcom /= 10;
		}
		if (max == -1 || max < com)
			max = com;
		if (min == -1 || min > com)
			min = com;
		// prlong longf("com : %d\n", com);
		printf("%lld %lld ", com, cnt);
	} while (n != 0);
	printf("\n%lld %lld", min, max);

	return 0;
}