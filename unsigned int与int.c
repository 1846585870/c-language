#include<stdio.h>
int array[]={23,34,12,17,204,99,16};
#define TOTAL_ELEMENTS (sizeof(array)/sizeof(array[0]))
int main()
{
    int d=-1,x;

    if(d <= (int)TOTAL_ELEMENTS-2)//sizeof����Ϊunsigned int ����
        x=array[d+1];
    printf("%d",x);
}
//������Ϊ23

/*
int main()
{
    int d=-1,x;

    if(d <= TOTAL_ELEMENTS-2)
        x=array[d+1];
    printf("%d",x);
}
*/
//������Ϊ�����
