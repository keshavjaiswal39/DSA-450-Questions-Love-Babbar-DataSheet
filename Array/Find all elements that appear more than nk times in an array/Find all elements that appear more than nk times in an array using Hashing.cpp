#include<bits/stdc++.h>
using namespace std;

int max(int arr[],int n)
{
	int max=-32767;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	return max;
}

void more_than_KN_times(int arr[],int n,int k)
{
	int H[10005]={0};
	for(int i=0;i<n;i++)
	{
		H[arr[i]]++;
	}
	int count=0;
	int max_element=max(arr,n);
	for(int i=0;i<=max_element;i++)
	{
		if(H[i]>n/k)
		{
			cout<<i<<" "<<H[i]<<" times"<<endl;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[10005];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int k;
	cin>>k;
	more_than_KN_times(arr,n,k);
}
