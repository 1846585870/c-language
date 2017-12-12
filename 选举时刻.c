#include<stdio.h>
int main()
{
    int n,k,i,j,t,s=0;
    scanf("%d %d",&n,&k);
    int a[n][2],b[k],c[k];
    for(i=0;i<n;i++)
        for(j=0;j<2;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
    {
        for(j=0,t=0;j<n;j++)
            if(a[i][0]>a[j][0])
                t++;
        if(t>=n-k)
        {
            b[s]=i+1;
            c[s]=a[i][1];
            s++;
        }
    }
    for(i=0;i<k;i++)
    {
        for(j=0,t=0;j<k;j++)
            if(c[i]>c[j])
                t++;
        if(t==k-1)
            printf("%d\n",b[i]);
    }
    return 0;
}
