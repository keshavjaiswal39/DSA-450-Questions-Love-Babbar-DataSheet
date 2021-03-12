#include<bits/stdc++.h>
#include<vector>
using namespace std;

void sorted(vector<vector<int> > v,int n)
{
	vector<int> temp;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			temp.push_back(v[i][j]);
		}
	}
	
	sort(temp.begin(),temp.end());
	
	for(int i = 0; i < n*n; ++i) 
	{
    	v[i/n][i%n] = temp[i];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<v[i][j]<<" ";
		}
	}
	
}

int main()
{
	int n;
	cin>>n;
	
	vector<vector<int> > v;
	
	for(int i=0;i<n;i++)
	{
		vector<int> v1;
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			v1.push_back(x);
		}
		v.push_back(v1);
	}
	
	sorted(v,n);


}
