#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N=100010;
int d[N];
void CountSort(int d[],int n)
{
	int max=d[0],min=d[0];
	int i;
	for(i=1;i<n;i++)
	{
		if(d[i]>max)
			max=d[i];
		if(d[i]<min)
			min=d[i];
	}
	int x=max-min;
	int count[x+1];//ͳ������
	memset(count,0,(x+1)*sizeof(int));
	for(i=0;i<n;i++)
	{
		count[d[i]-min]++;
	}
	for(i=1;i<x+1;i++)//��ͳ������洢��Ԫ��ֵ������Ӧ������ans�е���������λ�� 
	{
		count[i]+=count[i-1];
	}
	int ans[n];
	for(i=n-1;i>=0;i--)//count[d[i]-min]��ʾλ��ans�ڼ�λ,-1����Ϊans�±��0��ʼ 
	{
		ans[count[d[i]-min]-1]=d[i];//�ҵ�d�еĵ�ǰԪ���ڽ���������ŵڼ�λ
		count[d[i]-min]--;//
	}
	for(i=0;i<n;i++)
	{
		d[i]=ans[i];
	}
}
void printans(int d[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",d[i]);
	}
}
int main()
{
	cout<<"����n:";
	cin>>n;
	cout<<"����n������:";
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
	CountSort(d,n);
	printans(d,n);
	return 0;
}
