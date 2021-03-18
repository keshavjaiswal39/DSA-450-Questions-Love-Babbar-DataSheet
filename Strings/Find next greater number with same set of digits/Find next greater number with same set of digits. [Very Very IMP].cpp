#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

void findNext(char number[],int n)
{
	int i,j;
	
	for(i=n-1;i>0;i--)
	{
		if(number[i]>number[i-1])
			break;
	}
	
	if(i==0)
	{
		cout<<"Next Number not Possible";
		return;
	}
	
	int x=number[i-1],smallest=i;
	
	for(j=i;j<n;j++)
	{
		if(number[j]>x and number[j]<number[smallest])
			smallest=j;	
	}
	
	swap(number[smallest],number[i-1]);
	
	reverse(number+i,number+n);
	
	cout<<number<<endl;
	
	return;
}

int main()
{
	char s[10001];
	cin>>s;
	
	int n=strlen(s);
	
	findNext(s,n);
	
	return 0;
}
