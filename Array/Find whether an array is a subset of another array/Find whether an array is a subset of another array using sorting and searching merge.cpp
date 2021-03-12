#include<bits/stdc++.h>
using namespace std;

bool isarraySubset(int arr[],int brr[],int m,int n)
{
	int i=0;
	int j=0;
	if(m<n)
	{
		return 0;
	}
	sort(arr,arr+m);
	sort(brr,brr+n);
	
	while(i<n and j<m)
	{
		if(arr[j]<brr[i])
		{
			j++;
		}
		else if(arr[j]==brr[i])
		{
			j++;
			i++;
		}
		else if(arr[j]>brr[i])
		{
			return 0;
		}
	}
	return (i<n)?false:true;
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
