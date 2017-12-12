#include<stdio.h>
#include<math.h>
int main()
{
    long int n,i,j,k;
    scanf("%d",&n);
    for(i=0;;i++)
        if(n%(int)pow(10,i)>=n)break;
    printf("%d\n",i);
    int a[i+1];
    for(j=i;j>0;j--)
    {
        a[j]=(int)fmod((double)n,pow(10,i-j+1))/(int)pow(10,i-j);
        n-=a[j]*pow(10,i-j);
    }
    for(k=1;k<=i;k++)
        printf("%d ",a[k]);
    printf("\n");
    for(k=i;k>0;k--)
    {
        if(a[k]==0)
        {

        }
        else printf("%d",a[k]);
    }
    printf("\n");
    return 0;
}
