#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i;
    while(gets(str)!=NULL)
    {
        for(i=0;i<strlen(str);i++)
            {
                if(i==0)
                    {
                        if(str[i]>='a'&&str[i]<='z')
                            str[i]-=32;
                    }
                else if(str[i]==' ')
                    {
                        if(str[i+1]>='a'&&str[i+1]<='z')
                            str[i+1]-=32;
                    }
            }
        printf("%s",str);

    }

    return 0;
}
