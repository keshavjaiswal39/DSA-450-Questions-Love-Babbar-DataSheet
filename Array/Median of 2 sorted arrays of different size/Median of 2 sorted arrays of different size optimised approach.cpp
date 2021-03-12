#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
 
// to find the median of four element 
int medianOfFourElements(int a,int b,int c,int d)
{
	int Max=max(a,max(b,max(c,d)));
	int Min=min(a,min(b,min(c,d)));
	// it has to be sum of three num - min element - max element
	// e.g   7 9 8 6 -> sum=30, min=6, max=9, so we get 30-6-9=15 , now median=15/2=7.5
	return ((a+b+c+d)-Max-Min)/2;
}  
 
// to find the median of three element 
int medianOfThreeElements(int a,int b,int c)
{
	// it has to be sum of three num - min element - max element
	// e.g   7 9 8 -> sum=24, min=7, max=9, so we get 24-7-9=8
	return (a+b+c)-max(a,max(b,c))-min(a,min(b,c));
} 
 
// to find median of two elements
int medianOfTwoElements(int a,int b)
{
	return (a+b)/2;
}

// to find the median from a single array
int medianSingle(int a[],int n)
{
	// if no element in the array
	if(n==0)
	{
		return -1;
	}
	
	// if even no. of elements
	if(n%2==0)
	{
		return (a[n/2]+a[n/2-1])/2;
	}
	// if odd number of element
	return a[n/2];
	
} 

// this fucntion assumes that always array a is smaller than array b and n is less than or equal to m
int getMedian(int a[],int b[],int n,int m)
{
	// id the size of array a is 0 median will be generated from the array b
	if(n==0)
	{
		return medianSingle(b,m);
	}
	
	// means if there is only one element in the smaller array
	if(n==1)
	{
		// there will be 3 cases
		
		// case-1
		// if one one element in the other array too
		if(m==1)
		{
			return medianOfTwoElements(a[0],b[0]);
		}
		
		// case-2
		// if odd number of elements in the other array
		if(m%2)
		{
			// median of (1st element in the array a, median of(b[mid],b[mid-1],b[mid+1]))
			return medianOfTwoElements(a[0],medianOfThreeElements(b[m/2],b[m/2-1],b[m/2+1]));
		}
		
		// case-3
		// if even number of elements in the other array
		// median of (1st element in the array a,b[m/2+1],b[m/2-1])
		return medianOfThreeElements(a[0],b[m/2+1],b[m/2-1]);
	}
	
	else if(n==2)
	{
		// case-4
		// if m is also 2
		// median will be for all four elements
		if(m==2)
		{
			return medianOfFourElements(a[0],a[1],b[0],b[1]);	
		}
		
		// case-5
		// if the larger array has odd number of elements then median will be
		if(m%2)
		{
			return medianOfThreeElements(b[m/2],max(a[0],b[m/2-1]),min(a[1],b[m/2+1]));
		}	
		
		// case-6
		// if even number of elements in the larger array
		return medianOfFourElements(b[m/2],b[m/2-1],max(a[0],b[m/2-2]),min(a[1],b[m/2+1]));	
	}
	
//	in case both the array are greater than 2,  we will find the median for both the array

	int idxA=(n-1)/2;
	int idxB=(m-1)/2;
	
	// if a[idxA]<=b[idxB], then median must exist in the A(idxA to n-1) and B(0 to idxB)
	if(a[idxA]<=b[idxB])
	{
		return getMedian(a+idxA,b,n/2+1,m-idxB);
	}
	
	// else median must exist in the A(0,idxA) and B(idxB,m-1)
	
	return getMedian(a,b+idxB,n-idxA,m/2+1);
}


// this functions makes sure that the smaller array is passed as first argument
int findMedian(int a[],int b[],int n,int m)
{
	// if 1st array is greater than the 2nd array pass 2nd array as 1st parameter
	if(n>m)
		return getMedian(b,a,m,n);
		
	return getMedian(a,b,n,m);
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	int a[100005],b[100005];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	
	cout<<findMedian(a,b,n,m);
	
}
