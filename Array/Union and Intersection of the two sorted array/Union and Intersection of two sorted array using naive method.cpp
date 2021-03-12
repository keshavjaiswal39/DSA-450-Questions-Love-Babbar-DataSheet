// For union using the Naive approach

/*

#include<iostream>
using namespace std;

int main()
{
	int A[1000],B[1000];
	int U[1000];
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		cin>>A[i];
	}
	for(int j=0;j<n;j++)
	{
		cin>>B[j];
	}
	for(int k=0;k<m;k++)
	{
		U[k]=A[k];
	}
	int new_index=m;
	for(int j=0;j<n;j++)
	{
		int flag=0;
		for(int i=0;i<m;i++)
		{
			if(B[j]==U[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			U[new_index++]=B[j];
		}
	}
	
	for(int i=0;i<new_index;i++)
	{
		cout<<U[i]<<" ";
	}
	
}

*/

// For intersection using the Naive approach

/*

#include<iostream>
using namespace std;

int main()
{
	int A[1000],B[1000];
	int U[1000];
	int m,n,new_index=0;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		cin>>A[i];
	}
	for(int j=0;j<n;j++)
	{
		cin>>B[j];
	}
	for(int i=0;i<m;i++)
	{
		int flag=0;
		for(int j=0;j<n;j++)
		{
			if(A[i]==B[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			U[new_index++]=A[i];
		}
	}
	
	for(int i=0;i<new_index;i++)
	{
		cout<<U[i]<<" ";
	}
	
}

*/
