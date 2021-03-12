#include<iostream>
using namespace std;

int main()
{
	int currentsum=0;
	int maxsum=0;
	
	int a[1000],cumsum[1000]={0};
	
	int left=-1,right=-1;
	int i,j,n;
	
	cin>>n;
	
	cin>>a[0];
	cumsum[0]=a[0];
	
	for(i=1;i<n;i++)
	{
		cin>>a[i];
		cumsum[i]=a[i]+cumsum[i-1];
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			currentsum=0;
			currentsum=cumsum[j]-cumsum[i-1];
			if(currentsum>maxsum)
			{
				maxsum=currentsum;
				left=i;
				right=j;
			}
		}
	}
	
	cout<<"Maximun subarray sum = "<<maxsum<<endl;
	cout<<"Sub array with max sum is: ";
	for(i=left;i<=right;i++)
	{
		cout<<a[i]<<" ";
	}
}
