#include<bits/stdc++.h>
using namespace std;

int maxProfit(int price[],int n)
{
	int buy1,profit1,buy2,profit2;
	
	buy1=buy2=INT_MAX;
	
	profit1=profit2=0;
	
	for(int i=0;i<n;i++)
	{
		buy1=min(buy1,price[i]);
		
		profit1=max(profit1,price[i]-buy1);
		
		buy2=min(buy2,price[i]-profit1);
		
		profit2=max(profit2,price[i]-buy2);
	}
	return profit2;
}

int main()
{
	int n;
	cin>>n;
	int price[10005];
	for(int i=0;i<n;i++)
	{
		cin>>price[i];
	}
	cout<<maxProfit(price,n);
}
