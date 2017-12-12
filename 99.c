#include<stdio.h>
#include<math.h>
int main()
{
    int x,n,w,i,j,t;
    while(scanf("%d %d",&x,&n)!=EOF)
    {

        for(i=0;;i++)
        if(x%(int)pow(10,i)==x)
            {
                w=i;
                break;
            }

        int a[999]={0},b[999]={0};
        for(i=1;i<=w;i++)
        {
            a[w-i+1]=x%10;
            x/=10;
        }
        for(j=1;j<=n;j++)
           {
               for(i=1;i<=w;i++)
                {
                    if(i<w)
                    {
                        b[i+1]=a[i];
                    }
                    else if(i==w)
                    {
                        b[1]=a[i];
                    }
                }
                for(i=1;i<=w;i++)
                {
                    a[i]=b[i];
                }

           }
            for(i=1;i<=w;i++)
            printf("%d",a[i]);
    }
}
