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
int counta=0;
int visited[maxsize][maxsize]={0};
SElemType result[maxsize*maxsize];

int InitStack(LinkStack &s)
{
	s=NULL;
	return 1;
}
int Push(LinkStack &s,SElemType e)
{
	LinkStack p;
	p=new StackNode;
	p->data=e;
	p->next=s;
	s=p;
	return 1;
}
int Pop(LinkStack &s)
{
	LinkStack p;
	if(s==NULL) return 0;
	p=s;
	s=s->next;
	delete p;
	return 1;
}
int IfEmpty_Stack(LinkStack &s)
{
	if(s==NULL) return 1;
	else return 0;
}
void OutPrint_maze()
{
    int i,j;
    for(i=0;i<length+2;i++)
    {
        for(j=0;j<width+2;j++)
        {
            if(maze[i][j]==1)
                cout << "¡ö" ;
            else if(maze[i][j]==0&&visited[i][j]==0)
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
PosType Nextpos(PosType pos,int n)
{
    PosType next;
    switch(n)
    {
        case 1: next.i=pos.i;next.j=pos.j+1;break;
        case 2: next.i=pos.i+1;next.j=pos.j;break;
        case 3: next.i=pos.i;next.j=pos.j-1;break;
        case 4: next.i=pos.i-1;next.j=pos.j;break;
        default: break;
    }
    return next;
}
OutPrint_Path(LinkStack &s)
{
    LinkStack p;int i;
    for(p=s,i=0;p!=NULL;p=p->next,i++)
        {
            maze[p->data.a.i][p->data.a.j]=2;
            result[i]=p->data;
        }
    OutPrint_maze();
    for(i--;i>=0;i--)
        cout << "<" <<result[i].a.i << "," << result[i].a.j << ","<< result[i].direction << ">" ;
    cout << endl;
    for(p=s;p!=NULL;p=p->next)
        maze[p->data.a.i][p->data.a.j]=0;
}
void Find_Path()
{
    counts=0;counta=0;
    LinkStack s;
    SElemType e;
    InitStack(s);
    counts++;e.num=counts;e.a=start;e.direction=1;
    Push(s,e);
    visited[start.i][start.j]=1;
    do
    {
        PosType next;
        next=Nextpos(s->data.a,s->data.direction);
        if(maze[next.i][next.j]==0&&!visited[next.i][next.j])
        {
            visited[next.i][next.j]=1;
            if(next.i==ending.i&&next.j==ending.j)
            {
                counts++;
                e.num=counts;e.a=next;e.direction=1;
                Push(s,e);
                OutPrint_Path(s);
                counta++;
                cout << endl;
                Pop(s);
                counts--;
                s->data.direction++;
                visited[next.i][next.j]=0;
                while(s->data.direction>4)
                {
                    visited[s->data.a.i][s->data.a.j]=0;
                    Pop(s);
                    s->data.direction++;
                    counts--;
                }
                continue;
            }
            else
            {
                counts++;
                e.num=counts;e.a=next;e.direction=1;
                Push(s,e);
            }
        }
        else
        {
            if(!IfEmpty_Stack(s)&&s->data.direction<4)
               {s->data.direction++;continue;}
            else if(!IfEmpty_Stack(s)&&s->data.direction==4)
            {
                visited[s->data.a.i][s->data.a.j]=0;
                Pop(s);
                counts--;
                if(s==NULL) break;
                s->data.direction++;
                while(s->data.direction>4)
                {
                    visited[s->data.a.i][s->data.a.j]=0;
                    Pop(s);
                    s->data.direction++;
                    counts--;
                }
                continue;
            }

        }
    }while(!IfEmpty_Stack(s));
    if(counta==0)
        cout << "cannot find a path!" << endl;
    else cout << "The count is " << counta << "." << endl;
}
int main()
{
	char m;
	do
    {
        int i,j,a,b;
        cout << "please input the length and width:" << '\n';
        cin >> length >> width;
        a=length+2;b=width+2;
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
        cout << endl;
        maze[start.i][start.j]=0;
        maze[ending.i][ending.j]=0;
        Find_Path();
        cout << endl << "Do you want to continue?(Y/N)" << endl;
        cin >> m;
    }while(m=='Y');

	return 0;
}
