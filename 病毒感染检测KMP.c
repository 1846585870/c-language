#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxlen 255
typedef struct                                   //�ṹ��
{
    char ch[maxlen+1];
    int length;
}Sstring;
void get_next(Sstring t,int next[])              //next����
{
    int i,j;
    i=1;next[1]=0;j=0;
    while(i<t.length)
    {
        if(j==0||t.ch[i]==t.ch[j]){++i;++j;next[i]=j;}
        else j=next[j];
    }
}
int Index_KMP(Sstring s,Sstring t,int pos)      //KMP�㷨
{
    int i,j,k,next[maxlen];
    i=pos;j=1;
    get_next(t,next);
    while(i<=s.length&&j<=t.length)
    {
        if(j==0||s.ch[i]==t.ch[j]){i++;j++;}
        else j=next[j];
    }
    if(j>t.length) return 1;                    //ƥ��ɹ�
    else return 0;                              //ƥ��ʧ��
}
int virus()
{
    Sstring s,t,temp;
    int i,j,k;
    while(scanf("%s %s",&t.ch[1],&s.ch[1])!=EOF)
    {
        if(strcmp(&t.ch[1],"0")==0&&strcmp(&s.ch[1],"0")==0) break;
        t.length=strlen(&t.ch[1]);
        s.length=strlen(&s.ch[1]);
        for(i=1,j=i+t.length;i<=t.length;i++,j++) //�ַ�������һ��
            t.ch[j]=t.ch[i];
        t.ch[t.length*2+1]='\0';
        for(i=1;i<=t.length;i++)
        {
            for(j=i,k=1;j<i+t.length;j++,k++)
                temp.ch[k]=t.ch[j];
            temp.ch[t.length+1]='\0';
            temp.length=t.length;
            if(Index_KMP(s,temp,1)==1)
                {printf("YES\n");break;}
        }
        if(i==t.length+1) printf("NO\n");
    }

}
int main()
{
    virus();
    return 0;
}
