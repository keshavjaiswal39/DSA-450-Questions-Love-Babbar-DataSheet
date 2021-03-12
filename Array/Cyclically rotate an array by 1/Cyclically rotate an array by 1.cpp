#include<iostream>
using namespace std;

int main()
{
	int A[1000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	int x=A[n-1];
	for(int i=n-1;i>=0;i--)
	{
		A[i+1]=A[i];
	}
	A[0]=x;
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
}
