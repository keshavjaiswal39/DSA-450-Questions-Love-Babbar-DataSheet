// Time- O(NLOGN)  AND O(1) EXTRA SPACE SOLUTION

#include<bits/stdc++.h>
using namespace std;

struct Interval
{
	int s;
	int e;
};

bool mycompare(Interval a,Interval b)
{
	return a.s<b.s;
}

void MergeIntervals(Interval arr[],int n)
{
	sort(arr,arr+n,mycompare);
	int index=0;
	for(int i=1;i<n;i++)
	{
		if(arr[index].e>=arr[i].s)
		{
			arr[index].e=max(arr[index].e,arr[i].e);
			arr[index].s=min(arr[index].s,arr[i].s);
		}
		else
		{
			index++;
			arr[index]=arr[i];
		}
	}
	// printing the merged intervals
	for(int i=0;i<=index;i++)
	{
		cout<<"["<<arr[i].s<<", "<<arr[i].e<<"]";
	}
}

int main()
{
	Interval arr[1000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].s>>arr[i].e;
	}
	MergeIntervals(arr,n);
	return 0;
}


