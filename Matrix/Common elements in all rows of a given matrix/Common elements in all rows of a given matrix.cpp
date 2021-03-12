#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

void printCommonElements(int mat[][100],int N,int M) 
{ 
    unordered_map<int, int> mp; 
  
    // initalize 1st row elements with value 1 
    for (int j = 0; j < N; j++) 
        mp[mat[0][j]] = 1; 
  
    // traverse the matrix 
    for (int i = 1; i < M; i++) 
    { 
        for (int j = 0; j < N; j++) 
        { 
            // If element is present in the map and 
            // is not duplicated in current row. 
            if (mp[mat[i][j]] == i) 
            { 
               // we increment count of the element 
               // in map by 1 
                mp[mat[i][j]] = i + 1; 
  
                // If this is last row 
                if (i==M-1) 
                  cout << mat[i][j] << " "; 
            } 
        } 
    } 
} 

int main()
{
	int n,m;
	cin>>n>>m;
	
	int mat[100][100];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>mat[i][j];
		}
	}
	
	printCommonElements(mat,n,m);
}
