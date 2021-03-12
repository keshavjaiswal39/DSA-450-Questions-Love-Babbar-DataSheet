#include<bits/stdc++.h>
using namespace std;

bool isarraySubset(int arr[],int brr[],int m,int n)
{
	set<int> hashset;
	for(int i=0;i<m;i++)
	{
		hashset.insert(arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(hashset.find(brr[i])==hashset.end())
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int m,n;
	cin>>m>>n;
	int a[10005];
	int b[10005];
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	sort(a,a+n);
	if(isarraySubset(a,b,m,n))
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	
}
