#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,w=0;
    while(scanf("%d",&n)!=EOF)
    {
        w=0;
        char strr[1000][100],strw[1000][100];
        for(i=1;i<=n;i++)
            scanf("%s",strr[i]);
        for(i=1;i<=n;i++)
            scanf("%s",strw[i]);
        for(i=1;i<=n;i++)
            {
                if(strcmp(strr[i],strw[i])==0)
                   w++;
            }
        if(w==n)
            printf("Congratulation!\n");
        else
        {
            for(i=1;i<=n;i++)
            {
                if(strcmp(strr[i],strw[i])!=0)
                    printf("%s\n",strr[i]);
                else
                    printf("\n");
            }
        }

    }
    return 0;
}
