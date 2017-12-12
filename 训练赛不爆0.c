#include<stdio.h>
int C(int up,int down)
{
    int i,fz=1,fm=1;
    for(i=1;i<=up;i++)
        {
            fz*=down;
            down--;
        }
    for(i=1;i<=up;i++)
        fm*=i;
    return fz/fm;
}
int main()
{
    int t,i,j,k,c;
    scanf("%d",&t);
    int a[t][3];
    for(i=0;i<t;i++)
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
    for(i=0;i<t;i++)
    {
        c=0;
        if(a[i][1]==0)
            printf("0\n");
        else
        {
            for(j=1;j<=a[i][2];j++)
            {
                c+=C(a[i][2]-j,a[i][0]-a[i][1])*C(j,a[i][1]);
            }
            printf("%d\n",c);
        }
    }
    return 0;
}
