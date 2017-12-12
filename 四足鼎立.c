#include<stdio.h>
#include<math.h>
#define r 1
int distance(double x_1,double y_1,double x_2,double y_2)
{
    double m;
    m=(x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2);
    return m;
}
int main()
{
    int x[6];
    int y[6];
    int height,i;
    for(i=1;i<=5;i++)
    {
         scanf("%d",&x[i]);
         scanf("%d",&y[i]);
    }
    for(i=1;i<5;i++)
        if(distance((double)x[i],(double)y[i],(double)x[5],(double)y[5])<=(double)r*r)
        break;
    if(i!=5)
        height=10;
    printf("%d",height);
    return 0;
}
