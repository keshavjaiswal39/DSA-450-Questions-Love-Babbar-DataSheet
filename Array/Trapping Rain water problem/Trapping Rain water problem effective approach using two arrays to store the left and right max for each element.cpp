#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[10000];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int res=0;
	
	int left[n],right[n];

	left[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		left[i]=max(left[i-1],arr[i]);
		cout<<left[i]<<" ";
	}
	
	cout<<endl;
	
	right[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--)
	{
		right[i]=max(right[i+1],arr[i]);
		cout<<right[i]<<" ";
	}
	
	for(int i=0;i<n;i++)
	{
		res=res+min(left[i],right[i])-arr[i];
	}
	
	cout<<res;
	
}
