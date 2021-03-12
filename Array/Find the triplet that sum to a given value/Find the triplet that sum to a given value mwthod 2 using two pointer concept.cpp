#include<iostream>
#include<algorithm>
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
	
	int sum;
	cin>>sum;
	
	// sort the array
	sort(arr,arr+n);
	
	for(int k=0;k<n-2;k++)
	{
		int i=k+1;
		int j=n-1;
		
		while(i<j)
		{
			if(arr[i]+arr[j]+arr[k]==sum)
			{
				cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
				return true;
			}
			else if(arr[i]+arr[j]+arr[k]<sum)
			{
				i++;
			}
			else
			{
				j--;
			}
		}
	}
	return false;
}
