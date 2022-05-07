#include<iostream>
using namespace std;
int n;
const int N=100010;
int d[N];
int getMax(int d[],int n)//�����������ֵ���Ӷ�������ָ����Χ 
{
	int i,max;
	max=d[0];
	for(i=1;i<n;i++)
	{
		if(d[i]>max)
			max=d[i];
	}
	return max;
}
void CountSort(int d[],int n,int exp)//������ʵΪ�������� 
{
	int output[n];
	int i,bucket[10]={0};//����0~9 
	for(i=0;i<n;i++)
		bucket[(d[i]/exp)%10]++;
	for(i=1;i<10;i++)//��bucket�洢��Ԫ��ֵΪ��Ӧ�������մ洢λ�� 
		bucket[i]+=bucket[i-1];
	for(i=n-1;i>=0;i--)
	{
		output[bucket[(d[i]/exp)%10]-1]=d[i];
		bucket[(d[i]/exp)%10]--;
	}
	for(i=0;i<n;i++)
		d[i]=output[i];
}
void RadixSort(int d[],int n)
{
	int exp;
	int max=getMax(d,n);
	for(exp=1;max/exp>0;exp*=10)
		CountSort(d,n,exp); 
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
	RadixSort(d,n);
	printans(d,n);
	return 0;
}
