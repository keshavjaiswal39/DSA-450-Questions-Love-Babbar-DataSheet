#include<bits/stdc++.h>
using namespace std;

int min_swap(int arr[],int n,int k)
{
	// Find the count of elements which are less than k
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<=k)
		{
			count++;
		}
	}
	
	// Find the count of element which are greater than k upto the count
	int bad=0;
	for(int i=0;i<count;i++)
	{
		if(arr[i]>k)
		{
			bad++;
		}
	}
	
	// Initialise answer with 'bad' value of current window
	int ans=bad;
	for(int i=0;j=count;j<n;i++,j++)
	{
		// Decrement the count of the previous window
		if(arr[i]>k)
		{
			bad--;
		}
		
		// Increment the count of the current window
		if(arr[j]>k)
		{
			bad++;
		}
		
		// Update ans if count of bad is less in current window
		ans=min(ans,bad);
	}
	
	return ans;
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
	
	int k;
	cin>>k;
	
	cout<<min_swap(arr,n,k);
}
