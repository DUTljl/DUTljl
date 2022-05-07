#include<iostream>
#include<cstring>
using namespace std;
int n;
const int N=100010;
int d[N];
void BucketSort(int d[],int n,int max)
{
	int i,j;
	int bucket[max];
	memset(bucket,0,max*sizeof(int));
	for(i=0;i<n;i++)
		bucket[d[i]]++;
	for(i=0,j=0;i<max;i++)
	{
		while((bucket[i]--)>0)
			d[j++]=i;
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
	int max;
	cout<<"输入n:";
	cin>>n;
	cout<<"输入数据的最大范围：";
	cin>>max;
	cout<<"输入n个数字:";
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
	BucketSort(d,n,max);
	printans(d,n);
	return 0;
}
