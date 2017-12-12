#include<stdio.h>
struct student
{
  int num;
  char name[20];
  double score[3];
};
double average(struct student *stu)
{
    double a;
    a=1.0/3*(stu->score[0]+stu->score[1]+stu->score[2]);
    return a;
}
int main()
{
    int i;
    struct student stu[10];
    struct student *p=stu;
    for(i=0;i<2;p++,i++)
        scanf("%d %s %lf %lf %lf",&p->num,&p->name,&p->score[0],&p->score[1],&p->score[2]);
    p=stu;
    for(i=0;i<2;p++,i++)
        printf("%-5d %s %.0lf %.0lf %.0lf %.0lf\n",p->num,p->name,p->score[0],p->score[1],p->score[2],average(p));
}
