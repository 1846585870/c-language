#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <iomanip>
#include <math.h>
#define MAXSIZE 500

using namespace std;

typedef FILE file;
typedef struct ElemType
{
	char w[20];
	int num;
}ElemType;
typedef struct
{
	ElemType *elem;
	int length;
}Sqlist;
typedef struct Node
{
	char w[20];
	int num;
	struct Node *next;
}LNode,*LinkList;
typedef struct BSTNode
{
	ElemType data;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
typedef struct
{
    int key;
    ElemType data;
    int sign;
}HashNode;
typedef struct KeyNum
{
    int key;
    ElemType data;
    struct KeyNum *next;
}KeyNum,*HashLink;

HashNode a[MAXSIZE];
KeyNum b[26];
Sqlist l;
LinkList L;
BSTree T;
char str[20];
char tstr[10];
int TNodenum,sign,p,m=MAXSIZE;

void InitList(Sqlist &l)
{
	l.elem=new ElemType[MAXSIZE];
	if(!l.elem)exit(0);
	l.length=0;
}

void InitLinklist(LinkList &L)
{
	L=new Node;
	L->next=NULL;
	L->num=0;
	L->w[0]='\0';
}
void InsertBST(BSTree &T,ElemType e)
{
	BSTree S;
	if(!T)
	{
		S=new BSTNode;
		S->data=e;
		S->lchild=S->rchild=NULL;
		T=S;
	}
	else if(strcmp(e.w,T->data.w)<0)
		InsertBST(T->lchild,e);
	else if(strcmp(e.w,T->data.w)>0)
		InsertBST(T->rchild,e);
}

void pre_traverse(BSTree &T)
{
    if(T)
    {
        if(strcmp(T->data.w,str)==0)
        {
            T->data.num++;
            sign=1;
            return;
        }
        pre_traverse(T->lchild);
        pre_traverse(T->rchild);
    }
}

void in_traverse_save(BSTree T,char* &output)
{
    if(T)
    {
        char str1[20];
        strcpy(str1,T->data.w);
        in_traverse_save(T->lchild,output);
        sprintf(tstr,"%d",T->data.num);
        strcat(output,strcat(strcat(strcat(str1," "),tstr),"\n"));
        in_traverse_save(T->rchild,output);
    }
    return ;
}
int Print_main()
{
	int a;
	system("CLS");
	cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl << endl ;
	cout << "1.基于线性表的查找" << endl;
	cout << "2.基于二叉排序树的查找" << endl;
	cout << "3.基于哈希表的查找" << endl;
	cout << "4.退出" << endl;
	cout << "请按相应数字键进行选择：";
	cin >> a;return a;
}
int Print_list()
{
	int a;
	system("CLS");
	cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
	cout << "———————————基于线性表的查找———————————" << endl << endl;
	cout << "1.顺序查找"<< endl;
	cout << "2.折半查找" << endl;
	cout << "3.返回上一级" << endl;
	cout << "请按相应数字键进行选择：";
	cin >> a;return a;
}
int Print_BiTree()
{
	int a;
	system("CLS");
	cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
	cout << "——————————基于二叉排序树的查找———————————" << endl << endl;
	cout << "1.二叉排序树查找"<< endl;
	cout << "2.返回上一级" << endl;
	cout << "请按相应数字键进行选择：";
	cin >> a;return a;
}
int Print_HashList()
{
	int a;
	system("CLS");
	cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
	cout << "———————————基于哈希表的查找—————————————" << endl << endl;
	cout << "1.线性探测法查找"<< endl;
	cout << "2.链地址法查找"<< endl;
	cout << "3.返回上一级" << endl;
	cout << "请按相应数字键进行选择：";
	cin >> a;return a;
}
int Print_BiTree_Search()
{
	int a;
	system("CLS");
	cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
	cout << "   —————基于二叉排序树的查找—————  " << endl << endl;
	cout << "1.词频统计"<< endl;
	cout << "2.单词查找" << endl;
	cout << "3.返回上一级" << endl;
	cout << "请按相应数字键进行选择：";
	cin >> a;return a;
}
int Print_Order_Search()
{
	int a;
	system("CLS");
	cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
	cout << "    —————顺序查找—————    " << endl << endl;
	cout << "1.基于顺序表的顺序查找"<< endl;
	cout << "2.基于链表的顺序查找" << endl;
	cout << "3.返回上一级" << endl;
	cout << "请按相应数字键进行选择：";
	cin >> a;return a;
}
int Print_OS_Sqlist()
{
	int a;
	system("CLS");
	cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
	cout << "   —————基于顺序表的顺序查找—————  " << endl << endl;
	cout << "1.词频统计"<< endl;
	cout << "2.单词查找" << endl;
	cout << "3.返回上一级" << endl;
	cout << "请按相应数字键进行选择：";
	cin >> a;return a;
}
int Print_OS_linklist()
{
	int a;
	system("CLS");
	cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
	cout << "   —————基于链表的顺序查找—————   " << endl << endl;
	cout << "1.词频统计"<< endl;
	cout << "2.单词查找" << endl;
	cout << "3.返回上一级" << endl;
	cout << "请按相应数字键进行选择：";
	cin >> a;return a;
}
int Print_HF_Search()
{
	int a;
	system("CLS");
	cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
	cout << "    —————折半查找—————    " << endl << endl;
	cout << "1.基于顺序表的折半查找单词"<< endl;
	cout << "2.返回上一级" << endl;
	cout << "请按相应数字键进行选择：";
	cin >> a;return a;
}
int Print_HS1()
{
    	int a;
	system("CLS");
	cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
	cout << "   —————基于哈希表线性探测法的查找—————   " << endl << endl;
	cout << "1.词频统计"<< endl;
	cout << "2.单词查找" << endl;
	cout << "3.返回上一级" << endl;
	cout << "请按相应数字键进行选择：";
	cin >> a;return a;
}
int Print_HS2()
{
    	int a;
	system("CLS");
	cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
	cout << "   —————基于哈希表链地址法的查找—————   " << endl << endl;
	cout << "1.词频统计"<< endl;
	cout << "2.单词查找" << endl;
	cout << "3.返回上一级" << endl;
	cout << "请按相应数字键进行选择：";
	cin >> a;return a;
}
int If_letter(char &c)
{
	if(c>='A'&&c<='Z')
	{
		c=c+32;
		return 1;
	}
	else if(c>='a'&&c<='z')
		return 1;
	else return 0;
}
void Sort_L(Sqlist &l)
{
	char temp[20];
	int i,j,t;
	for(i=0;i<l.length-1;i++)
		for(j=i+1;j<l.length;j++)
			if(strcmp(l.elem[j].w,l.elem[i].w)<0)
			{
				strcpy(temp,l.elem[i].w);
				strcpy(l.elem[i].w,l.elem[j].w);
				strcpy(l.elem[j].w,temp);
				t=l.elem[j].num;
				l.elem[j].num=l.elem[i].num;
				l.elem[i].num=t;
			}
}
int Sqlist_word_statistics(int k)//词频统计
{
	int i,j;
	file *fp,*fc;char c;
	InitList(l);
	fp=fopen("D:\\InFile.txt","r+");
	if(k==1)
		fc=fopen("D:\\OutFile1.txt","w");
	else if(k==2)
		fc=fopen("D:\\OutFile3.txt","w");
	if(fp==NULL) return 0;
	if(fc==NULL) return 0;
	c=fgetc(fp);
	while(c!=EOF)
	{
		if(If_letter(c)==1)
		{
			str[0]=c;
			c=fgetc(fp);
			for(i=1;If_letter(c)==1;i++)
			{str[i]=c;c=fgetc(fp);}
			str[i]='\0';
			if(l.length==0)
			{
				strcpy(l.elem[0].w,str);
				l.elem[0].num=1;l.length++;c=fgetc(fp);continue;
			}
			for(j=0;j<l.length;j++)
			{
				if(strcmp(l.elem[j].w,str)==0)
				{l.elem[j].num++;break;}
				else if(j==l.length-1)
				{strcpy(l.elem[j+1].w,str);l.elem[j+1].num=1;l.length++;break;}
			}
			c=fgetc(fp);
		}
		else c=fgetc(fp);
	}
	Sort_L(l);
	sprintf(tstr,"%d",l.length);
	fputs(tstr,fc);
	fputc('\n',fc);
	for(j=0;j<l.length;j++)
	{
		fputs(l.elem[j].w,fc);
		fputc(' ',fc);
		sprintf(tstr,"%d",l.elem[j].num);
    fputs(tstr,fc);
		fputc('\n',fc);
	}
	fclose(fp);
	fclose(fc);
	return 1;
}
void Sqlist_word_find()//单词查找
{
	int i;
	LARGE_INTEGER timeStart;	//开始时间
	LARGE_INTEGER timeEnd;		//结束时间
	LARGE_INTEGER frequency;	//计时器频率
	QueryPerformanceFrequency(&frequency);
	double quadpart = (double)frequency.QuadPart;
	QueryPerformanceCounter(&timeStart);

	for(i=0;i<l.length;i++)
		if(strcmp(l.elem[i].w,str)==0)
			break;

	QueryPerformanceCounter(&timeEnd);
	double elapsed = (timeEnd.QuadPart - timeStart.QuadPart) / quadpart;
	if(i==l.length) cout<< "查找失败" << endl;
	else
	{
		cout << "此单词的词频为：" << l.elem[i].num << endl << "查找该单词所花的时间为：" <<fixed<<setprecision(0)<<elapsed*10e6<< "μs" << endl << "平均查找长度:" << fixed << setprecision(1) << (l.length+1)/2.0 << endl;
	}
}
void Sqlist_word_Search_Bin()
{
	int low,high,mid;
	low=0;high=l.length-1;
	LARGE_INTEGER timeStart;	//开始时间
	LARGE_INTEGER timeEnd;		//结束时间
	LARGE_INTEGER frequency;	//计时器频率
	QueryPerformanceFrequency(&frequency);
	double quadpart = (double)frequency.QuadPart;
	QueryPerformanceCounter(&timeStart);

	while(low<=high)
	{
		mid=(low+high)/2;
		if(strcmp(str,l.elem[mid].w)==0)
			break;
		else if(strcmp(str,l.elem[mid].w)<0)
			high=mid-1;
		else low=mid+1;
	}

	QueryPerformanceCounter(&timeEnd);
	double elapsed = (timeEnd.QuadPart - timeStart.QuadPart) / quadpart;
	if(low>high) cout<< "查找失败" << endl;
	else
	{
		cout << "此单词的词频为：" << l.elem[mid].num << endl << "查找该单词所花的时间为：" <<fixed<<setprecision(0)<<elapsed*10e6<< "μs" << endl << "平均查找长度:" << fixed << setprecision(1) <<((l.length+1)/(double)l.length)*log((double)l.length+1)/log((double)2)-1  << endl;
	}
}
BSTree SearchBST(BSTree T,ElemType e)
{
	if((!T)||strcmp(e.w,T->data.w)==0) return T;
	else if(strcmp(e.w,T->data.w)<0) return SearchBST(T->lchild,e);
	else return SearchBST(T->rchild,e);
}
double asl;
void BSTree_ASL(BSTree T,int k)
{
	if(k==0)
		asl=0;
	k++;
	if(T)
	{
		asl+=k;
		BSTree_ASL(T->lchild,k);
		BSTree_ASL(T->rchild,k);
	}
	else
	{
		return;
	}

}
int BSTree_word_statistics()
{
    int i;
    file *fp = NULL,*fc;char c,*output;
    output=new char[500];
    T=NULL;
    *output='\0';
    ElemType e;
    fp=fopen("D:\\InFile.txt","r+");
    fc=fopen("D:\\OutFile4.txt","w");
    if(fp==NULL) return 0;
	if(fc==NULL) return 0;
	TNodenum=0;
	c=fgetc(fp);
	while(c!=EOF)
    {
        if(If_letter(c)==1)
        {
            str[0]=c;
			c=fgetc(fp);
			for(i=1;If_letter(c)==1;i++)
			{str[i]=c;c=fgetc(fp);}
			str[i]='\0';
			sign=0;
			pre_traverse(T);
			if(sign==1)
            {
                c=fgetc(fp);continue;
            }
            else
            {
                e.num=1;strcpy(e.w,str);
                InsertBST(T,e);TNodenum++;
                c=fgetc(fp);continue;
            }
        }
        else
        {
            c=fgetc(fp);continue;
        }
    }
    sprintf(tstr,"%d",TNodenum);
	fputs(tstr,fc);
	fputc('\n',fc);
    in_traverse_save(T,output);
    fputs(output,fc);
	fclose(fp);
	fclose(fc);
	delete output;
	return 1;
}
void BSTree_word_find()
{
	BSTree p;ElemType e;
	LARGE_INTEGER timeStart;	//开始时间
	LARGE_INTEGER timeEnd;		//结束时间
	LARGE_INTEGER frequency;	//计时器频率
	QueryPerformanceFrequency(&frequency);
	double quadpart = (double)frequency.QuadPart;
	QueryPerformanceCounter(&timeStart);
	strcpy(e.w,str);
	p=SearchBST(T,e);
	QueryPerformanceCounter(&timeEnd);
	double elapsed = (timeEnd.QuadPart - timeStart.QuadPart) / quadpart;
	if(p==NULL)
		cout<< "查找失败" << endl;
	else
	{
		BSTree_ASL(T,0);
		cout << "此单词的词频为：" << p->data.num << endl << "查找该单词所花的时间为：" <<fixed<<setprecision(0)<<elapsed*10e6<< "μs" << endl << "平均查找长度:" << fixed << setprecision(1) << asl/TNodenum << endl;
	}
}

int Linklist_word_statistics()
{
	int i,a,b;
	LinkList p,q;
	file *fp,*fc;char c;
	InitLinklist(L);
	fp=fopen("D:\\InFile.txt","r+");
	fc=fopen("D:\\OutFile2.txt","w");
	if(fp==NULL) return 0;
	if(fc==NULL) return 0;
	c=fgetc(fp);
	while(c!=EOF)
	{
		if(If_letter(c)==1)
		{
			str[0]=c;
			c=fgetc(fp);
			for(i=1;If_letter(c)==1;i++)
			{str[i]=c;c=fgetc(fp);}
			str[i]='\0';
			//单词字符存入str
			p=L;
			if(p->next==NULL)
            {
                q=new LNode;strcpy(q->w,str);q->num=1;q->next=NULL;p->next=q;L->num++;
                c=fgetc(fp);continue;
            }
            else if(p->next->next==NULL)
            {
                a=strcmp(p->next->w,str);
                if(a>0)
                {
                    q=new LNode;strcpy(q->w,str);q->num=1;q->next=p->next;p->next=q;L->num++;
                    c=fgetc(fp);continue;
                }
                else if(a==0)
                {
                     p->next->num++;
                     c=fgetc(fp);continue;
                }
                else
                {
                    p=p->next;
                    q=new LNode;strcpy(q->w,str);q->num=1;q->next=NULL;p->next=q;L->num++;
                    c=fgetc(fp);continue;
                }
            }
            else
            {
                for(p=L;p->next!=NULL;p=p->next)
                {
                    a=strcmp(p->w,str);b=strcmp(p->next->w,str);
                    if(a==0) {p->num++;break;}
                    else if(b==0) {p->next->num++;break;}
                    else if(a<0 && b>0)
                    {
                        q=new LNode;strcpy(q->w,str);q->num=1;q->next=p->next;p->next=q;L->num++;break;
                    }
                    else continue;
                }
                if(p->next==NULL)
                {
                    q=new LNode;strcpy(q->w,str);q->num=1;q->next=NULL;p->next=q;L->num++;
                }
                c=fgetc(fp);continue;
            }
		}
		else c=fgetc(fp);
	}
	sprintf(tstr,"%d",L->num);fputs(tstr,fc);fputc('\n',fc);
	for(p=L->next;p!=NULL;p=p->next)
	{
		fputs(p->w,fc);
		fputc(' ',fc);
		sprintf(tstr,"%d",p->num);
		fputs(tstr,fc);
		fputc('\n',fc);
	}
	fclose(fp);
	fclose(fc);
	return 1;
}
void Linklist_word_find()
{
	int i=0;
	LinkList p;
	LARGE_INTEGER timeStart;	//开始时间
	LARGE_INTEGER timeEnd;		//结束时间
	LARGE_INTEGER frequency;	//计时器频率
	QueryPerformanceFrequency(&frequency);
	double quadpart = (double)frequency.QuadPart;
	QueryPerformanceCounter(&timeStart);

	for(p=L->next;p!=NULL;p=p->next)
		if(strcmp(p->w,str)==0)
		{i++;break;}

	QueryPerformanceCounter(&timeEnd);
	double elapsed = (timeEnd.QuadPart - timeStart.QuadPart) / quadpart;
	if(i==L->num) cout<< "查找失败" << endl;
	else
		cout << "此单词的词频为：" << p->num << endl << "查找该单词所花的时间为：" <<fixed<<setprecision(0)<<elapsed*10e6<< "μs" << endl << "平均查找长度:" << fixed << setprecision(1) << (L->num+1)/2.0 << endl;


}
void Initialization()
{
    int i,j;
    for(i=MAXSIZE;i>1;i--)
    {
        for(j=2;j<i;j++)
            if(i%j==0) break;
        if(j==i) break;
    }
    p=i;
    for(i=0;i<MAXSIZE;i++)
    {
        a[i].key=i;
        a[i].sign=0;
    }
}
int H(char key[])
{
    int i,sum=0;
    for(i=0;i<strlen(key);i++)
    {
        sum+=key[i]-71;
    }
    return sum%p;
}
int Hash(char key[],int di)
{
    return (H(key)+di)%m;
}
int Hash_(char key[])
{
    return key[0]-97;
}
void InsertHashNode(HashLink &p)
{
    HashLink q;
    q=new KeyNum;
    q->next=NULL;
    strcpy(q->data.w,str);
    q->data.num=1;
    p->next=q;
}
int Hash1_word_statistics()
{
    Initialization();
    int i,t,count=0;
    file *fp,*fc;char c;
    fp=fopen("D:\\InFile.txt","r+");
	fc=fopen("D:\\OutFile5.txt","w");
	if(fp==NULL) return 0;
	if(fc==NULL) return 0;
	c=fgetc(fp);
	while(c!=EOF)
    {
        if(If_letter(c)==1)
		{
		    asl=1;
			str[0]=c;
			c=fgetc(fp);
			for(i=1;If_letter(c)==1;i++)
			{str[i]=c;c=fgetc(fp);}
			str[i]='\0';
			t=Hash(str,0);
			if(a[t].sign==0)
            {
                strcpy(a[t].data.w,str);
                a[t].data.num=1;
                a[t].sign=1;
                count++;
                c=fgetc(fp);continue;
            }
            else if(strcmp(a[t].data.w,str)==0)
            {
                a[t].data.num++;
                c=fgetc(fp);continue;
            }
            else
            {
                for(i=1;i<=m-1;i++)
                {
                    t=Hash(str,i);
                    asl++;
                    if(a[t].sign==0)
                    {
                        strcpy(a[t].data.w,str);
                        a[t].data.num=1;
                        a[t].sign=asl;
                        count++;
                        break;
                    }
                    else if(strcmp(a[t].data.w,str)==0)
                    {
                        a[t].data.num++;
                        break;
                    }
                    else continue;
                }
                c=fgetc(fp);continue;
            }
		}
		else {c=fgetc(fp);continue;}
    }
    fprintf(fc,"%d",count);
    fputc('\n',fc);
    asl=0;
    for(i=0;i<MAXSIZE;i++)
   {
       if(a[i].sign!=0)
        {
            asl+=a[i].sign;
            fprintf(fc,"%s %d",a[i].data.w,a[i].data.num);
            fputc('\n',fc);
        }
   }
   asl/=count;
   fclose(fp);
   fclose(fc);
   return 1;
}
void Hash1_word_find()
{
    int n;double elapsed;
    LARGE_INTEGER timeStart;	//开始时间
	LARGE_INTEGER timeEnd;		//结束时间
	LARGE_INTEGER frequency;	//计时器频率
	QueryPerformanceFrequency(&frequency);
	double quadpart = (double)frequency.QuadPart;
	QueryPerformanceCounter(&timeStart);
	n=Hash(str,0);
	if(a[n].sign==0)
        cout<< "查找失败" << endl;
    else if(strcmp(a[n].data.w,str)==0)
    {
            QueryPerformanceCounter(&timeEnd);
            elapsed = (timeEnd.QuadPart - timeStart.QuadPart) / quadpart;
            cout << "此单词的词频为：" << a[n].data.num << endl << "查找该单词所花的时间为：" <<fixed<<setprecision(0)<<elapsed*10e6<< "μs" << endl << "平均查找长度:" << fixed << setprecision(1) << asl<< endl;
    }
    else
    {
        for(int i=1;i<=m-1;i++)
        {
            n=Hash(str,i);
            if(a[n].sign==0)
                {cout<< "查找失败" << endl;break;}
            else if(strcmp(a[n].data.w,str)==0)
                    {
                        QueryPerformanceCounter(&timeEnd);
                        elapsed = (timeEnd.QuadPart - timeStart.QuadPart) / quadpart;
                        cout << "此单词的词频为：" << a[n].data.num << endl << "查找该单词所花的时间为：" <<fixed<<setprecision(0)<<elapsed*10e6<< "μs" << endl << "平均查找长度:" << fixed << setprecision(1) << asl << endl;
                        break;
                    }
                    else continue;
        }
    }
}
int Hash2_word_statistics()
{
    int i,t,count=0;
    file *fp,*fc;char c;HashLink p,pre,q;
    for(i=0;i<26;i++)
    {
        b[i].key=i;b[i].data.num=0;b[i].next=NULL;
    }
    fp=fopen("D:\\InFile.txt","r+");
	fc=fopen("D:\\OutFile6.txt","w");
	if(fp==NULL) return 0;
	if(fc==NULL) return 0;
	c=fgetc(fp);
	while(c!=EOF)
    {
        if(If_letter(c)==1)
        {
            str[0]=c;
			c=fgetc(fp);
			for(i=1;If_letter(c)==1;i++)
			{str[i]=c;c=fgetc(fp);}
			str[i]='\0';
			t=Hash_(str);
			p=&b[t];
			if(p->next==NULL)
            {
                InsertHashNode(p);
                b[i].data.num++;count++;
                c=fgetc(fp);continue;
            }
            else
            {
                for(p=b[t].next;p!=NULL;p=p->next)
                {
                    if(strcmp(str,p->data.w)==0)
                    {
                        p->data.num++;break;
                    }
                    pre=p;
                }
                if(p==NULL)
                {
                    InsertHashNode(pre);b[i].data.num++;count++;
                }
                c=fgetc(fp);continue;
            }
        }
        else {c=fgetc(fp);continue;}
    }
    fprintf(fc,"%d",count);
    fputc('\n',fc);
    asl=0;
    for(i=0;i<26;i++)
    {
        if(b[i].next==NULL) continue;
        else
        {
            asl+=(b[i].data.num+1)*b[i].data.num/2.0;
            for(p=b[i].next;p!=NULL;p=p->next)
            {
                fprintf(fc,"%s %d",p->data.w,p->data.num);
                fputc('\n',fc);
            }
        }
    }
    asl/=count;
    fclose(fp);
    fclose(fc);
    return 1;
}
void Hash2_word_find()
{
     int n;double elapsed;HashLink p;
    LARGE_INTEGER timeStart;	//开始时间
	LARGE_INTEGER timeEnd;		//结束时间
	LARGE_INTEGER frequency;	//计时器频率
	QueryPerformanceFrequency(&frequency);
	double quadpart = (double)frequency.QuadPart;
	QueryPerformanceCounter(&timeStart);
	n=Hash_(str);
	if(b[n].next==NULL)
        cout<< "查找失败" << endl;
    else
    {
        for(p=b[n].next;p!=NULL;p=p->next)
        {
            if(strcmp(p->data.w,str)==0)
            {
                QueryPerformanceCounter(&timeEnd);
                elapsed = (timeEnd.QuadPart - timeStart.QuadPart) / quadpart;
                cout << "此单词的词频为：" << p->data.num << endl << "查找该单词所花的时间为：" <<fixed<<setprecision(0)<<elapsed*10e6<< "μs" << endl << "平均查找长度:" << fixed << setprecision(1) << asl<< endl;
                break;
            }
        }
        if(p==NULL)
            cout<< "查找失败" << endl;
    }
}
void Menu_1112()
{
	void Menu_1();
	void Menu_111();
	switch(Print_OS_linklist())
	{
		case 1:Linklist_word_statistics();system("CLS");
			cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
			cout << "    —————词频统计—————    " << endl << endl;
			cout<<"已经生成文件到OutFile2.txt"<<endl;system("Pause");Menu_1();break;
		case 2:Linklist_word_statistics();
			system("CLS");
			cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
			cout << "    —————单词查找—————    " << endl << endl;
			cout<<"请输入待查找的单词：";
			cin >> str;
			Linklist_word_find();
			system("Pause");Menu_1();
			break;
		case 3:Menu_111();break;
	}
}

void Menu_1111()
{
	int detail;
	void Menu_1();
	void Menu_111();
	switch(Print_OS_Sqlist())
	{
		case 1:detail=Sqlist_word_statistics(1);system("CLS");
			cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
			cout << "    —————词频统计—————    " << endl << endl;
			if(detail)
			{cout<<"已经生成文件到OutFile1.txt"<<endl;system("Pause");Menu_1();break;}
			else {cout <<"error:无法读入文件或者未有权限创建文件"<<endl;system("Pause");Menu_1();break;}
		case 2:
			Sqlist_word_statistics(1);
			system("CLS");
			cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
			cout << "    —————单词查找—————    " << endl << endl;
			cout<<"请输入待查找的单词：";
			cin >> str;
			Sqlist_word_find();
			system("Pause");Menu_1();
			break;
		case 3:Menu_111();break;
	}
}
void Menu_1121()
{
	int detail;
	void Menu_1();
	void Menu_112();
	switch(Print_OS_Sqlist())
	{
		case 1:detail=Sqlist_word_statistics(2);system("CLS");
			cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
			cout << "    —————词频统计—————    " << endl << endl;
			if(detail)
			{cout<<"已经生成文件到OutFile3.txt"<<endl;system("Pause");Menu_1();break;}
			else {cout <<"error:无法读入文件或者未有权限创建文件"<<endl;system("Pause");Menu_1();break;}
		case 2:
			Sqlist_word_statistics(2);
			system("CLS");
			cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
			cout << "    —————单词查找—————    " << endl << endl;
			cout<<"请输入待查找的单词：";
			cin >> str;
			Sqlist_word_Search_Bin();
			system("Pause");Menu_1();
			break;
		case 3:Menu_112();break;
	}
}

void Menu_111()
{
	void Menu_11();
	switch(Print_Order_Search())
	{
		case 1:Menu_1111();break;
		case 2:Menu_1112();break;
		case 3:Menu_11();break;
	}
}
void Menu_112()
{
	void Menu_11();
	void Menu_1();
	switch(Print_HF_Search())
	{
		case 1:Menu_1121();break;
		case 2:Menu_11();break;
	}
}
void Menu_121()
{
	int detail;
	void Menu_12();
	void Menu_1();
	switch(Print_BiTree_Search())
	{
		case 1:detail=BSTree_word_statistics();system("CLS");
			cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
			cout << "    —————词频统计—————    " << endl << endl;
			if(detail)
			{cout<<"已经生成文件到OutFile4.txt"<<endl;system("Pause");Menu_1();break;}
			else {cout <<"error:无法读入文件或者未有权限创建文件"<<endl;system("Pause");Menu_1();break;}
		case 2:
			BSTree_word_statistics();system("CLS");
			cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
			cout << "    —————单词查找—————    " << endl << endl;
			cout<<"请输入待查找的单词：";
			cin >> str;
			BSTree_word_find();
			system("Pause");Menu_1();
			break;
		case 3:Menu_12();break;
	}
}
void Menu_131()
{
    int detail;
    void Menu_1();
    void Menu_13();
    switch(Print_HS1())
    {
        case 1:detail=Hash1_word_statistics();system("CLS");
			cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
			cout << "    —————词频统计—————    " << endl << endl;
			if(detail)
			{cout<<"已经生成文件到OutFile5.txt"<<endl;system("Pause");Menu_1();break;}
			else {cout <<"error:无法读入文件或者未有权限创建文件"<<endl;system("Pause");Menu_1();break;}
        case 2:Hash1_word_statistics();system("CLS");
			cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
			cout << "    —————单词查找—————    " << endl << endl;
			cout<<"请输入待查找的单词：";
			cin >> str;
			Hash1_word_find();
			system("Pause");Menu_1();
			break;
        case 3:Menu_13();break;
    }
}
void Menu_132()
{
    int detail;
    void Menu_1();
    void Menu_13();
    switch(Print_HS2())
    {
        case 1:detail=Hash2_word_statistics();;system("CLS");
			cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
			cout << "    —————词频统计—————    " << endl << endl;
			if(detail)
			{cout<<"已经生成文件到OutFile6.txt"<<endl;system("Pause");Menu_1();break;}
			else {cout <<"error:无法读入文件或者未有权限创建文件"<<endl;system("Pause");Menu_1();break;}
        case 2:Hash2_word_statistics();system("CLS");
			cout << "  /****基于不同策略的单词统计和检索系统****/  " << endl;
			cout << "    —————单词查找—————    " << endl << endl;
			cout<<"请输入待查找的单词：";
			cin >> str;
			Hash2_word_find();
			system("Pause");Menu_1();
			break;
        case 3:Menu_13();break;
    }
}
void Menu_11()
{
	void Menu_1();
	switch(Print_list())
	{
		case 1:Menu_111();break;
		case 2:Menu_112();break;
		case 3:Menu_1();break;
	}
}
void Menu_12()
{
	void Menu_1();
	switch(Print_BiTree())
	{
		case 1:Menu_121();break;
		case 2:Menu_1();break;
		default:break;
	}
}
void Menu_13()
{
    void Menu_1();
    switch(Print_HashList())
    {
        case 1:Menu_131();break;
        case 2:Menu_132();break;
        case 3:Menu_1();break;
        default:break;
    }
}
void Menu_1()
{
	switch(Print_main())
	{
		case 1:Menu_11();break;
		case 2:Menu_12();break;
		case 3:Menu_13();break;
		case 4:return;
	}
}

int main()
{
	Menu_1();
	system("Pause");
	return 0;
}
