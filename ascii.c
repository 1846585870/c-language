#include<stdio.h>
int main()
{
    char m;
    unsigned char n;
    int i;
    for(i=0;i<255;i++)
    {
        m=i;
        n=i;
        printf("%d:%c %c\n",i,m,n);
    }
}
