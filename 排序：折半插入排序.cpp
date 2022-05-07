#include<iostream>
using namespace std;
int n;
const int N=100010;
int d[N];
void BinaryInsertSort(int d[],int n)
{
	for(int i=1;i<n;i++)
	{
		int t=d[i];
		int l=0,r=i-1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(t<d[mid])
				r=mid-1;
			else l=mid+1;
		}
		for(int j=i-1;j>=l;j--)
			d[j+1]=d[j];
		d[l]=t;
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
	BinaryInsertSort(d,n);
	printans(d,n); 
	return 0;
}
