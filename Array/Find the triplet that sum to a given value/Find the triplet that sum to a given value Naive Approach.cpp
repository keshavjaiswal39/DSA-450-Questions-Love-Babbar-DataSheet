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
	
	int sum;
	cin>>sum;
	
	for(int i=0;i<n-2;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(arr[i]+arr[j]+arr[k]==sum)
				{
					cout<<"Triplets are : "<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
					return true;
				}
			}
		}
	}
	return false;
}
