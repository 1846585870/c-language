//ȡ��3λ�������е�ˮ�ɻ�����ˮ�ɻ�����ָһ�� n λ�� ( n��3 ),����ÿ��λ�ϵ����ֵ� n ����֮�͵�����������
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