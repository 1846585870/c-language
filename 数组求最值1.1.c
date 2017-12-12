#include<stdio.h>
int main()
{
    int max,min,maxi,mini,i,a[10];
    for(i=0;i<10;i++)
        scanf("%d ",&a[i]);//此处若%d后不加空格则正常，若在%d后加一个空格则程序会要求输入11个数而不是10个
    max=min=a[0];
    maxi=mini=0;
    for(i=1;i<10;i++)
        if(a[i]>max)
        {
            max=a[i];
            maxi=i+1;
        }
    for(i=1;i<10;i++)
        if(a[i]<min)
        {
            min=a[i];
            mini=i+1;
        }
    printf("%d %d\n%d %d\n",max,maxi,min,mini);
    return 0;
}
