/*
#include<stdio.h>
int main()
{
    double m;
    int n;
    scanf("%lf",&m);
    n=m/10;
    switch(n)
    {
        case 10:printf("A\n");break;                  //分数转换
        case 9:printf("A\n");break;
        case 8:printf("B\n");break;
        case 7:printf("C\n");break;
        case 6:printf("D\n");break;
        default:printf("E\n");
    }
    return 0;
}
*/



/*
#include<windows.h>
#include<math.h>
#include<stdio.h>
int main()
{
	double a,b,c,x1,x2,n;
	printf("这是一个求解形如ax^2+bx+c=0的标准形式的一元二次方程的实根的小程序\n");
	printf("请输入系数a:");
	scanf("%lf",&a);
	printf("请输入系数b:");
	scanf("%lf",&b);
	printf("请输入系数c:");
	scanf("%lf",&c);
	n=b*b-4*a*c;
	if(n>0)
	{
		x1=(-b+sqrt(n))/(2.0*a);                                        //求一元二次方程的实根
		x2=(-b-sqrt(n))/(2.0*a);
		printf("x1=%lf\nx2=%lf\n",x1,x2);
	}
	else if(n==0)
	{
		x1=(-b)/(2.0*a);
		x2=(-b)/(2.0*a);
		printf("x1=x2=%lf\n",x1,x2);
	}
	else
	{
		printf("无实根\n");
	}
	system("pause");
	return 0;
}
*/

/*
#include<stdio.h>>
#include<stdlib.h>
#include<windows.h>
int main()
{
    printf("I Love You!\n");
    system("color f4");
    system("pause");                                    //颜色问题
    return 0;
}
*/


/*

#include<stdio.h>
int main()
{
    int max,min,maxi,mini,i,a[10];
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    max=min=a[0];
    maxi=mini=0;
    for(i=1;i<10;i++)
        if(a[i]>max)
        {
            max=a[i];
            maxi=i+1;                                      //数组内最大与最小的数
        }
    for(i=1;i<10;i++)
        if(a[i]<min)
        {
            min=a[i];
            mini=i+1;
        }
    printf("%d %d\n%d %d\n",max,maxi,min,mini);
    return 0;
}
*/




/*
#include<stdio.h>
int main()
{
    int m,n,x,y;
    scanf("%d%d",&m,&n);
    if(m>n)
        x=n;
    else
        x=m;
    for(;x>0;)
    {
        if(m%x==0&&n%x==0)
            break;
        x--;
    }
    if(m>n)
        y=m;
    else
        y=n;
    for(;y>0;)
    {
        if(y%m==0&&y%n==0)                                            //最大公约数与最小公倍数（穷举法）
            break;
        y++;
    }
    printf("最大公约数=%d\n最小公倍数=%d\n",x,y);
    return 0;

}

*/



/*
#include<stdio.h>
int main()
{
    int p,r,n,m,temp;
    scanf("%d%d",&m,&n);
    if(n<m)
    {
        temp=n;
        n=m;
        m=temp;
    }
    p=n*m;
    while(m!=0)                                                       //最大公约数与最小公倍数（欧几里得算法）
    {
        r=n%m;
        n=m;
        m=r;
    }
    printf("最大公约数=%d\n最小公倍数=%d\n",n,p/n);
    return 0;
}

*/


/*
#include<stdio.h>
int main()
{
    char c;
    int letters=0,space=0,digit=0,other=0;
    printf("请输入一行字符：\n");
    while((c=getchar())!='\n')
    {
        if(c>='a'&&c<='z'||c>='A'&&c<='Z')
            letters++;
        else if(c==' ')
            space++;
        else if(c>='0'&&c<='9')                                      //统计字符
            digit++;
        else
            other++;
    }
    printf("字母数:%d\n空格数:%d\n数字数:%d\n其他字符数:%d\n",letters,space,digit,other);
    return 0;
}
*/

/*
#include<stdio.h>
int main()
{
    int Sn=0,i=1,t=0,a,n;
    scanf("%d%d",&a,&n);
    for(;i<=n;i++)
    {
        t=t+a;
        Sn=Sn+t;                                  //求n+nn+nnn+...的和
        a=a*10;
    }
    printf("%d\n",Sn);
    return 0;
}


*/


/*

#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d,e;
    double x1,x2,x0,fx0;
    scanf("%d %d %d %d %d\n%lf %lf",&a,&b,&c,&d,&e,&x1,&x2);
    do
    {
        x0=(x1+x2)/2;
        fx0=a*x0*x0*x0*x0+b*x0*x0*x0+c*x0*x0+d*x0+e;                               //二分法求方程的根
        if((a*x1*x1*x1*x1+b*x1*x1*x1+c*x1*x1+d*x1+e)*fx0>0)
            x1=x0;
        else
            x2=x0;
    }
    while(fabs(fx0)>1e-12);
    printf("%.10lf",x0);
    return 0;
}
*/



/*

#include<stdio.h>
#include<math.h>
int main()
{
    int s,n;                                                    //猴子吃桃问题
    scanf("%d",&n);
    s=pow(2,n)+pow(2,n-1)-2;
    printf("%d\n",s);
    return 0;
}


*/

/*

#include<stdio.h>
#include<math.h>
int main()
{
	float a,x2,x1;
	scanf("%f",&a);
	x1=a/2;
	x2=(x1+(a/x1))/2;
	while(fabs(x2-x1)>=1e-5)                                  //迭代法求算数平方根
	{
		x1=x2;
		x2=(x1+(a/x1))/2;
	}
	printf("%f\n",x2);
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
    int a,b,c,t;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b)
    {
        t=a;
        a=b;
        b=t;
    }
    if(b>c)
    {
        t=b;                                                 //三数排序输出
        b=c;
        c=t;
    }
    if(a>c)
    {
        t=a;
        a=c;
        c=t;
    }
    printf("%d %d %d\n",a,b,c);
    return 0;
}

*/

/*
#include<stdio.h>
#define PI 3.1415
int main()
{
    int r,h;
    double S1,S2,C,V;
    scanf("%d %d",&r,&h);
    C=2*PI*r;                                                            //圆柱问题
    S1=PI*r*r;
    S2=2*S1+C*h;
    V=S1*h;
    printf("%10.6lf %10.6lf %10.6lf %10.6lf\n",C,S1,S2,V);
    return 0;
}

*/

/*
#include<stdio.h>
#include<math.h>
int main()
{
    int n,a,b,c,d,e,i;
    scanf("%d",&n);
    for(i=0;;i++)
        if(n%(int)pow(10,i)==n)
        break;
    printf("%d\n",i);
    switch(i)
    {
        case 5:{a=n/10000;b=n/1000-a*10;e=n%10;d=(n%100-e)/10;c=(n%1000-d*10-e)/100;printf("%d %d %d %d %d\n",a,b,c,d,e);};break;
        case 4:{b=n/1000;e=n%10;d=(n%100-e)/10;c=(n%1000-d*10-e)/100;printf("%d %d %d %d\n",b,c,d,e);};break;
        case 3:{e=n%10;d=(n%100-e)/10;c=(n%1000-d*10-e)/100;printf("%d %d %d\n",c,d,e);};break;
        case 2:{e=n%10;d=(n%100-e)/10;printf("%d %d\n",d,e);};break;
        case 1:{e=n%10;printf("%d\n",e);};break;
    }
    switch(i)
    {
        case 5:n=e*10000+d*1000+c*100+b*10+a;break;                            //五位正整数问题
        case 4:n=e*1000+d*100+c*10+b;break;
        case 3:n=e*100+d*10+c;break;
        case 2:n=e*10+d;break;
        case 1:n=e;break;
    }
    printf("%d\n",n);
    return 0;
}
*/

/*
#include<stdio.h>
int main()
{
    int n,m,i,k,j=0;
    scanf("%d%d",&n,&m);
    int a[n];
    for(i=0;i<n;i++)
        a[i]=i+1;
    for(k=0;k<n;)
    {
        for(i=0;i<n;i++)
        {
            j++;
            if(a[i]!=0)
            {
                if(j==m)
                {
                    printf("%d ",a[i]);                                      //约瑟夫环
                    a[i]=0;
                    j=0;
                    k++;
                }
            }
            else
                j--;
        }
    }
    return 0;
}
*/


/*

#include<stdio.h>
int main(void)
{
    int i,j,n,t,w,c[1000],q=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        w=0;
        int a[n],b[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            scanf("%d",&b[i]);
        for(j=0;j<n-1;j++)
            for(i=0;i<n-1-j;i++)
                if(a[i]<a[i+1])
                {
                    t=a[i];
                    a[i]=a[i+1];
                    a[i+1]=t;
                }
        for(j=0;j<n-1;j++)
            for(i=0;i<n-1-j;i++)                                         //渊子赛马
                if(b[i]<b[i+1])
                {
                    t=b[i];
                    b[i]=b[i+1];
                    b[i+1]=t;
                }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(a[i]>b[j])
                {
                    w++;
                    b[j]=a[i];
                    break;
                }
        if(w>n/2)
            c[q]=1;
        else
            c[q]=0;
        q++;
    }
    for(i=0;i<=q;i++)
    {
        if(c[i]==1)
            printf("Yes\n");
        if(c[i]==0)
            printf("No\n");
    }
    return 0;
}
*/


/*
#include<stdio.h>
int main()
{
    int i,j,k,n,h=3;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        h++;
        for(k=1;k<=n-i;k++)
            printf(" ");
        for(j=1;j<=i;j++)
        {
            printf("*");
            if(i+3<=h)
                printf(" ");
        }
        printf("\n");
    }
    for(i=1;i<=n-1;i++)                                //n阶钻石
    {
        h++;
        for(k=1;k<=i;k++)
            printf(" ");
        for(j=n;j>=i+1;j--)
        {
            printf("*");
            if(i+3<=h)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

*/



/*
#include<stdio.h>
int main()
{
    int m=0,n=0,i;
    char a[500];
    while(scanf("%s",a)!=EOF)
    {
        for(i=0;a[i];i++)
            if(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z')
            {
                if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U')   //元音、辅音
                    m++;
                else
                    n++;
            }
        printf("%d %d\n",m,n);
        m=0;
        n=0;
    }
    return 0;
}
*/

/*
#include<stdio.h>
#include<math.h>
int main()
{
    int x,p,n,y,i,j,c,d,e,f,t,s=0,k=10,a[50],b[50];
    scanf("%d %d %d %d",&x,&p,&n,&y);
    for(i=0;;i++)
        if(x/(int)pow(10,i)==0)
            break;
    for(j=i-1;j>=0;j--)
    {
        a[j]=x%10;
        x=x/10;
    }
    for(c=0;;c++)
        if(y/(int)pow(10,c)==0)                   //整数位移1
            break;
    for(d=0;d<c;d++)
    {
        b[d]=y%10;
        y=y/10;
    }
    for(e=p-1,f=0;e<=n;e++,f++)
    {
        a[e]=b[f];
    }
    for(t=i-2;t>=0;t--)
    {
        s=s+a[t]*k;
        k=10*k;
    }
    x=s+a[i-1];
    printf("%d\n",x);
    return 0;
}
*/


/*
#include<stdio.h>
int main()
{
    int n,m,i,j,maxj,t,p,max;
    scanf("%d %d",&n,&m);
    int a[n][m];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
    {
        max=a[i][0];
        for(j=0;j<m;j++)
            if(a[i][j]>max)
            {
                max=a[i][j];
                maxj=j;
            }
        t=1;
        for(p=0;p<n;p++)
            if(a[p][maxj]<max)                  //鞍点
            {
                t=0;
                continue;
            }
        if(t)
        {
            printf("%d %d %d\n",i,maxj,max);
            break;
        }
    }
    if(!t)
        printf("It does not exist!\n");
    return 0;
}
*/

/*
#include<stdio.h>
int main(void)
{
    int x,n,i,j,t,k,b[20];
    while(scanf("%d %d",&x,&n)!=EOF)
    {
        for(i=0;;i++)
            if(x/(int)pow(10,i)==0)
                break;
        if(n>i)
            n=n%i;
        int a[i];
        for(j=i-1;j>=0;j--)
        {
            a[j]=x%10;
            x=x/10;
        }                                                  //整数位移2
        for(t=0;t<i;t++)
        {
            b[t]=a[i-n];
            n--;
            if(n==0)
                n=i;
        }
        for(k=0;k<i;k++)
            printf("%d",b[k]);
        printf("\n");
    }
    return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    while(scanf("%s",a)!=EOF)
    {
        int i,j=0,n,k,t=0;
        char b[100];
        n=strlen(a);
        for(i=n-1;i>=0;i--)
        {
            b[j]=a[i];                                     //判断回文
            j++;
        }
        for(k=0;k<n;k++)
            if(a[k]==b[k])
                t++;
        if(t==n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
int main()
{
    char a[80],b[80];
    while(scanf("%s %s",a,b)!=EOF)
    {
        int i,j,m,n;
        m=strlen(a);
        n=strlen(b);
        int x[80],y[80];
        if(m>=n)
        {
            for(i=m-1,j=n-1;j>=0;i--,j--)
                b[i]=b[j];
            for(i=0;i<m-n;i++)
                b[i]='0';
            for(i=0;i<m;i++)
                x[i]=a[i]-48;
            for(i=0;i<m;i++)
                y[i]=b[i]-48;
            for(i=m-1;i>=0;i--)
            {
                x[i]=x[i]+y[i];
                if(x[i]>=10&&i>0)
                {
                    x[i]=x[i]-10;
                    x[i-1]=x[i-1]+1;
                }
            }
            for(i=0;i<m;i++)
                printf("%d",x[i]);
            printf("\n");
        }
        else
        {
            for(i=m-1,j=n-1;i>=0;i--,j--)                    //高精度加法
                a[j]=a[i];
            for(i=0;i<n-m;i++)
                a[i]='0';
            for(i=0;i<n;i++)
                x[i]=a[i]-48;
            for(i=0;i<n;i++)
                y[i]=b[i]-48;
            for(i=n-1;i>=0;i--)
            {
                y[i]=x[i]+y[i];
                if(y[i]>=10&&i>0)
                {
                    y[i]=y[i]-10;
                    y[i-1]=y[i-1]+1;
                }
            }
            for(i=0;i<n;i++)
                printf("%d",y[i]);
            printf("\n");
        }
    }
    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,a[10],p[10],vis[10];
void digui(int l)
{
    int i;
    if(l>n)
    {
        for(i=1;i<n;i++)
        {
            printf("%d ",p[i]);
        }
        printf("%d\n",p[n]);
    }
    for(i=1;i<=n;i++)
    {
        if(!vis[a[i]])
        {
            p[l]=a[i];
            vis[a[i]]=1;                                        //生成全排列
            digui(l+1);
            vis[a[i]]=0;
        }
    }
}
int main()
{
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            a[i]=i;
        }
        memset(vis,0,sizeof(vis));
        digui(1);
    }
    return 0;
}
*/

/*
#include<stdio.h>
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        if(b<0)
            b=-b;
        if(c<0)
            c=-c;
        if(a+b+c==4)
            printf("%d+%d+%d\n",a,b,c);
        else if(a+b-c==4)
            printf("%d+%d-%d\n",a,b,c);                           //通关密码
        else if(a-b+c==4)
            printf("%d-%d+%d\n",a,b,c);
        else if(a-b-c==4)
            printf("%d-%d-%d\n",a,b,c);
        else
            printf("no\n");
    }
    return 0;
}
*/

/*
#include<stdio.h>
int insert(int a[],int b,int c,int x)
{
    int i,p,d[10000];
    for(i=0;i<c;i++)
    {
        if(a[i]==b)
        {
            p=i;
            break;
        }
    }
    for(i=p;i<c;i++)
        d[i+1]=a[i];
    a[p]=x;
    for(i=p+1;i<c+1;i++)
        a[i]=d[i];
    return *a;
}
int outsert(int a[],int b,int x)
{
    int i,p=-1,d[10000];
    for(i=0;i<x;i++)
    {
        if(a[i]==b)
        {
            p=i;
            break;
        }
    }
    for(i=p+1;i<x;i++)
        d[i-1]=a[i];
    for(i=p;i<x;i++)
        a[i]=d[i];
    return *a;
}
int main()
{
    int a[10000],i,len,m,n,l;
    int *p;
    char c;
    p=a;
    for(i=0;i<10000;i++)
    {
        scanf("%d",&a[i]);                                            //插队
        if(a[i]==-1)
        {
            len=i;
            break;
        }
    }
    c=getchar();
    while(c!='#')
    {
        switch(c)
        {
            case'C':printf("%d\n",len);break;
            case'A':scanf("%d %d",&m,&n);for(i=0;i<len;i++)if(a[i]==m)break;if(i!=len){len++;*a=insert(a,m,len,n);}else printf("Not in the queue\n");break;
            case'D':scanf("%d",&l);for(i=0;i<len;i++)if(a[i]==l)break;if(i!=len){*a=outsert(a,l,len);len--;}else printf("Not in the queue\n");
            default:break;
        }
        c=getchar();
    }
    printf("The last one is %d\n",a[len-1]);
    return 0;
}
*/

/*
#include<stdio.h>
int main()
{
    int n,m,k,i,j,t,s=0;
    scanf("%d%d%d",&n,&m,&k);
    double a[n][m],b[m],sum;
    int c[k];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%lf",&a[i][j]);
    for(i=0;i<m;i++)
    {
        for(j=0,sum=0;j<n;j++)                                     //设计T恤
        {
            sum+=a[j][i];
        }
        b[i]=sum;
    }
    for(i=0;i<m;i++)
    {
        for(j=0,t=0;j<m;j++)
            if(b[i]>b[j])
                t++;
        if(t>=m-k)
        {
            c[s]=i+1;
            s++;
        }
    }
    for(t=k-1;t>=0;t--)
        printf("%d ",c[t]);
    printf("\n");
    return 0;
}
*/

/*
#include<stdio.h>
int main()
{
    int n,k,i,j,t,s=0;
    scanf("%d %d",&n,&k);
    int a[n][2],b[k],c[k];
    for(i=0;i<n;i++)
        for(j=0;j<2;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
    {
        for(j=0,t=0;j<n;j++)
            if(a[i][0]>a[j][0])
                t++;
        if(t>=n-k)
        {
            b[s]=i+1;                                             //选举时刻
            c[s]=a[i][1];
            s++;
        }
    }
    for(i=0;i<k;i++)
    {
        for(j=0,t=0;j<k;j++)
            if(c[i]>c[j])
                t++;
        if(t==k-1)
            printf("%d\n",b[i]);
    }
    return 0;
}
*/

/*
#include<stdio.h>
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        int a[n][n];
        for(i=0;i<n;i++)
            a[i][0]=a[i][i]=1;
        for(i=2;i<n;i++)
            for(j=1;j<i;j++)
                a[i][j]=a[i-1][j]+a[i-1][j-1];                          //打印杨辉三角
        for(i=0;i<n;i++)
        {
            for(j=0;j<i+1;j++)
                printf("%d  ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
*/

/*
#include<stdio.h>
int GCD(int m,int n)
{
    int r,t;
    if(m<n)
    {
        t=m;
        m=n;
        n=t;
    }
    while(n!=0)
    {
        r=m%n;                                                //最大公约数（函数）
        m=n;
        n=r;
    }
    return(m);
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
        printf("%d\n",GCD(a,b));
    return 0;
}
*/

/*
#include<stdio.h>
int main()
{
    int n,t;
    double i,sum;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1,sum=0;;i++)
        {
            sum=sum+1/i;
            if((int)sum==n)
            {
                t=(int)i;
                printf("%d\n",t);                       //小龟的环球旅行
                break;
            }
        }
    }
    return 0;
}
*/

/*
#include <stdio.h>
int main()
{
    int i,j,r;
    for(i=9;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            r=i*j;
            printf("%d*%d=%d ",i,j,r);                          //打印9*9乘法表
            if(r<10)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
*/


/*
#include<stdio.h>
#include<math.h>
int main()
{
    int n,w;
    while(scanf("%d",&n)!=EOF)
    {
        for(w=1;;w++)
            if((n/(int)pow(10,w))==0)
                break;
        printf("%d\n",w);
    }
    return 0;
}

#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j,t,a[5],w;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=n;i<10000;i++)
        {
            for(j=2;j<=sqrt(i);j++)
                if(i%j==0)
                    break;
            if(j>=sqrt(i)+1)
            {
                t=i;
                printf("%d\n",t);
                for(w=1;;w++)
                    if((t/(int)pow(10,w))==0)
                        break;
                printf("%d\n",w);

            }
        }
    }
    return 0;
}
*/

/*
#include<stdio.h>
#define N 10
struct student
{
    int num;
    char name[20];
    double score[3];
    double aver;
};
void input(struct student stu[])
{
    int i;
    printf("请输入各学生的信息：学号、姓名、3门课成绩：\n");
    for(i=0;i<N;i++)
    {
        scanf("%d%s%lf%lf%lf",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
    }
}
struct student max(struct student stu[])
{
    int i,m=0;
    for(i=0;i<N;i++)
        if(stu[i].aver>stu[m].aver)
            m=i;
    return stu[m];
};
void print(struct student stu)
{
    printf("\n成绩最高的学生是：\n");
    printf("学号：%d\n姓名：%s\n三门课成绩：%5.1lf,%5.1lf,%5.1lf\n平均成绩：%6.2lf\n",stu.num,stu.name,stu.score[0],stu.score[1],stu.score[2],stu.aver);
}
int main()
{
    struct student stu[N],*p=stu;
    input(p);
    print(max(p));
    return 0;
}
*/


#include<stdio.h>
int main()
{
    int n,h,l,i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        h=0;
        l=(n-1)/2;
        int a[n][n];
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                a[i][j]=0;
        a[h][l]=1;
        for(k=2;k<=(n*n);k++)
        {
            h--;
            l++;
            if(h==-1)
                h=n-1;
            if(l==n)
                l=0;
            if(a[h][l]!=0)
            {
                for(i=0;i<n;i++)
                    for(j=0;j<n;j++)
                        if(k-1==a[i][j])
                        {
                            h=i+1;
                            l=j;
                            if(h==n)
                                h=0;
                        }
                a[h][l]=k;
            }
            else
            {
                a[h][l]=k;
            }
        }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                printf("%d",a[i][j]);
                if(j==n-1)
                {
                    printf("\n");
                    break;
                }
                printf(" ");
            }
    }
    return 0;
}
















