#include<iostream>
#include<algorithm>
using namespace std;

void Rotate_Image(int A[][100],int m)
{
	int i,j,start_row,end_row;
	for(i=0;i<m;i++)
	{
		start_row=0;
		end_row=m-1;
		while(start_row<end_row)
		{
			swap(A[start_row][i],A[end_row][i]);
			start_row++;
			end_row--;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			if(i<j)
			{
				swap(A[i][j],A[j][i]);
			}
		}
	}
	
}


int main()
{
	int i,j,m;
	cin>>m;
	int A[100][100];
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>A[i][j];
		}
	}
	Rotate_Image(A,m);
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}
