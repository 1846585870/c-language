#include<stdio.h>
int main()
{
    int n,m,k,i,j,t;
    scanf("%d %d %d",&n,&m,&k);
    double a[n][m];
    double b[2][m];
    double c[k];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%lf",&a[i][j]);
    for(i=0;i<m;i++)
    {
        b[0][i]=0;
        for(j=0;j<n;j++)
           {
                b[0][i]+=a[j][i];
                b[1][i]=i+1;
           }
            //printf("%.1lf %.0lf ",b[0][i],b[1][i]);
    }
    for(j=0;j<=m-1;j++)
        for(i=m-1;i>j;i--)
        {
            if(b[0][i]>b[0][i-1])
                {
                    t=b[0][i];
                    b[0][i]=b[0][i-1];
                    b[0][i-1]=t;
                    t=b[1][i];
                    b[1][i]=b[1][i-1];
                    b[1][i-1]=t;
                }
        }
    for(i=0;i<k;i++)
        c[i]=b[1][i];
    for(i=0;i<k;i++)
        for(j=k-1;j>i;j--)
        {
            if(c[j]>c[j-1])
            {
                t=c[j];
                c[j]=c[j-1];
                c[j-1]=t;
            }
        }
    for(i=0;i<k;i++)
    {
        printf("%.0lf",c[i]);
        if(i!=k-1)
            printf(" ");
    }
    return 0;

}
