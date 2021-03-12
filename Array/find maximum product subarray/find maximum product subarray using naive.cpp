#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[10005];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int max=-32767;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int temp=1;
			for(int k=i;k<=j;k++)
			{
				temp*=arr[k];
			}
			if(temp>max)
			{
				max=temp;
			}
		}
	}
	cout<<max;
}
