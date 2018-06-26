#include <stdio.h>
int main()
{
	int n,i,c;
	long int a;
	int b[100];
	n=1;
	scanf("%d",&a);
	c=a;
	while(c%10!=c)
	{
		c=c/10;
		n++;
	}
	b[0]=a%10;
	if(n>=2)
	{
		for(i=1;i<n;i++)
		{
			a=a/10;
			b[i]=a%10;
		}
	}
	for(i=n-1;i>=0;i--)
		printf("%d ",b[i]);
	return 0;
}
