#include<stdio.h>
int main()
{
    int n=0,i,j,k,h=3,t=1,a[10];
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    for(i=0;i<4;i++)
    {
        for(k=1;k<=h;k++)
            printf(" ");
        for(j=1;j<=t;j++)
        {
            if(n<10)
            {
                printf("%d",a[n]);
                n++;
            }
            printf(" ");
        }
        t++;
        for(k=1;k<h;k++)
            printf(" ");
        printf("\n");
        h--;
    }
    return 0;
}
