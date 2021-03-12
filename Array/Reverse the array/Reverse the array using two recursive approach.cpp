#include<iostream>
using namespace std;

void ReverseArray(int arr[],int n,int start,int end)
{
	if(start>end)
	{
		return;
	}
	int temp=arr[start];
	arr[start]=arr[end];
	arr[end]=temp;
	ReverseArray(arr,n,start+1,end-1);
}

void DisplayReverse(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

int main()
{
	int arr[10000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ReverseArray(arr,n,0,n-1);
	DisplayReverse(arr,n);
	
}
