#include<iostream>
#define maxsize 50
#define N 10
using namespace std;

//data
typedef struct ElemType
{
	char num;
	int time;
}ElemType;
typedef struct SqStack
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;
typedef struct QNode
{
	ElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct LinkQueue
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
//data
//Stack
void InitStack(SqStack &s)
{
	s.base=new ElemType[maxsize];
	if(!s.base) return;
	s.top=s.base;
	s.stacksize=N;
}

void Push(SqStack &s,ElemType e)
{
	if(s.top-s.base==s.stacksize) return;
	*s.top++=e;
}

void Pop(SqStack &s,ElemType &e)
{
	if(s.top==s.base) return;
	e=*--s.top;
}
ElemType GetTop(SqStack s)
{
	if(s.top!=s.base)
		return *(s.top-1);
}
int IfFull_Stack(SqStack &s)
{
	if(s.top-s.base==s.stacksize) return 1;//stack is full.
	else return 0;
}
//Queue
void InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=new QNode;
	Q.front->next=NULL;
}
void EnQueue(LinkQueue &Q,ElemType e)
{
	QueuePtr p;
	p=new QNode;
	p->data=e;
	p->next=NULL;Q.rear->next=p;
	Q.rear=p;
}
void DeQueue(LinkQueue &Q,ElemType &e)
{
	QueuePtr p;
	if(Q.rear==Q.front) return;
	p=Q.front->next;
	e.num=p->data.num;e.time=p->data.time;
	Q.front->next=p->next;
	if(Q.rear==p)Q.rear=Q.front;
	delete p;
}
ElemType GetHead(LinkQueue Q)
{
	if(Q.front!=Q.rear)
		return Q.front->next->data;
}
int Getnum_Q(LinkQueue Q,ElemType e)
{
	QueuePtr p;
	int i=0;
	for(p=Q.front->next;p!=NULL;i++,p=p->next)
		if(p->data.num==e.num&&p->data.time==e.time)
		{i++;break;}
	return i;
}
int IfEmpty_Queue(LinkQueue Q)
{
	if(Q.front==Q.rear)
		return 1;//Queue is empty
	else return 0;
}
int main()
{
	char c,carnum;
	int time,i,j;
	ElemType e,t[N+1],u;
	SqStack s;LinkQueue Q;
	InitStack(s);InitQueue(Q);
	cout << "*************Welcome to Parking Management System*************" << endl;
	cout << "**************Our parking pot can holds " << N << " cars***************" << endl;
	cout << "**********Operation: A(arrive)/L(leave) carnumber time********" << endl;
	cout << "*******Fee details:1 dollars an hour(Notice your time)********" << endl;
	cout << "*****************Please input your operation******************" << endl;
	cout << "***********you can input (0 0 0) to exit this system**********" << endl;
	while(N!=0)
	{
		cin >> c >> carnum >> time;
		if(c=='0'&&carnum=='0'&&time==0)
			break;
		if(c=='A')//put car into parking pot.
		{
			if(!IfFull_Stack(s))//stack is not full.
			{
				e.num=carnum;e.time=time;
				Push(s,e);
				cout <<"The "<< carnum << " car is parked at No."<< s.top-s.base << " parking pot." << endl;
			}
			else //stack is full.put car into queue.
			{
				e.num=carnum;e.time=time;
				EnQueue(Q,e);
				cout << "Sorry!The parking pot is full.You need to wait at the sidewalk."<< endl;
				cout << "The " << carnum << " car is parked at No."<< Getnum_Q(Q,e)<<" sidewalk." << endl;
			}
		}
		else if(c=='L')//car leave.
		{
			for(i=1;i<=N;i++)
			{
				if(GetTop(s).num==carnum)
				{
					Pop(s,u);i--;
					cout << "The car has parked for " << time-u.time <<" hour(s).The cost is " << time-u.time << " dollar(s)." << endl;
					break;
				}
				else
				{
					Pop(s,u);
					t[i].num=u.num;t[i].time=u.time;
				}
			}
			for(j=i;j>=1;j--)
				Push(s,t[j]);
			if(!IfEmpty_Queue(Q))//Queue is not empty.
			{
				DeQueue(Q,u);
				u.time=time;
				Push(s,u);
			}
		}

	}
	return 0;
}
