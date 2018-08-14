#include<stdio.h>
int array[]={23,34,12,17,204,99,16};
#define TOTAL_ELEMENTS (sizeof(array)/sizeof(array[0]))
int main()
{
    int d=-1,x;

    if(d <= (int)TOTAL_ELEMENTS-2)//sizeof返回为unsigned int 类型
        x=array[d+1];
    printf("%d",x);
}
//输出结果为23

/*
int main()
{
    int d=-1,x;

    if(d <= TOTAL_ELEMENTS-2)
        x=array[d+1];
    printf("%d",x);
}
*/
//输出结果为随机数
