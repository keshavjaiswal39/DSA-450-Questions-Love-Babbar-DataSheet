#include<bits/stdc++.h>
using namespace std;

void reArrange(int a[],int n)
{
	int i=-1,j=n;
	while(i<j)
	{
		while(i<=n-1 and a[i]>0)
		{
			i++;
		}
		while(j>=0 and a[j]<0)
		{
			j--;
		}
		if(i<j)
		{
			swap(a[i],a[j]);
		}
	}
	if(i==0 || i==n)
	{
		return;
	}
	int k=0;
	while(k<n && i<n)
	{
		swap(a[k],a[i]);
		i=i+1;
		k=k+2;
	}
}

int main()
{
	int n;
	cin>>n;
	int a[10005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	reArrange(a,n);
		
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
