#include<stdio.h>
int main()
{
    int a[10];
    int i;
    int max,min;
    int max_i,min_i;
    for (i=0;i<10;i++)
        scanf("%d",&a[i]);
    max=min=a[0];
    max_i=max_i=0;
    for(i=1;i<10;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
            max_i=i;
        }
        if(a[i]<min)
        {
            min=a[i];
            min_i=i;
        }
    }
    printf("The %dth is maximum=%d\n",max_i+1,max);
    printf("The %dth is minimum=%d",min_i+1,min);
}
