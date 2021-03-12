#include<bits/stdc++.h>
using namespace std;
 
int median(int [], int); /* to get median of a sorted array */
 
/* This function returns median of ar1[] and ar2[].
   Assumptions in this function:
   Both ar1[] and ar2[] are sorted arrays
   Both have n elements */
   
int getMedian(int ar1[], int ar2[], int n)
{
    /* return -1  for invalid input */
    if (n <= 0)
        return -1;
    if (n == 1)
        return (ar1[0] + ar2[0])/2;
    if (n == 2)
        return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;
 
    int m1 = median(ar1, n); /* get the median of the first array */
    int m2 = median(ar2, n); /* get the median of the second array */
 
    /* If medians are equal then return either m1 or m2 */
    if (m1 == m2)
        return m1;
 
    /* if m1 < m2 then median must exist in ar1[m1....] and
        ar2[....m2] */
    if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar1 + n/2 - 1, ar2, n - n/2 +1);    // arr 1 ka (n/2)-1th element se n-1  and arr 2 ka n-n/2+1 index tak
        return getMedian(ar1 + n/2, ar2, n - n/2);   // arr 1 ka n/2th element se n-1  and arr 2 ka n-n/2 index tak
    }
 
    /* if m1 > m2 then median must exist in ar1[....m1] and
        ar2[m2...] */
    if (n % 2 == 0)
        return getMedian(ar2 + n/2 - 1, ar1, n - n/2 + 1);   // arr 2 ka (n/2)-1th element se n-1  and arr 1 ka n-n/2+1 index tak
    return getMedian(ar2 + n/2, ar1, n - n/2);   // arr 2 ka n/2th element se n-1  and arr 1 ka n-n/2 index tak
}
 
/* Function to get median of a sorted array */
int median(int arr[], int n)
{
    if (n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    else
        return arr[n/2];
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
	
	cout<<getMedian(a,b,n);
	
}
