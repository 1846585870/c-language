#include<iostream>
#include<iomanip>
#include<windows.h>
#include<time.h>
#define Window 4 //���Ը�����Ҫ�޸Ĵ�����Ŀ

using namespace std;

typedef struct elemtype
{
    int arrivetime;//����ʱ��
    int waittime;  //����ʱ�䣨�����ȴ�ʱ��Ͱ���ҵ��ʱ�䣩
    int leavetime; //�뿪ʱ��
    int starttime; //��ʼ����ҵ���ʱ���
    int businesstime;//����ҵ������Ҫ��ʱ��
}elemtype;
typedef struct Node
{
    elemtype data;//������
    struct Node *next;//ָ����
}Node,*queueptr;
typedef struct
{
    queueptr front;
    queueptr rear;
}linkqueue;

float sum_wait_time=0.0;//�ܹ��Ķ���ʱ��
int sum_num=0;			//������
int rand_businesstime=0,rand_waittime=0,now_time=0,total_time=0;
//����İ���ʱ�� ���������ͻ��ĵ�����ʱ��� ��ǰʱ�� ��ʱ��
int opentime,closetime;//����ʱ�� �ر�ʱ��
int close=0;           //���_�Ƿ����
linkqueue queue_[Window];//ÿ�����ڶ�Ӧһ��������
void Initqueue(linkqueue &q)//��ʼ������
{
    q.front=q.rear=new Node;
    q.front->next=NULL;
    q.front->data.arrivetime=0;
}
void Enqueue(linkqueue &q,elemtype e)//���ӵ����
{
    queueptr p;
    p=new Node;
    p->data=e;
    p->next=NULL;
    q.rear->next=p;
    q.rear=p;
    q.front->data.arrivetime++;
}
void Dequeue(linkqueue &q,elemtype &e)//���ӵĳ���
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
int IsEmpty(linkqueue &q)//�ж������Ƿ�Ϊ�� Ϊ��1 ��֮0
{
    if(q.front==q.rear)
        return 1;
    else return 0;
}
void rand_time()//��2�������
{
    srand((unsigned)time(NULL));
    rand_businesstime=rand() % 30 + 1;//�ͻ�����ҵ��ʱ�� 1-30 min
    rand_waittime = rand() % 5 + 1;  //�κ������ͻ������ʱ����������5���ӣ�1-5
    now_time +=rand_waittime;
    if(total_time<now_time)
        close=1;
    Sleep(1000);
}
void OpenForDay()//��ʼ��
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
        cout << "�����ڣ�" << i+1 <<"��\t" << "���"<< arrive_h << ":" <<arrive_m << "\t�뿪:" <<leave_h<<":"<<leave_m<< "\t����ʱ��:"<<wait << "min" << "\tҵ��ʱ��:" <<business<<"min\t" << "��ʼ����:" << start_h<<":"<<start_m<<endl;
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
void EventDrived()//�¼�����
{
    int Q_freenum=0;
    rand_time();
    Ifleave_queue();//�ж϶�ͷԪ���Ƿ������ҵ�� ��������� ����
    Ifleave_queue();//�������������������1min��һ���� �Ұ���ʱ��Ҳ��1min������Ҫ�ж�4�Σ�����Ҫ����4��
    Ifleave_queue();
    Ifleave_queue();
    Q_freenum=Find_freeq();//�ҵ���̵Ķ��У�������������front-��data.arrivetime�У�
    if(!close)//δ����
    {
        elemtype e;
        e.arrivetime=now_time;
        e.businesstime=rand_businesstime;
        if(IsEmpty(queue_[Q_freenum]))//�����
        {
            e.leavetime=now_time+rand_businesstime;
            e.waittime=rand_businesstime;
            e.starttime=now_time;
        }
        else//����ǿ�
        {
            e.leavetime=queue_[Q_freenum].rear->data.leavetime+rand_businesstime;
            e.waittime=e.leavetime-now_time;
            e.starttime=queue_[Q_freenum].rear->data.leavetime;
        }
        Enqueue(queue_[Q_freenum],e);//�ͻ�������̵Ķ���
    }
}
void CloseForDay()//�°ദ��
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
					cout <<"�����ڣ�"<< i+1 << "��\t" << "״̬�����ڰ���ҵ��\t" <<"��������ʱ�䣺"<< p->data.leavetime - closetime << "min" <<"����ʱ�䣺" << leave_h << ":" << leave_m << "\t" << endl;
				}
				else
				{
					t++;
					cout <<"�ȴ����ڣ�"<< i+1 << "��\t" << "״̬���ȴ�\t" << "�ȴ�����" << t << endl;
				}
			}
		}
		t=0;
	}
	cout << "�����ϻ��ڵȴ��Ŀͻ��������ϰ�ʱ���������ɴ˴����Ĳ��㾴����¡�" << endl;
}
int main()
{

	cout << "*****************************��ӭ������԰����*****************************" << endl;
	cout << "*****************************����"<< Window <<"�����ڿ���******************************" << endl;
	cout << "*********���������뿪ʼʱ�������ʱ��(24Сʱ��Ӫҵʱ��):(��9 17)*********" << endl;
	cin >> opentime >> closetime;
	OpenForDay();
	cout << "************************���й���ǰҵ����ɵĿͻ���************************" << endl;
    while(now_time <= total_time)
    {
        EventDrived();
    }
	cout << "*************************���й���ʱ���Ѿ����ˣ���*************************" << endl;
	cout << "******************���й���ʱ�䵽��û�а�����ҵ��Ŀͻ���******************" << endl;
	CloseForDay();
	cout << endl << "*******������Ӫҵʱ������ɰ���ͻ�������Ϊ"<< sum_num <<"��,�ܹ�����ʱ��Ϊ"<< fixed << setprecision(0) << sum_wait_time <<"min******" <<endl;
	cout << "**************ƽ������ʱ�䣺" << fixed << setprecision(2)<< sum_wait_time/sum_num << "min****************" << endl;
	return 0;
}
