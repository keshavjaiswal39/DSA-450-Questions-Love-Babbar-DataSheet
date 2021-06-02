#include<iostream>
#include<queue>

using namespace std;

void MaxOfSubarraySizeK(vector<int> v, int k)
{
	int i=0;
	int ans=0;
	
	priority_queue<int> p;
	
	for(int i=0;i<v.size();i++)
	{
		p.push(v[i]);
		
		if(p.size()>=k)
		{
			int new_ans = p.top();
			p.pop();
			
			if(ans<new_ans)
			{
				ans=new_ans;
				cout<<ans<<" ";
			}
			else
			{
				cout<<ans<<" ";
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	
	vector<int> v;
	
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		
		v.push_back(num);
	}
	
	int k;
	cin>>k;
	
	MaxOfSubarraySizeK(v,k);
	
}
