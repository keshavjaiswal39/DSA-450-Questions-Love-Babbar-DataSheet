#include<bits/stdc++.h>
using namespace std;

int findLongestConsuqSubseq(int arr[],int n)
{
	int ans=0,count=0;
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
	{
		if(arr[i]==arr[i-1]+1)
		{
			count++;
		}
		else
		{
			count=1;
		}
		ans=max(ans,count);
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
	cout<<findLongestConsuqSubseq(arr,n);
	return 0;
}
