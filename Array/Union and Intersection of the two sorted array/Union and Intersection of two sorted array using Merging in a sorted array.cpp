//Union of two sorted array using Merging

/*

#include<iostream>
using namespace std;

int main()
{
	int A[1000],B[1000],C[1000];
	int m,n;
	cin>>m>>n;
	for(int x=0;x<m;x++)
	{
		cin>>A[x];
	}
	for(int y=0;y<n;y++)
	{
		cin>>B[y];
	}
	int i=0,j=0,k=0;
	while(i<m && j<n)
	{
		if(A[i]<B[j])
		{
			C[k++]=A[i++];
		}
		else if(A[i]>B[j])
		{
			C[k++]=B[j++];
		}
		else
		{
			C[k++]=A[i];
			i++;
			j++;
		}
	}   
	for(;i<m;i++)
	{
		C[k++]=A[i];
	}
	for(;j<n;j++)
	{
		C[k++]=B[j];
	}
	for(int p=0;p<k;p++)
	{
		cout<<C[p]<<" ";
	}
}

*/

//Union of two sorted array using Merging

/*

#include<iostream>
using namespace std;

int main()
{
	int A[1000],B[1000],C[1000];
	int m,n;
	cin>>m>>n;
	for(int x=0;x<m;x++)
	{
		cin>>A[x];
	}
	for(int y=0;y<n;y++)
	{
		cin>>B[y];
	}
	int i=0,j=0,k=0;
	while(i<m && j<n)
	{
		if(A[i]<B[j])
		{
			i++;
		}
		else if(A[i]>B[j])
		{
			j++;
		}
		else
		{
			C[k++]=A[i];
			i++;
			j++;
		}
	}   
	
	for(int p=0;p<k;p++)
	{
		cout<<C[p]<<" ";
	}
}

*/
