#include<iostream>
using namespace std;
int n;
const int N=100010;
int d[N];
void InsertSort(int d[],int n)
{
	int i,j;
	int temp;
	for(i=1;i<n;i++)
	{
		temp=d[i];
		j=i-1;
		while(j>=0&&temp<d[j])
		{
			d[j+1]=d[j];
			j--;
		}
		d[j+1]=temp;
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
	InsertSort(d,n);
	printans(d,n);
	return 0;
}
