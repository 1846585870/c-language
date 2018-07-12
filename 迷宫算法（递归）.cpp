#include <iostream>
#define maxsize 10

using namespace std;

//data type
typedef struct PosType
{
	int i;
	int j;
}PosType;
typedef struct SElemType
{
	int num;
	PosType a;
	int direction;
}SElemType;
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode,*LinkStack;
//data type

PosType start,ending;
int maze[maxsize][maxsize];
int length,width;
int counts=0;

void OutPrint_maze()
{
    int i,j;
    for(i=0;i<length+2;i++)
    {
        for(j=0;j<width+2;j++)
        {
            if(maze[i][j]==1)
                cout << "¡ö" ;
            else if(maze[i][j]==0)
                cout << "  " ;
                else if (maze[i][j]==-1)
                    cout << "¡ø" ;
                    else if(maze[i][j]==3)
                    cout << "¨‹" ;
                    else cout << "¡ó" ;
        }
        if(j==width+2)
            cout << endl;
    }
}
void Find_Path(int i,int j)
{
	maze[i][j]=2;
   if(i==ending.i&&j==ending.j)
	{
		   OutPrint_maze();
		   maze[i][j]=0;
		   cout << endl;
		   return;
   }
   if(maze[i][j+1]==0)
	   Find_Path(i,j+1);
   if(maze[i+1][j]==0)
		Find_Path(i+1,j);
   if(maze[i][j-1]==0)
		Find_Path(i,j-1);
   if(maze[i-1][j]==0)
		Find_Path(i-1,j);
   maze[i][j]=0;
}
int main()
{
	char m;
	do
    {
	int i,j,a,b;
	cout << "please input the length and width:" << '\n';
	cin >> length >> width;
	a=length+2;b=length+2;
	cout << "please input the maze:" << '\n';
	for(i=0;i<a;i++)
	{
        for(j=0;j<b;j++)
		{
			if(i==0||j==0||i==a-1||j==b-1)
				maze[i][j]=1;
			else
				cin >> maze[i][j];
		}
	}
	OutPrint_maze();
	cout << "please input the start:" << '\n';
    cin >> start.i >> start.j;
    maze[start.i][start.j]=-1;
    cout << "please input the end:" << '\n';
    cin >> ending.i >> ending.j;
    maze[ending.i][ending.j]=3;
    OutPrint_maze();
	maze[start.i][start.j]=0;
	maze[ending.i][ending.j]=0;
    Find_Path(start.i,start.j);
    cout << endl << "Do you want to continue?(Y/N)" << endl;
    cin >> m;
    }while(m=='Y');
	return 0;
}
