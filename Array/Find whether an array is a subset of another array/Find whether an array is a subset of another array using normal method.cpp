#include<bits/stdc++.h>
using namespace std;

int isarraySubset(int a[],int b[],int m,int n)
{
	int flag=0;
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<m;i++)
		{
			if(b[j]==a[i])
			{
				flag=1;
				break;
			}
			else
			{
				flag=0;
			}
		}
	}
	return flag;
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
	if(isarraySubset(a,b,m,n))
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	
}
