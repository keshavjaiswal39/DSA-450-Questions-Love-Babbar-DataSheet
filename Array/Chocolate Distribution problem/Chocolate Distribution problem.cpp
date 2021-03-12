#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
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
		
		int m;
		cin>>m;
		
		sort(v.begin(),v.end());
		
		int s=0;
		int e=m-1;
		int ans=INT_MAX;
		while(e<n)
		{
			int min_diff=v[e]-v[s];
			ans=min(ans,min_diff);
			s++;
			e++;
		}
		
		cout<<ans<<endl;
		
	}
}
