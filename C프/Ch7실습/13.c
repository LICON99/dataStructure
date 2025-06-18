#include <stdio.h>

int main()
{
	char x[10];
	for(int i=0;i<10;i++)
	{
		scanf("%c",x+i);
	}
	for(int i=0;i<10;i++)
	{
		if(x[i]>='A'&&x[i]<='Z')
		printf("%c ",x[i]);
	}
	
	return 0;
}