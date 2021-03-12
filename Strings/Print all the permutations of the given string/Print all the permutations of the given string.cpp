#include<iostream>
#include<string>
using namespace std;

void findPermutation(string s,int l,int r)
{
	if(l==r)
	{
		cout<<s<<endl;
	}
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(s[l],s[i]);
			
			findPermutation(s,l+1,r);
			
			swap(s[l],s[i]);
		}	
	}
	
}

int main()
{
	string s;
	cin>>s;
	
	findPermutation(s,0,s.size()-1);
}
