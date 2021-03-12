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
    int i, index; 
 
    int max_row_index = 0; 
    int max = indexFirstOne(arr[0], 0, c - 1); 
 
    for (i = 1; i < r; i++) 
    { 
        if (max != -1 && arr[i][c - max - 1] == 1) 
        { 
			
            index = indexFirstOne (arr[i], 0, c - max); 
 
            if (index != -1 && c - index > max) 
            { 
                max = c - index; 
                max_row_index = i; 
            } 
        } 
        else
        { 
            max = indexFirstOne(arr[i], 0, c - 1); 
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


