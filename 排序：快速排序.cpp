#include<iostream>
using namespace std;
int n;
const int N=100010;
int d[N];
void QuickSort(int d[],int low,int high)
{
	int temp,i=low,j=high;
	if(low<high)
	{
		temp=d[low];
		while(i<j)
		{
			while(j>i&&d[j]>temp)
				--j;
			if(i<j)
			{
				d[i]=d[j];
				++i;
			}
			while(i<j&&d[i]<temp)
				++i;
			if(i<j)
			{
				d[j]=d[i];
				--j;
			}
		}
		d[i]=temp;
		QuickSort(d,low,i-1);
		QuickSort(d,j+1,high);
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
	QuickSort(d,0,n-1);
	printans(d,n);
	return 0;
}
