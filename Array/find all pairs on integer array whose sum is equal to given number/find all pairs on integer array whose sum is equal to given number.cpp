#include<bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[],int n,int sum)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]+arr[j]==sum)
			{
				count++;
			}
		}
	}
	return count;
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
	int sum;
	cin>>sum;
	cout<<getPairsCount(arr,n,sum);	
}
