#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[1000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int k;
	cin>>k;
	priority_queue<int>maxHeap;
	for(int i=0;i<n;i++)
	{
		maxHeap.push(arr[i]);
		if(maxHeap.size()>k)
		{
			maxHeap.pop();
		}
	}
	cout<<maxHeap.top();
}
