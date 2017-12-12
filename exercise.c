#include<stdio.h>
#define PI 3.1415
int main()
{
    int r,h;
    double c,s1,s2,v;
    scanf("%d %d",&r,&h);
    c=(double)2*PI*r;
    s1=(double)PI*r*r;
    s2=(double)(2*s1+c*h);
    v=(double)s1*h;
    printf("%.6lf %.6lf %.6lf %.6lf",c,s1,s2,v);
    return 0;
}
