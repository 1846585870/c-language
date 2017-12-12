#include<stdio.h>
void change(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}
void ks(int a[],int first,int a_size)
{
    int i=0,j=0;
    if(first==a_size)
    {
        for(i=0;i<a_size;i++)
        {
            printf("%d",a[i]);
            printf(" ");
        }
        printf("\n");
    }
    else
    {
        for(j=first;j<a_size;j++)
        {
            change(&a[j],&a[first]);
            ks(a,first+1,a_size);
            change(&a[j],&a[first]);
        }
    }
}
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        int a[n];
        for(i=0;i<=n;i++)
            a[i]=i+1;
        ks(a,0,n);
    }
    return 0;
}
