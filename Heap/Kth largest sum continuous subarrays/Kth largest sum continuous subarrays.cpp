#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int kthLargestContinuosSum(vector<int> v,int k)
{
	priority_queue<int,vector<int>,greater<int> > p;
	vector<int> sum;
	int n=v.size();
	sum.push_back(0);
	
	for(int i=1;i<n+1;i++)
	{
		sum[i]=sum[i-1]+v[i-1];
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int x = sum[j]-sum[i-1];
			
			if(p.size()<k)
			{
				p.push(x);
			}
			
			else
			{
				if(p.top()<x)
				{
					p.pop();
					p.push(x);
				}
			}
		}
	}
	return p.top();
}


int main()
{
	vector<int> v;
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		
		v.push_back(num);
	}
	
	int k;
	cin>>k;
	
	cout<<kthLargestContinuosSum(v,k);
	
	return 0;	
}





