#include<iostream>
using namespace std;

// this function gives the index of first one for each row
int indexFirstOne(int arr[],int l,int h)
{
	if(h>=l)
	{
		int mid=(l+h)/2;
		
		if((mid==0 || arr[mid-1]==0) and arr[mid]==1)
		{
			return mid;
		}
		
		else if(arr[mid]==0)
		{
			return indexFirstOne(arr,mid+1,h);
		}
		else
		{
			return indexFirstOne(arr,l,mid-1);
		}	
	}
	return -1;
}

int rowWithMaxOnes(int arr[][100],int r,int c)
{
	int max_row_index=-1;
	int max=-1;
	
	int i,index;
	
	for(i=0;i<r;i++)
	{
		index=indexFirstOne(arr[i],0,c-1);
		int count=c-index;
		
		if(index!=-1 and count>max)
		{
			max=count;
			max_row_index=i;
		}
	}
	return max_row_index;
}

int main()
{
	int r,c;
	cin>>r>>c;
	
	int arr[100][100];
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	cout<<rowWithMaxOnes(arr,r,c);
}
