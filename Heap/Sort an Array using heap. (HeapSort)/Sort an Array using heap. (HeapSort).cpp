#include<bits/stdc++.h>
using namespace std;

bool minHeap=false;

bool compare(int x,int y)
{
	if(minHeap)
	{
		return x<y;
	}
	return x>y;
}

void Heapify(vector<int> &v,int idx,int size)
{
	int left = idx*2;
	int right = left+1;
	
	int last=size-1;
	int min_idx=idx;
	
	if(left<=last and compare(v[left], v[idx]))
	{
		min_idx=left;
	}
	
	if(right<=last and compare(v[right], v[min_idx]))
	{
		min_idx=right;
	}
	
	if(min_idx!=idx)
	{
		swap(v[idx],v[min_idx]);
		
		Heapify(v,min_idx,size-1);
	}
	
}

void buildHeap(vector<int> v)
{
	for(int i=v.size()-1/2; i>=1;i--)
	{
		Heapify(v,i,v.size());
	}
}

void HeapSort(vector<int> &v)
{
	buildHeap(v);
	int n=v.size();
	
	while(n>1)
	{
		swap(v[1],v[n-1]);
		n--;
		
		Heapify(v,1,n);
	}
}

void print(vector<int> v)
{
	for(int i=1; i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}

int main()
{
	int n;
	cin>>n;
	
	vector<int> v;
	v.push_back(-1);
	
	for(int i=1;i<=n;i++)
	{
		int num;
		cin>>num;
		
		v.push_back(num);
	}	
	
	print(v);
	cout<<endl;
	
	HeapSort(v);
	print(v);
	
	
}
