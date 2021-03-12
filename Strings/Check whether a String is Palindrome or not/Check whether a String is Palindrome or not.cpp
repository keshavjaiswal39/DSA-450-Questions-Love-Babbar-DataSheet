#include<bits/stdc++.h>
#include<string>
using namespace std;


int isPalindrome(string S)
{
	// Your code goes here
    int i=0;
    int j=S.size()-1;
    
    while(i<j)
    {
        if(S[i]!=S[j])
        {
            return 0;
            break;
        }
        i++;
        j--;
    }
    return 1;
}

int main()
{
	string s;
	cin>>s;
	
	if(isPalindrome(s))
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
}
