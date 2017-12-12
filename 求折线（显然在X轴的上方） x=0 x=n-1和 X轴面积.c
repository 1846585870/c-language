#include<stdio.h>
int main()
{
    int n,i;
    double area;
    while(scanf("%d",&n)!=EOF)
    {
        double a[n];
        area=0;
        for(i=0;i<n;i++)
            scanf("%lf",&a[i]);
        for(i=1;i<=n-1;i++)
        {
            area+=(a[i-1]+a[i])/2.0;
        }
        printf("%.3lf\n",area);
    }
    return 0;
}
