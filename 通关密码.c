#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(b<0)
        b=-b;
    if(c<0)
        c=-c;
    if(a+b+c==4)
        printf("%d+%d+%d",a,b,c);
    else if(a+b-c==4)
        printf("%d+%d-%d",a,b,c);
    else if(a-b+c==4)
        printf("%d-%d+%d",a,b,c);
    else if(a-b-c==4)
        printf("%d-%d-%d",a,b,c);
    else
        printf("no");
    return 0;
}
