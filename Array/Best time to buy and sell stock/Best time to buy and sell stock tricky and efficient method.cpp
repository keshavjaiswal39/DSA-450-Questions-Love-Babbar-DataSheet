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
	int max_difference=arr[1]-arr[0];
	int min_element=arr[0];
	
	for(int i=1;i<n;i++)
	{
		if(arr[i]-min_element>max_difference)
		{
			max_difference=arr[i]-min_element;
			min_element=arr[i];
		}
	}
	cout<<max_difference;
}



