#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int findMedian(int arr[][100],int r,int c)
{
	int min=INT_MAX;
	int max=INT_MIN;
	
	for(int i=0;i<r;i++)
	{
		// find out the min element in the col 1
		if(arr[i][0]<min)
		{
			min=arr[i][0];
		}
		
		// find out the max element in the last col
		if(arr[i][c-1]>max)
		{
			max=arr[i][c-1];
		}
	}
	
	int desired=((r*c)+1)/2;  // this means whichever element has to be the median it should have (r*c+1)/2 elements less than or equal to it
	
	while(min<max)
	{
		// since the numbers are sorted row wise, the max element is somthing that will be the highest value in that matrix so any number will be less than it so we find the mid element
		int mid=(min+max)/2;
		
		// count of the number less than mid
		int place=0;    
		
		for(int i=0;i<r;i++)
		{
			// we will find out the upper bound for the mid element in every row.
			// as bound function will give us the iterator to the elemnt just greater than the value which is mentioned int the function
			// we will substract address of the matrix of the specific row
			// and we will find the count using upper bound of the mid for all the row and increment the place with new count generated each time
			
			place+=upper_bound(arr[i],arr[i]+c,mid)-arr[i];  // arr[i] is the addres of first element of each row
		}
		
		if(place<desired)
		{
			// means the mid for which we found out the place has got the count less than the desired so it cannot have any median less than it so we say min= mid+1
			min=mid+1;
		}
		
		else
		{
			// means the mid for which we found out the place has got the count greater than the desired so the max will be mid or less than it and we say max=mid
			max=mid;
		}
	}	
	
	// if min > max then return the min
	return min;
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
	
	cout<<findMedian(arr,r,c)<<endl;
}




