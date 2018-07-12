#include<iostream>
#include<iomanip>
#include<windows.h>
#include<time.h>
#define Window 4 //可以根据需要修改窗口数目

using namespace std;

typedef struct elemtype
{
    int arrivetime;//到达时间
    int waittime;  //逗留时间（包括等待时间和办理业务时间）
    int leavetime; //离开时间
    int starttime; //开始办理业务的时间点
    int businesstime;//办理业务所需要的时间
}elemtype;
typedef struct Node
{
    elemtype data;//数据域
    struct Node *next;//指针域
}Node,*queueptr;
typedef struct
{
    queueptr front;
    queueptr rear;
}linkqueue;

float sum_wait_time=0.0;//总共的逗留时间
int sum_num=0;			//总人数
int rand_businesstime=0,rand_waittime=0,now_time=0,total_time=0;
//随机的办理时间 相邻两个客户的到来的时间差 当前时间 总时间
int opentime,closetime;//开张时间 关闭时间
int close=0;           //标记_是否关门
linkqueue queue_[Window];//每个窗口对应一个链队列
void Initqueue(linkqueue &q)//初始化链队
{
    q.front=q.rear=new Node;
    q.front->next=NULL;
    q.front->data.arrivetime=0;
}
void Enqueue(linkqueue &q,elemtype e)//链队的入队
{
    queueptr p;
    p=new Node;
    p->data=e;
    p->next=NULL;
    q.rear->next=p;
    q.rear=p;
    q.front->data.arrivetime++;
}
void Dequeue(linkqueue &q,elemtype &e)//链队的出队
{
    queueptr p;
    if(q.front==q.rear)return;
    p=q.front->next;
    e=p->data;
    q.front->next=p->next;
    if(q.rear==p)q.rear=q.front;
    delete p;
    q.front->data.arrivetime--;
}
int IsEmpty(linkqueue &q)//判断链队是否为空 为空1 反之0
{
    if(q.front==q.rear)
        return 1;
    else return 0;
}
void rand_time()//置2个随机数
{
    srand((unsigned)time(NULL));
    rand_businesstime=rand() % 30 + 1;//客户办理业务时间 1-30 min
    rand_waittime = rand() % 5 + 1;  //任何两个客户到达的时间间隔不超过5分钟，1-5
    now_time +=rand_waittime;
    if(total_time<now_time)
        close=1;
    Sleep(1000);
}
void OpenForDay()//初始化
{
    int i;
    for(i=0;i<Window;i++)
        Initqueue(queue_[i]);
    total_time=(closetime-opentime)*60;
    rand_time();
    elemtype e;
    e.arrivetime=now_time;
    e.waittime=rand_businesstime;
    e.businesstime=rand_businesstime;
    e.leavetime=rand_businesstime+now_time;
    e.starttime=now_time;
    Enqueue(queue_[0],e);
}
int leave_queue(linkqueue &q,int i)
{
    int start=0,leave=0,wait=0,business=0,star,arrive_h=0,arrive_m=0,leave_h=0,leave_m=0,start_h=0,start_m=0;
    elemtype e;
    queueptr p;
    p=q.front->next;
    if(p->data.leavetime <= now_time)
    {
        start=p->data.arrivetime;
        arrive_h=opentime+start/60;
        arrive_m=start%60;

        leave=p->data.leavetime;
        leave_h=opentime+leave/60;
        leave_m=leave%60;

        wait=p->data.waittime;
        business=p->data.businesstime;

        star=p->data.starttime;
        start_h=opentime+star/60;
        start_m=star%60;
        cout << "办理窗口：" << i+1 <<"号\t" << "到达："<< arrive_h << ":" <<arrive_m << "\t离开:" <<leave_h<<":"<<leave_m<< "\t逗留时间:"<<wait << "min" << "\t业务时间:" <<business<<"min\t" << "开始办理:" << start_h<<":"<<start_m<<endl;
        sum_wait_time+=wait;
        if(IsEmpty(q))
        {
            cout << "error" << endl;
            return 0;
        }
        Dequeue(q,e);
        return 1;
    }
    else return 0;
}
void Ifleave_queue()
{
    int i;
    for(i=0;i<Window;i++)
    {
        if(!close)
        {
            if(!IsEmpty(queue_[i]))
            {
                if(leave_queue(queue_[i],i))
                {
                    sum_num++;
                }
            }
        }
    }
}
int Find_freeq()
{
    int i,len,l,t,mini=0;
    len=queue_[0].front->data.arrivetime;
    for(i=0;i<Window;i++)
    {
        l=queue_[i].front->data.arrivetime;
        if(l<len)
        {
            t=len;
            len=l;
            l=t;
            mini=i;
        }
    }
    return mini;
}
void EventDrived()//事件驱动
{
    int Q_freenum=0;
    rand_time();
    Ifleave_queue();//判断队头元素是否办理完业务 若办理完成 出队
    Ifleave_queue();//最差的情况是置随机数间隔1min来一个人 且办理时间也是1min，则需要判断4次，即需要出对4次
    Ifleave_queue();
    Ifleave_queue();
    Q_freenum=Find_freeq();//找到最短的队列（队列人数置于front-〉data.arrivetime中）
    if(!close)//未关门
    {
        elemtype e;
        e.arrivetime=now_time;
        e.businesstime=rand_businesstime;
        if(IsEmpty(queue_[Q_freenum]))//队伍空
        {
            e.leavetime=now_time+rand_businesstime;
            e.waittime=rand_businesstime;
            e.starttime=now_time;
        }
        else//队伍非空
        {
            e.leavetime=queue_[Q_freenum].rear->data.leavetime+rand_businesstime;
            e.waittime=e.leavetime-now_time;
            e.starttime=queue_[Q_freenum].rear->data.leavetime;
        }
        Enqueue(queue_[Q_freenum],e);//客户进入最短的队列
    }
}
void CloseForDay()//下班处理
{
	int i,leave_h,leave_m,t=0;
	for(i=0;i<Window;i++)
	{
		if(!IsEmpty(queue_[i]))
		{
			queueptr p;
			for(p=queue_[i].front->next;p!=NULL;p=p->next)
			{
				if(p->data.starttime<closetime)
				{
					leave_h=opentime+p->data.leavetime/60;
					leave_m=p->data.leavetime%60;
					cout <<"办理窗口："<< i+1 << "号\t" << "状态：正在办理业务\t" <<"还需办理的时间："<< p->data.leavetime - closetime << "min" <<"结束时间：" << leave_h << ":" << leave_m << "\t" << endl;
				}
				else
				{
					t++;
					cout <<"等待窗口："<< i+1 << "号\t" << "状态：等待\t" << "等待次序：" << t << endl;
				}
			}
		}
		t=0;
	}
	cout << "请以上还在等待的客户于明天上班时间在来，由此带来的不便敬请见谅。" << endl;
}
int main()
{

	cout << "*****************************欢迎来到花园银行*****************************" << endl;
	cout << "*****************************现有"<< Window <<"个窗口开放******************************" << endl;
	cout << "*********请依此输入开始时间与结束时间(24小时制营业时间):(如9 17)*********" << endl;
	cin >> opentime >> closetime;
	OpenForDay();
	cout << "************************银行关门前业务完成的客户：************************" << endl;
    while(now_time <= total_time)
    {
        EventDrived();
    }
	cout << "*************************银行关门时间已经到了！！*************************" << endl;
	cout << "******************银行关门时间到还没有办理完业务的客户：******************" << endl;
	CloseForDay();
	cout << endl << "*******今日在营业时间内完成办理客户总人数为"<< sum_num <<"人,总共逗留时间为"<< fixed << setprecision(0) << sum_wait_time <<"min******" <<endl;
	cout << "**************平均逗留时间：" << fixed << setprecision(2)<< sum_wait_time/sum_num << "min****************" << endl;
	return 0;
}
