#include<windows.h>
#include<math.h>
#include<stdio.h>
int main()
{
	double a,b,c,x1,x2,n;
	printf("这是一个求解形如ax^2+bx+c=0的标准形式的一元二次方程的实根的小程序\n");
	printf("请输入系数a:");
	scanf("%lf",&a);
	printf("请输入系数b:");
	scanf("%lf",&b);
	printf("请输入系数c:");
	scanf("%lf",&c);
	n=b*b-4*a*c;
	if(n>0)
	{
		x1=(-b+sqrt(n))/(2.0*a);
		x2=(-b-sqrt(n))/(2.0*a);
		printf("x1=%lf\nx2=%lf\n",x1,x2);
	}
	else if(n==0)
	{
		x1=(-b)/(2.0*a);
		x2=(-b)/(2.0*a);
		printf("x1=x2=%lf\n",x1,x2);
	}
	else
	{
		printf("无实根\n");
	}
	system("pause");
	return 0;
}
