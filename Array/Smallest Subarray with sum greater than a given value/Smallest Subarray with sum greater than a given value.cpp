#include<bits/stdc++.h>
#include<climits>
using namespace std;

int minLengthSubarray(int a[],int n,int k)
{
	int final_len=INT_MAX;
	// we will use sliding window approach
	
	int sum=a[0];
	
	int i=0;
	int j=0;
	int len=1;
	
	while(j<n)
	{
		if(sum>k)
		{
			final_len=min(final_len,len);
			sum=sum-a[i];
			i++;
			len--;	
		}
		else
		{
			j++;
			sum=sum+a[j];
			len++;
		}
	}
	
	if(final_len>n)
	{
	    return 0;
	}

	return final_len;
} 

int main()
{
	int n;
	cin>>n;
	
	int arr[100005];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int k;
	cin>>k;
	
	cout<<minLengthSubarray(arr,n,k);
}

