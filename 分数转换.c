#include<stdio.h>
int main()
{
    double m;
    int n;
    scanf("%lf",&m);
    n=m/10;
    switch(n)
    {
        case 10:printf("A\n");break;
        case 9:printf("A\n");break;
        case 8:printf("B\n");break;
        case 7:printf("C\n");break;
        case 6:printf("D\n");break;
        default:printf("E\n");
    }
    return 0;
}
