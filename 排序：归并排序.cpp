#include<iostream>
using namespace std;
int n;
const int N=100010;
int d[N];
void merge(int d[],int start,int mid,int end)
{
	int *temp=(int*)malloc((end-start+1)*sizeof(int));
	int i=start;
	int j=mid+1;
	int k=0;
	while(i<=mid&&j<=end)
	{
		if(d[i]<=d[j])
		{
			temp[k++]=d[i++];
		}
		else
			temp[k++]=d[j++];
	}
	while(i<=mid)
	{
		temp[k++]=d[i++];
	}
	while(j<=end)
	{
		temp[k++]=d[j++];
	}
	for(i=0;i<k;i++)
	{
		d[start+i]=temp[i];
	}
	free(temp);
}
void MergeSort(int d[],int start,int end)
{
	if(start<end)
	{
		int mid=start+(end-start)/2;
		MergeSort(d,start,mid);
		MergeSort(d,mid+1,end);
		merge(d,start,mid,end);
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
	MergeSort(d,0,n-1);
	printans(d,n);
	return 0;
}
