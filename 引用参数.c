#include<stdio.h>
int multiply(int *a,int *b)
{
    *a=*a*(*b);
}
int main()
{
    int a=4,b=4;
    multiply(&a,&b);
    printf("a=%d,b=%d",a,b);
}
