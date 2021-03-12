#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int median(vector<vector<int>> &arr, int r, int c){
        // code here  
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
			
			place+=upper_bound(arr[i].begin(),arr[i].end(),mid)-arr[i].begin();  // arr[i] is the addres of first element of each row
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
};


int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int r,c;
		cin>>r>>c;
		
		vector<vector<int>> matrix(r, vector<int>(c));
		
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin>>matrix[i][j];
			}
		}

		Solution obj;		
		cout<<obj.median(matrix,r,c)<<endl;
	}
	return 0;
}





