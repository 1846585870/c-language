#include<stdio.h>
int main()
{
    int n,m,i,j=0,k;
    scanf("%d %d",&n,&m);
    int a[n+1];
    for(i=1;i<n+1;i++)
        a[i]=i;

    for(k=0;k<n;)
    {
        for(i=1;i<n+1;i++)
        {
        j++;
        if(a[i]!=0)
        {
            if(j%m==0)
            {printf("%d ",a[i]);
            a[i]=0;
            k++;}
        }
        else j--;
        }
    }
    return 0;
}
