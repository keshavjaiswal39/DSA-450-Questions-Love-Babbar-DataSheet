#include<iostream>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	int sr=0;  // start row
	int er=n-1;  // end row 
	
	int sc=0;  // start col
	int ec=m-1;  // end col
	
	int arr[100][100];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	
	while(sr<=er and sc<=ec)
	{
		for(int i=sc;i<=ec;i++)
		{
			cout<<arr[sr][i]<<" ";
		}
		sr++;
		
		for(int i=sr;i<=er;i++)
		{
			cout<<arr[i][ec]<<" ";
		}
		ec--;
		
		if(er>=sr)
		{
			for(int i=ec;i>=sc;i--)
			{
				cout<<arr[er][i]<<" ";
			}
		}
		er--;
		
		if(ec>=sc)
		{
			for(int i=er;i>=sr;i--)
			{
				cout<<arr[i][sc]<<" ";
			}
		}
		sc++;
	}
	
	return 0;
}





