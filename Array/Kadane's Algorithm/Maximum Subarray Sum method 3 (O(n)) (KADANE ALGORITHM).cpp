#include<iostream>
using namespace std;

int main()
{
	int n,a[1000],i;
	int cs=0;
	int ms=0;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	//Kadane's Algorithm
	for(i=0;i<n;i++)
	{
		cs+=a[i];
		if(cs<0)
		{
			cs=0;
		}
		ms=max(cs,ms);
	}
	cout<<ms;
}
