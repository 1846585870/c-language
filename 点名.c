#include<stdio.h>
int main()
{
    int n,x,i,j=0;
    scanf("%d %d",&n,&x);
    int a[n+1];
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        if(a[i]==x)
            j++;
    printf("%d\n",j);
    return 0;
}
