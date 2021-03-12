#include<bits/stdc++.h>
#include<string>

using namespace std;

int main()
{
	string name;
	cin>>name;
	
	long long int i,H=0,x=0;
	
	for(i=0;i<name.size();i++)
	{
		x=1;
		x=x<<(name[i]-97);
		
		if((x&H)>0)
		{
			cout<<name[i]<<" ";
		}
		
		else
		{
			H=x|H;
		}
	}
	return 0;	
}
