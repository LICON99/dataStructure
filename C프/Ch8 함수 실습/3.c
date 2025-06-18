#include <stdio.h>
int sum(int n)
{
	return n * (n + 1) / 2;
}
int main()
{
	int n;
	int ret=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		ret+=sum(i);
	}
	printf("%d",ret);
	return 0;
}