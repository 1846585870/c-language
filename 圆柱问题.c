#include<stdio.h>
#define PI 3.1415
int main()
{
    int r,h;
    double S1,S2,C,V;
    scanf("%d %d",&r,&h);
    C=2*PI*r;
    S1=PI*r*r;
    S2=2*S1+C*h;
    V=S1*h;
    printf("%10.6lf %10.6lf %10.6lf %10.6lf\n",C,S1,S2,V);
    return 0;
}
