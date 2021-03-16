#include<iostream>
#include<algorithm>
using namespace std;

int setBits(int N) 
{
    // Write Your Code here
    int count=0;
    
    while(N>0)
    {
        N=N&(N-1);
        count++;
    }
    
    return count;
}

int main()
{
	int n;
	cin>>n;
	
	cout<<setBits(n);
}
