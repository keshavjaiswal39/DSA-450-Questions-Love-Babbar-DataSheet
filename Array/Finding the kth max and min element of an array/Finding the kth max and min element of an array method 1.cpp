#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[1000];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int k;
	cin>>k;
	
	int max=arr[n-k];
	int min=arr[k-1];
	cout<<"Max kth element is: "<<max<<endl;
	cout<<"Min kth element is: "<<min<<endl;
	return 0;
}
