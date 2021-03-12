#include<bits/stdc++.h>
using namespace std;

int reverse(int n)
{
	int rem;
	int sum=0;
	
	while(n>0)
	{
		rem=n%10;
		sum=sum*10+rem;
		n=n/10;
	}
	
	return sum;
}



int main()
{
	int n;
	cin>>n;
	
	int flag=1;
	int arr[10005];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=reverse(arr[i]))
		{
			flag=0;
			break;
		}
	}
	
	if(flag)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
}
