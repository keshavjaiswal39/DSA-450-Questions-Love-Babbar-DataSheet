#include<bits/stdc++.h>
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
	sort(A,A+m);
	sort(B,B+n);
	
	int i=0,j=0,k=0;
	while(i<m && j<n)
	{
		if(A[i]<B[j])
		{
			cout<<A[i]<<" ";
			i++;
		}
		else if(A[i]>B[j])
		{
			cout<<B[j]<<" ";
			j++;
		}
		else
		{
			cout<<A[i]<<" ";
			i++;
			j++;
		}
	}   
	for(;i<m;i++)
	{
		cout<<A[i]<<" ";
	}
	for(;j<n;j++)
	{
		cout<<B[j]<<" ";
	}
}

