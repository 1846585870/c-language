#include<windows.h>
#include<math.h>
#include<stdio.h>
int main()
{
	double a,b,c,x1,x2,n;
	printf("����һ���������ax^2+bx+c=0�ı�׼��ʽ��һԪ���η��̵�ʵ����С����\n");
	printf("������ϵ��a:");
	scanf("%lf",&a);
	printf("������ϵ��b:");
	scanf("%lf",&b);
	printf("������ϵ��c:");
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
		printf("��ʵ��\n");
	}
	system("pause");
	return 0;
}
