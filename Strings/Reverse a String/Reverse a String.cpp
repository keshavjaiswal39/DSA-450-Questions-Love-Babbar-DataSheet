#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;

void reverseString(string s)
{
	 int i=0;
    int j=s.size()-1;
    
    while(i<j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }
    
    cout<<s;
}


int main()
{
	string s;
	cin>>s;
	
	reverseString(s);
}


