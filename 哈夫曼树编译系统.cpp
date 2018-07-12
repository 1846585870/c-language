#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 80 //字符数目 max=255

using namespace std;

//data
typedef struct ElemType
{
	char c;//字符
	int num;//频度
}ElemType;
typedef struct
{
	ElemType *elem;
	int length;
}Sqlist;
typedef FILE file;
//data
char str[10];

int InitList(Sqlist &l)
{
	l.elem = new ElemType[MAXSIZE];
	if(!l.elem) exit(0);
	l.length=0;
	return 1;
}
int Generation()
{
	Sqlist l;
	char c;
	int i,j,a;
	InitList(l);
	file *fp,*fc;
	fp=fopen("D:\\ToBeTran.txt","r");
	fc=fopen("D:\\DataFile.txt","w");
	if(fp==NULL)
	{
		cout << "Cannot open this file." << endl;
		return 0;
	}
	c=fgetc(fp);
	while(c!=EOF)//未到文件末尾
	{
		if(c=='\n') {c=fgetc(fp);continue;}
		if(l.length==0)
		{
			l.elem[0].c=c;
			l.elem[0].num=1;
			l.length++;c=fgetc(fp);continue;
		}
		for(i=0;i<l.length;i++)
		{
			if(l.elem[i].c==c)
			{l.elem[i].num++;break;}
			else if(i==l.length-1)
			{l.elem[i+1].c=c;l.elem[i+1].num=1;l.length++;break;}
		}
		c=fgetc(fp);
	}
	for(i=0;i<l.length;i++)
	{
		fputc(l.elem[i].c,fc);
		fputc(' ',fc);
		a=l.elem[i].num;
		for(j=0;a!=0;j++)
		{
			str[j]=a%10+48;
			a/=10;
		}
		j--;
		for(;j>=0;j--)
			fputc(str[j],fc);
		fputc('\n',fc);
	}
	fclose(fp);
	fclose(fc);
	return 1;

}
int main()
{
	int n;
	cout << "-------------------------This is a Huffmancoding System------------------------" << endl << endl;
	cout << "--------------------------------*** Welcome ***--------------------------------" << endl;
	cout << "------------------------------*** Operations: ***------------------------------" << endl;
	cout << "-----------------------------*** 1:Generation ***------------------------------" << endl;
	cout << "---------*** Read the File ToBeTran.data and generate DataFile.data ***--------" << endl << endl;
	cout << "----------------------------*** 2:Initialzation ***----------------------------" << endl;
	cout << "-----------*** Read the File DataFile.data and build Huffman Tree ***----------" << endl << endl;
	cout << "------------------------------*** 3:EnCoding ***-------------------------------" << endl;
	cout << "--------*** Read the File ToBeTran.data and transform into Code.txt ***--------" << endl << endl;
	cout << "------------------------------*** 4:DeCoding ***-------------------------------" << endl;
	cout << "------*** Read the File CodeFile.data and transform into Textfile.txt ***------" << endl << endl;
	cout << "-------------------------------*** 5:Output ***--------------------------------" << endl;
	cout << "-------------*** Output DataFile.data's characters and weight. ***-------------" << endl;
	cout << "--------------------*** Output ToBeTran.data and Code.txt ***------------------" << endl;
	cout << "------------------*** Output CodeFile.data and Textfile.txt ***----------------" << endl << endl;
	cout << "----------------------------*** 0:Leave System ***-----------------------------" << endl;
	cout << "Now is your choice:";
	cin >> n;
	while(n!=0)
	{
		switch(n)
		{
			case 1:Generation();
		}

		cout << "Now is your choice:";
		cin >> n;
	}
}
