#include<iostream>
#include<string>

using namespace std;

string countAndSay(int n)
{
	if(n==1)
	{
		return "1";
	}
	if(n==2)
	{
		return "11";
	}
	
	string s="11";
	
	for(int i=3;i<=n;i++)
	{
		string t="";   // final results gets added here
		s=s+'&';   // we have added a delimiter to track the last element
		
		int count=1;
		
		for(int j=1;j<s.size();j++)
		{
			if(s[j]!=s[j-1])
			{
				t=t+to_string(count);
				t=t+s[j-1];
				count=1;
			}
			else
			{
				count++;
			}
		}
		s=t;
	}
	return s;
}

int main()
{
	int n;
	cin>>n;
	
	cout<<countAndSay(n);
}
