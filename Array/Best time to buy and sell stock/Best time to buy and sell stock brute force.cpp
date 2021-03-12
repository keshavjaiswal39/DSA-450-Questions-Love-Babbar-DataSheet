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
	int max_difference=-32767;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]-arr[i]>max_difference)
			{
				max_difference=arr[j]-arr[i];
			}
		}
	}
	cout<<max_difference;
}



