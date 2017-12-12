#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    while(scanf("%s",a)!=EOF)
    {
        int i,j=0,n,k,t=0;
        char b[100];
        n=strlen(a);
        for(i=n-1;i>=0;i--)
        {
            b[j]=a[i];
            j++;
        }
        for(k=0;k<n;k++)
            if(a[k]==b[k])
                t++;
        if(t==n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
