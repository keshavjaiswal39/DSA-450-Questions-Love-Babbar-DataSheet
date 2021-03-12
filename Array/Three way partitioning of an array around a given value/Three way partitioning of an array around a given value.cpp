#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void threeWayPartitioning(int arr[],int n,int a,int b)
{
	int start=0;
	int end=n-1;
	
	for(int i=0;i<=end;)
	{
		if(arr[i]<a)
		{
			swap(arr[i++],arr[start++]);
		}
		else if(arr[i]>b)
		{
			swap(arr[i],arr[end--]);
		}
		else
		{
			i++;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	
	int arr[105];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int a,b;
	cin>>a>>b;
	
	threeWayPartitioning(arr,n,a,b);
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	
}
