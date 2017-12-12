#include<stdio.h>
#include<string.h>
int min(int x,int y)
{
    int z;
    z=x<y?x:y;
    return(z);
}

int main()
{
    char a[80],b[80];
    int lena,lenb,i,w=0;
    while(scanf("%s %s",a,b)!=EOF)
    {
        w=0;
        char sum[80],a1[80],b1[80];
        memset(a1,0,80);
        memset(b1,0,80);
        memset(sum,0,80);
        lena=strlen(a);
        lenb=strlen(b);
        //µ¹Ðò
        for(i=0;i<lena;i++)
            a1[i]=a[lena-1-i];
         for(i=0;i<lenb;i++)
            b1[i]=b[lenb-1-i];
        //printf("%s\n",a1);
        //printf("%s\n",b1);
        //µ¹Ðò½áÊø
        for(i=0;i<min(lena,lenb);i++)
        {
            if(w==0)
                if(a1[i]+b1[i]-48*2>=10)
                 {
                     w=1;
                     sum[i]=a1[i]+b1[i]-58;
                 }
                 else sum[i]=a1[i]+b1[i]-48;
            else if(w==1)
                {
                    if(a1[i]+b1[i]+1-48*2>=10)
                    {
                        w=1;
                        sum[i]=a1[i]+b1[i]+1-58;
                    }
                    else
                    {
                        sum[i]=a1[i]+b1[i]-47;
                        w=0;
                    }

                }
        }
       if(lena>lenb)
       {
           for(i=lenb;i<lena;i++)
            {if(w==0)
                sum[i]=a1[i];
            else if(a1[i]+1-48>=10)
            {
                w=1;
                sum[i]=a1[i]-10+1;
                sum[i+1]=49;
            }
            else
            {
                sum[i]=a1[i]+1;
                w=0;
            }
            }
       }
       else if(lena<lenb)
       {
           for(i=lena;i<lenb;i++)
            {
                if(w==0)
                    sum[i]=b1[i];
                else if(b1[i]+1-48>=10)
                {
                    w=1;
                    sum[i]=b1[i]-10+1;
                    sum[i+1]=49;
                }
                else
                {
                    sum[i]=b1[i]+1;
                    w=0;
                }
            }
       }
       else
       {
           if(w==1)
           {
               sum[lena]=w+48;
           }
       }
       for(i=0;i<strlen(sum);i++)
       {
           printf("%c",sum[strlen(sum)-1-i]);
       }
       printf("\n");
    }
    return 0;
}
