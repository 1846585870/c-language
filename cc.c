#include<stdio.h>
int main()
{
	int x,y;
	/*百元买百鸡
	  公鸡 x 3  0<=x<=33
	  母鸡 y 2  0<=y<=50
	  小鸡 z 0.5
	  x+y+z=100
	  3z+2y+0.5z=100
	  ==5x+3y=100(**)*/
	for(x=0;x<=33;x++)
	{
		for(y=0;y<=50;y++)
			if(5*x+3*y==100)
				printf("公鸡%-2d只,母鸡%-2d只,小鸡%-2d只\n",x,y,(100-x*3-y*2)*2);
	}

}
