#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> v) 
{
	for(int x:v)
	{
		cout<<x<<" ";
	}
	cout<<endl;
}

bool minHeap=false;

bool compare(int a,int b)
	{
		if(minHeap)
		{
			return a<b;
		}
		// else its a maxHeap
		else
		{
			return a>b;
		}
	}

void heapify(vector<int> &v,int idx)   // index of the node that has to be heapify
	{
		int left=2*idx;
		int right=2*idx+1;
		
		int min_idx=idx;   // initially min_idx will point to root
		int last=v.size()-1;
		
		if(left<=last and compare(v[left],v[idx]))
		{
			min_idx=left;
		}
		if(right<=last and compare(v[right],v[min_idx]))
		{
			min_idx=right;
		}
		if(min_idx!=idx)
		{
			swap(v[idx],v[min_idx]);
			// recursive call
			heapify(v,min_idx);
		}
	}

void buildHeapOptimised(vector<int> &v)
{
	for(int i=v.size()-1/2;i>=1;i--)
	{
		heapify(v,i);	
	}	
}

int main()
{
	vector<int> v{-1,10,20,5,6,1,8,9,4};
	print (v);
	buildHeapOptimised(v);
	print(v);
}
