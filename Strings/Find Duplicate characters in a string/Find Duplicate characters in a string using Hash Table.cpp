#include<bits/stdc++.h>
#include<string>
using namespace std;


void duplicates_string(string name,int H[])
{
	int i;
	for(i=0;name[i]!='\0';i++)
	{
		H[name[i]-97]++;
	}
	
	for(i=0;i<26;i++)
	{
		if(H[i]>1)
		{
			cout<<char(i+97)<<" -> "<<H[i]<<endl;
		}
	}
}

int main()
{
	string name;
	
	int H[26]={0};
	
	cin>>name;
	
	duplicates_string(name,H);
}



