
#define TRUE	1
#define FALSE	0
#define MIN -2147483646


#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int main()
{
    int n;
    int type;
    int id;
    int cnt=0;
    int maxcnt=MIN;
    int maxid[100000]={0,};
   for(int i=0;i<30000;i++)
   maxid[i]=MIN;


    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&type);
        getchar();
        if(type == 1)
        {
            cnt++;
            scanf("%d",&id);
            if(cnt>=maxcnt)
            {
                maxcnt=cnt;
                
                if(maxid[maxcnt]<id)
                {
                    maxid[maxcnt]=id;
                // printf("max : %d\n",maxid[maxcnt]);
            }
            }
        }
        if(type ==2)
        {
            cnt--;
        }
    }
    printf("%d %d\n",maxcnt,maxid[maxcnt]);
    return 0;
}