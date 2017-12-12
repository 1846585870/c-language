#include<stdio.h>
#include<math.h>
//定义f的函数
float f(float x)
{
    float y;
    y=((x-5.0)*x+16.0)*x-80.0;
    return y;
}
//定义xpoint函数，求出弦与x轴交点
float xpoint(float x1,float x2)
{
    float y;
    y=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
    return y;
}
//定义root函数 求近似根
float root(float x1,float x2)
{
    float x,y,y1;
    y1=f(x1);
    do
    {
        x=xpoint(x1,x2);
        y=f(x);
        if(y*y1>0)//f(x)与f(x1)同号
        {
            y1=y;
            x1=x;
        }
        else x2=x;

    }
    while (fabs(y)>=1e-6);
    return(x);
}
//主函数
void main()
{
    float x1,x2,f1,f2,x;
    do
    {
        printf("input x1,x2:\n");
        scanf("%f,%f",&x1,&x2);
        f1=f(x1);
        f2=f(x2);
    }
    while (f1*f2>=0);
    x=root(x1,x2);
    printf("A root of question is %8.4f\n",x);
}
