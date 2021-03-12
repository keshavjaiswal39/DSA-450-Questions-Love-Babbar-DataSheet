#include<bits/stdc++.h>
using namespace std;

void count_element_appearing_nbyk_times(int arr[],int n,int k)
{
	int x=n/k;
	for(int i=0;i<n-1;i++)
	{
		int count=1;
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j] && arr[j]!=-1)
			{
				count++;
				arr[j]=-1;
			}
		}
		if(count>x)
		{
			cout<<arr[i]<<" "<<count<<" times "<<endl;
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
