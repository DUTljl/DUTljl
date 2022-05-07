#include<iostream>
using namespace std;
int n;
const int N=100010;
int d[N];
int getMax(int d[],int n)//求数组中最大值，从而求得最大指数范围 
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
void CountSort(int d[],int n,int exp)//这里其实为计数排序 
{
	int output[n];
	int i,bucket[10]={0};//数字0~9 
	for(i=0;i<n;i++)
		bucket[(d[i]/exp)%10]++;
	for(i=1;i<10;i++)//让bucket存储的元素值为相应整数最终存储位置 
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
	cout<<"输入n:";
	cin>>n;
	cout<<"输入n个数字:";
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
	RadixSort(d,n);
	printans(d,n);
	return 0;
}
