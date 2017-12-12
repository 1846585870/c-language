#include<stdio.h>
/*下面给出构造奇数阶魔阵的通用算法：
首先把1放在第一行中间。
当数k放好后，考虑数k+1的安放，
总把它放在向上一行，向右一个位置，
下面是各种特殊情况的处理：
（1）要从最上一行向上，那么就转移到最下一行；
（2）要从最右一列向右，那么就转移到最左一列；
（3）如果企图放数的位置已经有了数，
那么，就把这个数放在它前面一个数的下面。
（本题只考虑奇数阶，不考虑偶数阶）*/
int judge(int a[],int x,int y,int size,int kind_return)
{
    if(x-1>=0&&y+1<size)
        {
            x--;
            y++;

            if(kind_return==1)
                return x;
            if(kind_return==2)
                return y;
        }
    else if(x-1>=0&&y+1>=size)
            {
                x--;
                y=0;
                if(kind_return==1)
                    return x;
                if(kind_return==2)
                    return y;
            }
            else if(x-1<0&&y+1<size)
                {
                    x=size-1;
                    y++;
                    if(kind_return==1)
                        return x;
                    if(kind_return==2)
                        return y;
                }
                else if(x-1<0&&y+1>=size)
                    {
                        x=size-1;
                        y=0;
                        if(kind_return==1)
                            return x;
                        if(kind_return==2)
                            return y;
                    }

}
int main()
{
    int n,i,x,y,j,tx,ty;
    while(scanf("%d",&n)!=EOF)
    {
        int a[100][100]={0};
        a[0][n/2]=1;
        x=0;
        y=n/2;
        for(i=2;i<=n*n;i++)
        {
          tx=judge(a,x,y,n,1);
          ty=judge(a,x,y,n,2);
          //x=tx;
          //y=ty;

        if(a[tx][ty]==0)
                {
                    x=tx;
                    y=ty;
                    a[x][y]=i;
                }
            else if(a[tx][ty]<i)
                {
                    if(x-1>n-1)
                        x=0;
                    else x++;
                    a[x][y]=i;

                }
          }


      for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                    {
                        printf("%d",a[i][j]);
                        if(j!=n-1)
                            printf(" ");
                    }
                printf("\n");
            }
    }
    return 0;

}
//while(scanf("")!=NULL)会造成OUTPUTLIMIT
