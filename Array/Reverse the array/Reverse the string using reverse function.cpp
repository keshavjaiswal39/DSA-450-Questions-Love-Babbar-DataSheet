#include<iostream>
using namespace std;

void reverseString(string &str)
{
	int n=str.length();
	for(int i=0;i<n/2;i++)
	{
		swap(str[i],str[n-i-1]);
	}
}

void displayString(string str)
{
	cout<<str;
}

int main()
{
	string str;
	cin>>str;
	reverseString(str);
	displayString(str);
}
