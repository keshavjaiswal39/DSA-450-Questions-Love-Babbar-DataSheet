#include<bits/stdc++.h>
#include<string>

using namespace std;

bool validShuffle(string s1,string s2,string res)
{
	int l1=s1.size();
	int l2=s2.size();
	int lr=res.size();
	
	if((l1+l2)!=lr)
	{
		return false;
	}
	
	int i=0,j=0,k=0;
	
	while(k<lr)
	{
		if(i<l1 and s1[i]==res[k])
		{
			i++;
		}
		else if(j<l2 and s2[j]==res[k])
		{
			j++;
		}
		else
		{
			return false;
		}
		k++;
	}
	
	if(i<l1 or j<l2)
	{
		return false;
	}
	
	else
	{	
		return true;
	}
}

int main()
{
	string s1;
	string s2;
	string res;
	
	cin>>s1>>s2>>res;
	
	if (validShuffle(s2,s2,res))
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	
}
