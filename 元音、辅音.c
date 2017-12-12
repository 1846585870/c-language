#include<stdio.h>
int main()
{
    int m=0,n=0,i;
    char a[500];
    while(scanf("%s",a)!=EOF)
    {
        for(i=0;a[i];i++)
            if(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z')
            {
                if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U')
                    m++;
                else
                    n++;
            }
        printf("%d %d\n",m,n);
        m=0;
        n=0;
    }
    return 0;
}
