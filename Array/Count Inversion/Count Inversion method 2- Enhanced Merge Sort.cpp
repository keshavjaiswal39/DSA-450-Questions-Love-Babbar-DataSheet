#include<bits/stdc++.h>
using namespace std;

int merge(int arr[],int temp[],int left,int mid,int right)
{
	int i,j,k;
	int inversion_count=0;
	i=left;
	j=mid;
	k=left;
	while((i<=mid-1) && (j<=right))
	{
		if(arr[i]<=arr[j])
		{
			temp[k++]=arr[i++];
		}
		else
		{
			temp[k++]=arr[j++];
			inversion_count=inversion_count+(mid-i); //qki i ke baad aur mid se pehle total elements chaiye including ith element
		}
	}
	while(i<=mid-1)
	{
		temp[k++]=arr[i++];
	}
	while(j<=right)
	{
		temp[k++]=arr[j++];
	}
	for(i=left;i<=right;i++)
	{
		arr[i]=temp[i];
	}
	return inversion_count;
}

int mergeSort(int arr[],int temp[],int left,int right)
{
	int mid,inversion_count=0;
	if(right>left)
	{
		mid=(left+right)/2;
		// Inversion will be sum of the inversion in left part,right part and number of inversions in merging
		inversion_count+=mergeSort(arr,temp,left,mid);
		inversion_count+=mergeSort(arr,temp,mid+1,right);
		// Merge two parts
		inversion_count+=merge(arr,temp,left,mid+1,right);
	}
	return inversion_count;
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
	int temp[10005];
	cout<<mergeSort(arr,temp,0,n-1);
}

