#include<bits/stdc++.h>
using namespace std;

int swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

int reverse(int arr[],int i,int j)
{
	while(i<j)
	{
		swap(&arr[i],&arr[j]);
		i++;
		j--;
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[10005];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int i=n-2;
	int j=n-1;
	
	while(arr[i]>arr[i+1] && i>=0)
	{
		i--;
	}
	
	if(i<0)
	{
		reverse(arr,i+1,n-1);
	}
	
	else
	{
		while(arr[j]<=arr[i])
		{
			j--;
		}
		
		swap(&arr[i],&arr[j]);
		
		reverse(arr,i+1,n-1);
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	
}
