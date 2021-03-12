#include<bits/stdc++.h>
using namespace std;


int Max(int a[],int n)
{
	int i;
	int max=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
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
	int H[10005]={0};
	int max=Max(a,n);
	for(int i=0;i<max;i++)
	{
		H[a[i]]++;
	}
	for(int i=0;i<max;i++)
	{
		if(H[i]>=2)
		{
			cout<<i<<" ";
		}
	}
	
}
