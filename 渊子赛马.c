#include<stdio.h>
int main()
{
    int N,i,j=0,k,l,win,result[99]={3};
    while(scanf("%d",&N)!=EOF)
    {
        if(N!=0)
        {
           int a[N+1],b[N+1];
           for(i=1;i<=N;i++)
           {
               scanf("%d",&a[i]);
           }
           for(i=1;i<=N;i++)
           {
               scanf("%d",&b[i]);
           }
           win=0;
           for(l=1;l<N;l++)
           {


           for(i=1;i<N;i++)
           {
               if(a[i]>a[i+1])
               {
                   k=a[i+1];
                   a[i+1]=a[i];
                   a[i]=k;
               }
           }
           }

             for(l=1;l<N;l++)
           {


           for(i=1;i<N;i++)
           {
               if(b[i]>b[i+1])
               {
                   k=b[i+1];
                   b[i+1]=b[i];
                   b[i]=k;
               }
           }
           }


           int af=1,bf=1,al=N,bl=N;
           for(i=1;i<=N;i++)
           {
               if(a[af]>b[bf])
               {
                   af++;
                   bf++;
                   win++;
               }
               else if(a[af]<b[bf])
               {
                   al--;
                   bf++;
                   win--;
               }
               else
               {
                   if(a[al]>b[bl])
                   {
                       al--;
                       bl--;
                       win++;
                   }
                   else if(a[al]<b[bl])
                   {
                       al--;
                       bf++;
                       win--;
                   }
                   else
                   {
                       if(a[al]<b[bf])
                       {
                           al--;
                           bf++;
                           win++;
                       }
                   }
               }
           }
           j++;
           if(win>0)
            result[j]=2;
           else result[j]=1;
        }
        else break;
    }

    for(i=1;i<=j;i++)
    {
       if(result[i]=1)
       printf("NO\n");
       else if(result[i]=2)
       printf("YES\n");
       else break;
    }

    return 0;
}
