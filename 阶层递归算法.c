#include<stdio.h>
int jc(int i)
{
    int m;
    if(i<0)
        printf("data error");
    else if(i==0||i==1)
        m=1;
    else m=i*jc(i-1);
    return m;
}
int main()
{
    int n;
    printf("Please input a number:");
    scanf("%d",&n);
    printf("This number's factorial is %d",jc(n));
}
