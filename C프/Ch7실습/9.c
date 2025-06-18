#include <stdio.h>

int main()
{
	int n,sum=0;
int x[10];

	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		scanf("%d",x+i);

	}
	for(int i=0;i<n;i++)
	{
		sum+=x[i];
		sum*=10;
	}
	printf("%d\n",sum/=10);
	return 0;
}