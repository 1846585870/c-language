#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d,e;
    double x1,x2,x0,fx0;
    scanf("%d %d %d %d %d\n%lf %lf",&a,&b,&c,&d,&e,&x1,&x2);
    do
    {
        x0=(x1+x2)/2;
        fx0=a*x0*x0*x0*x0+b*x0*x0*x0+c*x0*x0+d*x0+e;
        if((a*x1*x1*x1*x1+b*x1*x1*x1+c*x1*x1+d*x1+e)*fx0>0)
            x1=x0;
        else
            x2=x0;
    }
    while(fabs(fx0)>1e-12);
    printf("%.10lf",x0);
    return 0;
}
