#include <bits/stdc++.h>
using namespace std;

void display(string str,int low,int high)
{
    for(int i=low;i<=high;i++)
    {
        cout<<str[i];
    }
}

void longestPalindrome(string str)
{
    int len=str.size();
    int maxLen=1;
    int start=0;
    int low,high;
    
    for(int i=1;i<len;i++)
    {
        // even length palindromic string
        low=i-1;
        high-i;
        
        while(low>=0 and high<len and str[low]==str[high])
        {
            if(high-low+1>maxLen)
            {
                start=low;
                maxLen=high-low+1;
            }
            low--;
            high++;
        }
        
        // odd length palindromic string
        low=i-1;
        high-i+1;
        
        while(low>=0 and high<len and str[low]==str[high])
        {
            if(high-low+1>maxLen)
            {
                start=low;
                maxLen=high-low+1;
            }
            low--;
            high++;
        }
    }
    
    if(maxLen==1)
    {
        start=0;
    }
    
    display(str,start,maxLen+start-1);
    
}

int main() {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    string str;
        cin>>str;
        
        longestPalindrome(str);
        cout<<endl;
	}

	return 0;
}
