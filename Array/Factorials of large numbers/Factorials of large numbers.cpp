#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int A[100000]={0};
	int end=0;
	A[0]=1;
	int carry=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=end;j++)
		{
			int mul=A[j]*i+carry;
			A[j]=mul%10;
			carry=mul/10;
		}
		while(carry!=0)
		{
			A[++end]=carry%10;
			carry=carry/10;
		}
	}
	for(int i=end;i>=0;i--)
	{
		cout<<A[i];
	}
	return 0;
}

