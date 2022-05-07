/*希尔排序实质上是一种分组插入方法。
它的基本思想是：对于n个待排序的数列，取一个小于n的整数gap(gap被称为步长)将待排序元素分成若干个组子序列，
所有距离为gap的倍数的记录放在同一个组中；然后，对各组内的元素进行直接插入排序。
这一趟排序完成之后，每一个组的元素都是有序的。然后减小gap的值，并重复执行上述的分组和排序。
重复这样的操作，当gap=1时，整个数列就是有序的。 */
#include<iostream>
using namespace std;
int n;
const int N=100010;
int d[N];
void ShellSort(int d[],int n)
{
	int i,j,gap;
	for(gap=n/2;gap>0;gap/=2)
	{
		for(i=0;i<gap;i++)//共gap个组 
		{
			for(j=i+gap;j<n;j+=gap)//此处实质为直接插入排序 
			{
				if(d[j]<d[j-gap])
				{
					int temp=d[j];
					int k=j-gap;
					while(k>=0&&temp<d[k])
					{
						d[k+gap]=d[k];
						k-=gap;
					}
					d[k+gap]=temp;
				}
			}
		}
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
	ShellSort(d,n);
	printans(d,n);
	return 0;
}
