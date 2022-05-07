#include<iostream>
using namespace std;
int n;
const int N=100010;
int d[N];
void SelectSort(int d[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		int k=i;
		for(j=i+1;j<n;j++)
		{
			if(d[j]<d[k])
				k=j;
		}
		temp=d[k];
		d[k]=d[i];
		d[i]=temp;
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
	SelectSort(d,n);
	printans(d,n);
	return 0;
}
