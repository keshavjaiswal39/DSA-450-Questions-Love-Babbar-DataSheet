#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void TwoPointerApproach(int arr[],int n)
{
	int i=0,j=n-1;
	while(i<j)
	{
		if(arr[i]<0 and arr[j]<0)
		{
			i++;
		}
		else if(arr[i]>0 and arr[j]<0)
		{
			swap(&arr[i],&arr[j]);
			i++;
			j--;
		}
		else if(arr[i]>0 and arr[j]>0)
		{
			j--;	
		}
		else
		{
			i++;
			j--;
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
	TwoPointerApproach(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
