#include<stdio.h>
/*�����������������ħ���ͨ���㷨��
���Ȱ�1���ڵ�һ���м䡣
����k�źú󣬿�����k+1�İ��ţ�
�ܰ�����������һ�У�����һ��λ�ã�
�����Ǹ�����������Ĵ���
��1��Ҫ������һ�����ϣ���ô��ת�Ƶ�����һ�У�
��2��Ҫ������һ�����ң���ô��ת�Ƶ�����һ�У�
��3�������ͼ������λ���Ѿ���������
��ô���Ͱ������������ǰ��һ���������档
������ֻ���������ף�������ż���ף�*/
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
//while(scanf("")!=NULL)�����OUTPUTLIMIT
