//取出3位数中所有的水仙花数（水仙花数是指一个 n 位数 ( n≥3 ),它的每个位上的数字的 n 次幂之和等于它本身）
#include<stdio.h>
int main()
{
    int m,g,s,b;
    for(m=100;m<=999;m++)
    {
        g=m%10;
        s=m/10%10;
        b=m/100;
        if(m==g*g*g+s*s*s+b*b*b)
            printf("%-d\t",m);
    }
}
