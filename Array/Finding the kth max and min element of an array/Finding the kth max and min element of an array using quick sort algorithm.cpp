#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int pivot,int lo,int hi);
void swap(int *a,int *b);

int kthSmallest(int arr[],int lo,int hi,int k)
{
	int pivot=arr[hi];
	int index_pivot=partition(arr,pivot,lo,hi);
	if(k-1>index_pivot)
	{
		return kthSmallest(arr,index_pivot+1,hi,k);
	}
	else if(k-1<index_pivot)
	{
		return kthSmallest(arr,lo,index_pivot-1,k);
	}
	else
	{
		return arr[index_pivot];
	}
	
}

int partition(int arr[],int pivot,int lo,int hi)
{
	int i=lo;
	int j=lo;
	while(i<=hi)
	{
		if(arr[i]<=pivot)
		{
			swap(&arr[i],&arr[j]);
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}
	return j-1;   //j-1 qki last mein jo pivot apne propoer index pe swap hga as j++ ho rha hai.
}

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main()
{
	int arr[1000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int k;
	cin>>k;
	cout<<kthSmallest(arr,0,n-1,k);
}
