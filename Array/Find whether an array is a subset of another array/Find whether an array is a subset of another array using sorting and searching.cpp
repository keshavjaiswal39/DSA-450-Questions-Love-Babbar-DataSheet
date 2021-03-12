#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int l,int h,int key)
{
	int index;
	int mid=(l+h)/2;
	if(arr[mid]==key)
	{
		return mid;
	}
	else if(key<arr[mid])
	{
		binarySearch(arr,l,mid-1,key);
	}
	else if(key>arr[mid])
	{
		binarySearch(arr,mid+1,h,key);
	}
	else
	{
		return -1;
	}
}

int isarraySubset(int arr[],int brr[],int m,int n)
{
	int flag=0,index;
	for(int i=0;i<n;i++)
	{
		int key=brr[i];
		index=binarySearch(arr,0,m-1,key);
		if(index==-1)
		{
			flag=0;
			break;
		}
		else
		{
			flag=1;
		}
	}
	return flag;
}

int main()
{
	int m,n;
	cin>>m>>n;
	int a[10005];
	int b[10005];
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	sort(a,a+n);
	if(isarraySubset(a,b,m,n))
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	
}
