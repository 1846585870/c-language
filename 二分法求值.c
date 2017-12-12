#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d,e;
    double x1,x2,m,result;
    scanf("%d %d %d %d %d\n%lf %lf",&a,&b,&c,&d,&e,&x1,&x2);
    do
    {
        m=(double)(x1+x2)/2;
        result=m*m*m*m*a+m*m*m*b+m*m*c+m*d+e;
        if(result==0)
            printf("%.10lf",m);
        else if(result*(x1*x1*x1*x1*a+x1*x1*x1*b+x1*x1*c+x1*d+e)>0)
            x1=m;
        else x2=m;
    }
    while (fabs(result)>1e-12);
    printf("%.10lf",m);
    return 0;
}
