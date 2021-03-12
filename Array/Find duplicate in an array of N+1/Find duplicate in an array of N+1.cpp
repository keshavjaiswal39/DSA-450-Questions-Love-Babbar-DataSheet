#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[10005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int i,j,temp=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j] && a[i]!=temp)
			{
				cout<<a[i]<<" ";
				temp=a[i];
			}
		}
	}
}
