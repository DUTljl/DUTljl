/*ϣ������ʵ������һ�ַ�����뷽����
���Ļ���˼���ǣ�����n������������У�ȡһ��С��n������gap(gap����Ϊ����)��������Ԫ�طֳ����ɸ��������У�
���о���Ϊgap�ı����ļ�¼����ͬһ�����У�Ȼ�󣬶Ը����ڵ�Ԫ�ؽ���ֱ�Ӳ�������
��һ���������֮��ÿһ�����Ԫ�ض�������ġ�Ȼ���Сgap��ֵ�����ظ�ִ�������ķ��������
�ظ������Ĳ�������gap=1ʱ���������о�������ġ� */
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
		for(i=0;i<gap;i++)//��gap���� 
		{
			for(j=i+gap;j<n;j+=gap)//�˴�ʵ��Ϊֱ�Ӳ������� 
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
	cout<<"����n:";
	cin>>n;
	cout<<"����n������:";
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
	ShellSort(d,n);
	printans(d,n);
	return 0;
}
