#include<iostream>
using namespace std;
int n;
const int N=100010;
int d[N];
void maxheap_down(int d[],int start,int end)//第一个元素索引为0 
{
	int c=start;
	int l=2*c+1;
	int temp=d[c];
	for(;l<=end;c=l,l=2*l+1)//左孩子索引为2N+1，右孩子为2N+2 
	{
		if(l<end&&d[l]<d[l+1])//l指向左右孩子中较大的一个 
		{
			l++;
		}
		if(temp>=d[l])
			break;
		else
		{
			d[c]=d[l];
			d[l]=temp;
		}
	}
}
void HeapSort(int d[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
		maxheap_down(d,i,n-1);//建立初始堆 
	for(i=n-1;i>0;i--)
	{
		swap(d[0],d[i]);//将根节点放入最终位置 
		maxheap_down(d,0,i-1);
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
	HeapSort(d,n);
	printans(d,n);
	return 0;
}
