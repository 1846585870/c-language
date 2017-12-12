#include<stdio.h>
int main()
{
    char c;
    int i,a[6],j;
    c=getchar();
    for(i=0;c!='\n';i++)
    {
        a[i+1]=c-48;
        c=getchar();
    }
    printf("%d\n",i);
    for(j=1;j<=i;j++)
        printf("%d ",a[j]);
    printf("\n");
    for(j=i;j>0;j--)
    {
        if(a[j]!=0)
        printf("%d",a[j]);
    }
    return 0;
}
