#include<iostream>
using namespace std;

int GCD(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		return GCD(b,a%b);
	}
}


int Rotate(int arr[],int n,int d)
{
	d=d%n;  // in case d is greater than n
	int gcd=GCD(d,n);
	for(int i=0;i<gcd;i++)
	{
		int temp=arr[i];
		int j=i;
		while(1)
		{
			int k=j+d; //after every d elemets we need to consider for the sets.
			if(k>=n)
			{
				k=k-n;
			}
			if(k==i)
			{
				break;
			}
			arr[j]=arr[k];
			j=k;
		}
		arr[j]=temp;
	}
}

int main()
{
	int A[1000];
	int n;
	int d;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	cin>>d;
	Rotate(A,n,d);
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
}
