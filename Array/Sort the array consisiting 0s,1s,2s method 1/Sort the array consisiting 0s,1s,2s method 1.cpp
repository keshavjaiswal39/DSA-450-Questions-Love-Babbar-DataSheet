#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[1000];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int c1,c2,c3;
	for(i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
			c1++;
		}
		if(arr[i]==1)
		{
			c2++;
		}
		if(arr[i]==2)
		{
			c2++;
		}
	}
	while(c1!=0)
	{
		cout<<"0"<<" ";
		c1--;
	}
	while(c2!=0)
	{
		cout<<"1"<<" ";
		c2--;
	}
	while(c2!=0)
	{
		cout<<"2"<<" ";
		c2--;
	}
	return 0;
}
