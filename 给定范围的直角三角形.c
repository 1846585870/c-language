#include<stdio.h>
int main()
{
    int l,r,i,j,k,exist;
    while(scanf("%d %d",&l,&r)!=EOF)
    {
        exist=0;
        for(i=l;i<=r-2;i++)
            for(j=i+1;j<=r-1;j++)
                for(k=j+1;k<=r;k++)
                    if(i*i+j*j==k*k)
                    {
                        printf("%d %d %d\n",i,j,k);
                        exist++;
                    }
        if(exist==0)
            printf("NO\n");
    }
    return 0;
}
