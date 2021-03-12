#include<bits/stdc++.h>
using namespace std;

int max(int a[],int n)
{
	int max=-32767;
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}

int main()
{
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	int a[10005],b[10005],c[10005];
	for(int i=0;i<n1;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n2;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<n3;i++)
	{
		cin>>c[i];
	}
	int H[10005]={0};
	for(int i=0;i<n1;i++)
	{
		H[a[i]]++;
	}
	for(int i=0;i<n2;i++)
	{
		H[b[i]]++;
	}
	for(int i=0;i<n3;i++)
	{
		H[c[i]]++;
	}
	int a1=max(a,n1);
	int a2=max(b,n2);
	int a3=max(c,n3);
	int temp=max(a1,a2);
	int new_max=max(temp,a3);
//	int temp=max(a1,a2,a3);
	for(int i=0;i<new_max;i++)
	{
		if(H[i]==3)
		{
			cout<<i;
		}
	}
}
