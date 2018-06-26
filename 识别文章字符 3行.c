#include<stdio.h>
#define N 3
//↑↑↑↑↑↑↑↑↑↑可以修改任意行数
int main()
{
    char str[N][80];
    int i,j,letterL=0,letterS=0,num=0,blank=0,other=0;
    for(i=0;i<N;i++)
        scanf("%s",str[i]);
    for(i=0;i<N;i++)
        {for(j=0;j<strlen(str[i]);j++)
        {
            if(str[i][j]>='A'&&str[i][j]<='Z')
                letterL++;
            else if(str[i][j]>='a'&&str[i][j]<='z')
                letterS++;
            else if(str[i][j]>='0'&&str[i][j]<='9')
                num++;
            else if(str[i][j]==' ')
                blank++;
            else other++;

        }
        printf("letterL=%d,letterS=%d,num=%d,blank=%d,other=%d\n",letterL,letterS,num,blank,other);
        }
        return 0;
}
