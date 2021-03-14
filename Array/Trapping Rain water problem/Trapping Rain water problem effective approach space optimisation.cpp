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
	
	int left_max=0,right_max=0;

	int lo=0;
	int hi=n-1;
	
	while(lo<hi)
	{
		if(arr[lo]<arr[hi])
		{
			if(arr[lo]>left_max)
			{
				left_max=arr[lo];
			}
			else
			{
				res+=left_max-arr[lo];
			}
			lo++;
		}
		
		else
		{
			if(arr[hi]>right_max)
			{
				right_max=arr[hi];
			}
			else
			{
				res+=right_max-arr[hi];
			}
			hi--;
		}
	}
	
	cout<<res;
	
}
