#include<stdio.h>
#include<math.h>
int main()
{
    int s,n;
    scanf("%d",&n);
    s=pow(2,n)+pow(2,n-1)-2;
    printf("%d\n",s);
    return 0;
}
