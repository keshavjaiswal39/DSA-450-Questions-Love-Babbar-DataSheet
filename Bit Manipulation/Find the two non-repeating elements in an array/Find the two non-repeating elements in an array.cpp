#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[100005];
	int xor_=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		xor_=xor_^a[i];     // we get the total xor of the value
	}
	
	int temp=xor_;
	int pos=0;
	while((temp&1)!=1)
	{
		pos++;
		temp=temp>>1;      // here we get the position of the last set bit in the final answer
	}
	
	int mask=(1<<pos);     // creating a mask with the set bit 1
	
	int x=0;     // the elements which are occured only once
	int y=0;    // the elements which are occured only once
	
	for(int i=0;i<n;i++)
	{
		if((a[i]&mask)>0)
		{
			x=x^a[i];
		}
	}
	y=xor_^x;
	
	cout<<min(x,y)<<" "<<max(x,y);
	
}
