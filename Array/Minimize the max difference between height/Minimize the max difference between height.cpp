#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int MinDiffTower(int arr[],int n,int k)
{
	int add,subtract;
	if(n==1)
	{
		return 0;
	}
	sort(arr,arr+n);
	int ans=arr[n-1]-arr[0];
	int small=arr[0]+k;
	int big=arr[n-1]-k;
	if(small>big)
	{
		swap(small,big);
	}
	for(int i=1;i<n-1;i++)
	{
		subtract=arr[i]-k;
		add=arr[i]+k;
		if(subtract>=small || add<=big)
		{
			continue;
		}
		if(big-subtract<=add-small)
		{
			small=subtract;
		}
		else
		{
			big=add;
		}
	}
	return min(ans,big-small);
}

int main()
{
	int n,k;
	cin>>n;
	int A[1000];
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	cin>>k;
	cout<<MinDiffTower(A,n,k);
	
}
