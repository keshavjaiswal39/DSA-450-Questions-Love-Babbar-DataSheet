#include<bits/stdc++.h>
#include<vector>
using namespace std;

int median(vector<int> v,int n)
{
	cout<<v.size();
	if(n%2==0)
	{
		int mid=n/2;
		return (v[mid]+v[mid-1])/2;
	}
	else
	{
		int mid=n/2;
		return v[mid];
	}
}

int main()
{
	int n;
	cin>>n;
	
	vector<int> v;
	
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		
		v.push_back(x);
	}
	
	sort(v.begin(),v.end());
	
	cout<<median(v,n);
	
}
