#include<stdio.h>
int main()
{
    int n,m,i,j,maxj,t,p,max;
    scanf("%d %d",&n,&m);
    int a[n][m];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
    {
        max=a[i][0];
        for(j=0;j<m;j++)
            if(a[i][j]>max)
            {
                max=a[i][j];
                maxj=j;
            }
        t=1;
        for(p=0;p<n;p++)
            if(a[p][maxj]<max)
            {
                t=0;
                continue;
            }
        if(t)
        {
            printf("%d %d %d\n",i,maxj,max);
            break;
        }
    }
    if(!t)
        printf("It does not exist!\n");
    return 0;
}
