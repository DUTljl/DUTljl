#include<iostream>
using namespace std;
int n;
const int N=100010;
int d[N];
void BubbleSort(int d[],int n)//�㷨��������Ϊ��һ�����������û�з�����������flag��� 
{
	int i,j,temp;
	int flag;
	for(i=n-1;i>=1;i--)
	{
		flag=0;
		for(j=1;j<=i;j++)
		{
			if(d[j-1]>d[j])
			{
				temp=d[j];
				d[j]=d[j-1];
				d[j-1]=temp;
				flag=1;
			}
		}
		if(flag==0)
			return;
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
	BubbleSort(d,n);
	printans(d,n);
	return 0;
}
