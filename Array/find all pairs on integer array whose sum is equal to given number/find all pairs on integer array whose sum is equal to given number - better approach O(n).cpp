#include<bits/stdc++.h>
using namespace std;

int getPairsSum(int arr[],int n,int sum)
{
	unordered_map<int,int> m;
	//store all the elements in the map m
	for(int i=0;i<n;i++)
	{
		m[arr[i]]++;
	}
	int twice_count=0;
	//Iterete through each element and increment the count
	// note: every pair is counted twice
	for(int i=0;i<n;i++)
	{
		twice_count+=m[m-arr[i]];
		if(sum-arr[i]==arr[i])
		{
			twice_count--;
		}
	}
	return twice_count/2;
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
	int sum;
	cin>>sum;
	cout<<getPairsCount(arr,n,sum);	
}
