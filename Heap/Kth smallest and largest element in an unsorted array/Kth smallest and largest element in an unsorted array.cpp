#include<iostream>
#include<queue>
using namespace std;

// for kth smallest, we will use max heap.
int kthSmallest(vector<int> v,int k)
{
	priority_queue<int> p;
	int n=v.size();
	
	for(int i=0;i<n;i++)
	{
		p.push(v[i]);
		
		if(p.size()>k)
		{
			p.pop();
		}
	}
	return p.top();
}

// for kth smallest, we will use min heap.
int kthLargest(vector<int> v,int k)
{
	priority_queue<int,vector<int>,greater<int> > q;
	int n=v.size();
	
	for(int i=0;i<n;i++)
	{
		q.push(v[i]);
		
		if(q.size()>k)
		{
			q.pop();
		}
	}
	return q.top();
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
	
	cout<<kthSmallest(v,k)<<endl;
	cout<<kthLargest(v,k)<<endl;
}



