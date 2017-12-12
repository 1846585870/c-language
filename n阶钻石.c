#include<stdio.h>
int main()
{
    int n,h,i,j;
    scanf("%d",&n);
    h=2*n-1;//×ÜÐÐÊý
    for(i=1;i<=h;i++)
        {
            if(i<=n)
            {
                for(j=1;j<=n-i;j++)
                    printf(" ");
                for(j=1;j<=i;j++)
                {
                    if(j==i)
                    {
                        printf("*");
                        printf("\n");
                    }
                    else
                    {
                        printf("*");
                        printf(" ");
                    }
                }

            }
            else
            {
                for(j=1;j<=n-1-h+i;j++)
                    printf(" ");
                for(j=1;j<=h-i+1;j++)
                {
                    if(j==h-i+1)
                    {
                        printf("*");
                        printf("\n");
                    }
                    else
                    {
                        printf("*");
                        printf(" ");
                    }
                }

            }

        }

}
