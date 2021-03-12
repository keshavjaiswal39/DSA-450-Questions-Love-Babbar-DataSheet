#include<bits/stdc++.h>
using namespace std;

int minJump(int arr[],int n)
{
	if(n<=1)    // the jump required to reach the starting index = 0
	{
		return 0;
	}
	if(arr[0]==0)  // if the first index value is 0, not possible to jump 
 	{
		return -1;
	}
	//store all the maximal reachable index in the array
	int maxReach=arr[0];
	// storess the number of steps, we can still take
	int step=arr[0];
	// stores the number of jump necessary to reach the maximal reachable position
	int jump=1;
	
	int i=1;
	for(int i=1;i<n;i++)
	{
		if(i==n-1)
		{
			return jump;
		}
		maxReach=max(maxReach,i+arr[i]);   //i+arr[i] means the index we can reach from a ith position
		
		// we used a step to get to the current index
		step--;
		
		//if no further steps left
		if(step==0)
		{
			jump++;
		
		// check if the current indexess/position lesser index is the max reach point from the previous indexes
			if(i>=maxReach)
			{
				return -1;
			}

		
			//re-initialized the steps to the amount of steps to reach maxReach from position i
			step=maxReach-i;
		}
	}
	return -1;
}

int main()
{
	int n;
	int a[100005];
	cin>>n;
	for(int i=0;i<n;i++)	
	{
		cin>>a[i];
	}
	cout<<minJump(a,n);
}
