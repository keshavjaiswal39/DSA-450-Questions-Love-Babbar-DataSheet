#include<bits/stdc++.h>

using namespace std;

bool subArrayExists(int arr[], int n)
{
    unordered_map<int,bool> sumMap;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		if(sum==0 || sumMap[sum]==true)
		{
			return true;
		}
		sumMap[sum]=true;
	}
	return false;
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
	if(subArrayExists(arr,n))
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
}
