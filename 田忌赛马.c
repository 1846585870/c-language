#include<stdio.h>
int main()
{
    int n,i,j,k,num=-1,win,result[200];
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        int a[n],b[n];
        //��������
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        scanf("%d",&b[i]);
        //����
        //����ʼ ��С����
        for(i=0;i<n-1;i++)
            for(j=0;j<n-1-i;j++)
            if(a[j]>a[j+1])
            {
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
            }
        for(i=0;i<n-1;i++)
            for(j=0;j<n-1-i;j++)
            if(b[j]>b[j+1])
            {
                k=b[j];
                b[j+1]=b[j];
                b[j]=k;
            }

        //�������
        //������ʼ
        win=0;
        int afirst=0,bfirst=0,alast=n-1,blast=n-1;
        for(i=0;i<n;i++)
        {
            if(a[afirst]>b[bfirst])
            {
                afirst++;
                bfirst++;
                win++;
            }
            else if(a[afirst]<b[bfirst])//��ҲҪ����һ����õ�
            {
                afirst++;
                blast--;
            }
            else
            {
                if(a[alast]>b[blast])
                {
                    alast--;
                    blast--;
                    win++;
                }
                else if(a[alast]<b[blast])
                    {
                        afirst++;
                        blast--;
                    }
                    else
                    {
                        afirst++;
                        blast--;
                    }
            }
        }
        //��������
        num++;
        //ͳ�ƽ��
        if((double)win>(double)n/2.0)
        result[num]=1;//yes
        else result[num]=2;//no
        //ͳ�ƽ���
    }

    //���
    for(i=0;i<=num;i++)
    {
        if(result[i]==1)
        printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
