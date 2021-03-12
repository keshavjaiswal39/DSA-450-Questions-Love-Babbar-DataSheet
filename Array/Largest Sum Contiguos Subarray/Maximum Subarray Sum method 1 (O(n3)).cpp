#include<iostream>
using namespace std;

int main()
{
	int i,j,k,n,a[1000];
	int sum,maxsum=0,left=0,right=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			sum=0;
			for(k=i;k<=j;k++)
			{
				sum+=a[k];
			}
			if(maxsum<sum)
			{
				left=i;
				right=j;
				maxsum=sum;
			}
		}
	}
	cout<<"Maximun subarray sum = "<<maxsum<<endl;
	cout<<"Sub array with max sum is: ";
	for(k=left;k<=right;k++)
	{
		cout<<a[k]<<" ";
	}
}
