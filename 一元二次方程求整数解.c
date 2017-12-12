#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    double disc,x1,x2;
    scanf("%d %d %d",&a,&b,&c);
    disc=b*b-4*a*c;
    x1=(-b-sqrt(disc))/(2*a);
    x2=(-b+sqrt(disc))/(2*a);
    if(disc>=0)
    {
        if((int)x1==x1)
        {
            if(disc==0)
                printf("%d",(int)x1);
            else printf("%d %d",(int)x1,(int)x2);
        }
        else printf("NO");
    }
    else printf("NO");
    return 0;
}
