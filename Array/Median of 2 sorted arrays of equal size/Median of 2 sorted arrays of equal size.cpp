#include<bits/stdc++.h>
using namespace std;

int get_median(int a[],int b[],int n)
{
	int m1=-1;
	int m2=-1;
	int i=0;
	int j=0;
	
	for(int count=0;count<=n;count++)
	{
		// If all the elements in the array 1 are less than the elements of array 2
		if(i==n)
		{
			m1=m2;
			m2=b[0];
			break;
		}
		
		// If all the elements in the array 2 are less than the elements of array 1
		else if(j==n)
		{
			m1=m2;
			m2=a[0];
			break;
		}
		
		// If the ith element of array 1 is less than or equal to the jth element of array 2
		// then we take m1 as m2 and m2 as array1[i] and then increment i
		if(a[i]<=b[j])
		{
			m1=m2;
			m2=a[i];
			i++;
		}
		
		// If the ith element of array 1 is greater thab the jth element of array 2
		// then we take m1 as m2 and m2 as array2[j] and then increment j
		else
		{
			m1=m2;
			m2=b[j];
			j++;
		}
	}
	// return the avg of m1 and m2
	return (m1+m2)/2;
}

int main()
{
	int n;
	cin>>n;
	
	int a[100005],b[100005];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	
	cout<<get_median(a,b,n);
	
}
