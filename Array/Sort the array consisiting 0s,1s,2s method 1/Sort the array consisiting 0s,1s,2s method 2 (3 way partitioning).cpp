#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main()
{
	int n;
	cin>>n;
	int arr[1000];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int l=0,m=0,h=n-1;
	while(m<h)
	{
		if(arr[m]==0)
		{
			swap(&arr[l],&arr[m]);
			l++;
			m++;
		}
		if(arr[m]==1)
		{
			m++;
		}
		if(arr[m]==2)
		{
			swap(&arr[m],&arr[h]);
			h--;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
