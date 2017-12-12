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
        case 5:n=e*10000+d*1000+c*100+b*10+a;break;
        case 4:n=e*1000+d*100+c*10+b;break;
        case 3:n=e*100+d*10+c;break;
        case 2:n=e*10+d;break;
        case 1:n=e;break;
    }
    printf("%d\n",n);
    return 0;
}
