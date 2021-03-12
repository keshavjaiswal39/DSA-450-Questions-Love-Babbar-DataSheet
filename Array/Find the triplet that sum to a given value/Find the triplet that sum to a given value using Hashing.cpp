#include<iostream>
#include<algorithm>
#include<unordered_set>
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
		unordered_set<int> s;
		int current_sum=sum-arr[i];
		
		for(int j=i+1;j<n;j++)
		{
			if(s.find(current_sum-arr[j])!=s.end())
			{
				cout<<arr[i]<<" "<<arr[j]<<" "<<current_sum-arr[j]<<endl;
				return true;
			}
			s.insert(arr[j]);
		}
	}
	return false;
}
