#include<stdio.h>
int main()
{
    int n,h,l,i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        h=0;
        l=(n-1)/2;
        int a[n][n];
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                a[i][j]=0;
        a[h][l]=1;
        for(k=2;k<=(n*n);k++)
        {
            h--;
            l++;
            if(h==-1)
                h=n-1;
            if(l==n)
                l=0;
            if(a[h][l]!=0)
            {
                for(i=0;i<n;i++)
                    for(j=0;j<n;j++)
                        if(k-1==a[i][j])
                        {
                            h=i+1;
                            l=j;
                            if(h==n)
                                h=0;
                        }
                a[h][l]=k;
            }
            else
            {
                a[h][l]=k;
            }
        }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                printf("%d ",a[i][j]);
                if(j==n-1)
                {
                    printf("\n");
                    break;
                }
            }
    }
    return 0;
}
