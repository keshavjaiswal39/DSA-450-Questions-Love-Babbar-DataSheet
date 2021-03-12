#include<bits/stdc++.h>
using namespace std;

void count_element_appearing_nbyk_times(int arr[],int n,int k)
{
	int x=n/k;
	sort(arr,arr+n);
	int i=0;
	int count=1;
	while(i<n)
	{
		if(arr[i]==arr[i+1])
		{
			count++;
			i++;
		}
		if(count>x)
		{
			cout<<arr[i]<<" "<<count<<" times"<<endl;
			count=1;
		}
		if(arr[i]!=arr[i+1])
		{
			i++;
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
	count_element_appearing_nbyk_times(arr,n,k);
	
}
