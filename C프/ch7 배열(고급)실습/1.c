#include <stdio.h>

int main()
{
	int a[10];

	for(int i=0;i<5;i++)
	{
		scanf("%d",a+i);
	}
	double m=0;
	for (int i = 0; i < 5; i++)
	{
		m+=a[i];
	}
	m/=5;
	for (int i = 0; i < 5; i++)
	{
		if(a[i]>m)
		printf("%d\n",a[i]);
	}
	return 0;
}