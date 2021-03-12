#include<bits/stdc++.h>
using namespace std;

long long int maxProduct(int *arr, int n) 
{
	    // code here
    int min_prod=arr[0];
    int max_prod=arr[0];
    int ans=arr[0];
    int choice_1,choice_2;
    for(int i=1;i<n;i++)
    {
        choice_1=min_prod*arr[i];
        choice_2=max_prod*arr[i];
        min_prod=min(arr[i],min(choice_1,choice_2));
        max_prod=max(arr[i],max(choice_1,choice_2));
        ans=max(ans,max_prod);
    }
    return ans;
}

int main()
{
	int n;
	cin>>n;
	int arr[10005];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<maxProduct(arr,n);
}
	
