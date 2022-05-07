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
	int count[x+1];//统计数组
	memset(count,0,(x+1)*sizeof(int));
	for(i=0;i<n;i++)
	{
		count[d[i]-min]++;
	}
	for(i=1;i<x+1;i++)//让统计数组存储的元素值等于相应整数在ans中的最终排序位置 
	{
		count[i]+=count[i-1];
	}
	int ans[n];
	for(i=n-1;i>=0;i--)//count[d[i]-min]表示位于ans第几位,-1则因为ans下标从0开始 
	{
		ans[count[d[i]-min]-1]=d[i];//找到d中的当前元素在结果数组中排第几位
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
	cout<<"输入n:";
	cin>>n;
	cout<<"输入n个数字:";
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
	CountSort(d,n);
	printans(d,n);
	return 0;
}
