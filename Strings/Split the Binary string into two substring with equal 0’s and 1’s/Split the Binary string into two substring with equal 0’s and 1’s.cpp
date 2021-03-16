#include<iostream>
#include<string>
using namespace std;

int maxSubStr(string str,int n)
{
	int cnt=0;
	int count0=0;
	int count1=0;
	
	for(int i=0;i<n;i++)
	{
		if(str[i]=='0')
		{
			count0++;
		}
		else
		{
			count1++;
		}
		if(count0==count1)
		{
			cnt++;
		}
	}
	
	if(count0!=count1)
	{
		return -1;
	}
	
	return cnt;
}

int main()
{
	string s;
	cin>>s;
	
	int n=s.length();
	
	cout<<maxSubStr(s,n);
}
