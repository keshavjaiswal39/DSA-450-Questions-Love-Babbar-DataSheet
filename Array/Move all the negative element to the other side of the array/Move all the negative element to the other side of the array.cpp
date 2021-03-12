#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void SortNegative(int arr[],int n)
{
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<0)
		{
			if(i!=j)
			{
				swap(&arr[i],&arr[j]);
			}
			j++;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[1000];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	SortNegative(arr,n);
	for(int j=0;j<n;j++)
	{
		cout<<arr[j]<<" ";
	}
}
