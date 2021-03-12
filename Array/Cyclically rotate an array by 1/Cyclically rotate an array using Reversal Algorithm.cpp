#include<iostream>
using namespace std;

void Reverse(int arr[],int start, int end)
{
	while(start<end)
	{	
		int temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
		start++;
		end--;
	}
}

void Rotate(int arr[],int d,int n)
{
	if(d==0)
	{
		return;
	}
	if(d>n)
	{
		d=d%n;
	}
	Reverse(arr,0,d-1);
	Reverse(arr,d,n-1);
	Reverse(arr,0,n-1);
}


int main()
{
	int A[1000];
	int n;
	int d;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	cin>>d;
	Rotate(A,d,n);
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
}
