#include<stdio.h>
#include<string.h>
#define maxlen 255
typedef struct                                   //结构体
{
    char ch[maxlen+1];
    int length;
}Sstring;
int Index_BF(Sstring s,Sstring t,int pos)
{
    int i=pos,j=1;
    while(i<=s.length&&j<=t.length)
    {
        if(s.ch[i]==t.ch[i]){++i;++j;}
        else{i=i-j+2;j=1;}
    }
    if(j>t.length) return 1;
    else return 0;
}
void virus_detection()
{
    Sstring s,t,temp;
    int i,j,flag=0;
    while(scanf("%s %s",&t.ch[1],&s.ch[1])!=EOF)
    {
        if(strcmp(&t.ch[1],"0")==0&&strcmp(&s.ch[1],"0")==0) break;
        t.length=strlen(&t.ch[1]);
        s.length=strlen(&s.ch[1]);
        for(i=1,j=t.length+1;i<=t.length;i++,j++)
            t.ch[j]=t.ch[i];
        t.ch[t.length*2+1]='\0';
        for(i=0;i<t.length;i++)
        {
            for(j=1;j<=t.length;j++)
                temp.ch[j]=t.ch[i+j];
            temp.ch[t.length+1]='\0';
            temp.length=t.length;
            flag=Index_BF(s,temp,1);
            if(flag) break;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }

}
int main()
{
    virus_detection();
    return 0;
}
