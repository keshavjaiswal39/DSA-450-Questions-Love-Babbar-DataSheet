#include<iostream>
#include<climits>

using namespace std;

int printSolution(int p[], int n)  
{  
    int k;  
    if (p[n] == 1)  
        k = 1;  
    else
        k = printSolution (p, p[n]-1) + 1;  
    cout<<p[n]<<" "<<n<<" ";  
    return k;  
}  

void solveWordWrap(int a[],int n,int m)
{
	// this is space array which will store the space left when the particular word is taken
	int space[n+1][n+1];
	// this will store the cost for the dp i.e space
	int ls[n+1][n+1];
	// this will store the optimal answer starting from the particular index
	int c[n+1];
	// this will print the path for the optimal solution
	int p[n+1];
	
	for(int i=1;i<=n;i++)
	{
		space[i][i]=m-a[i-1];// this gives the space remaining when single word is taken at a time
		
		for(int j=i+1;j<=n;j++)
		{
			// this gives the space left if we take other words as well
			space[i][j]=space[i][j-1]-a[j-1]-1;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			// now we will update the cost in the ls matrix
			if(space[i][j]<0)
			{
				// if we get space[i][j]<0, then we keep infinity there
				ls[i][j]=INT_MAX;
			}
			else if(j==n and space[i][j]>=0)
			{
				// if we are in the last line and the space[i][j]>=0 then we make the cost 0
				ls[i][j]=0;
			}
			else
			{
				// for other lines, we calculate by squaring the number of spaces
				ls[i][j]=space[i][j]*space[i][j];
			}
		}
	}
	
	c[0]=0;
	for(int j=1;j<=n;j++)
	{
		c[j]=INT_MAX;
		for(int i=1;i<=j;i++)
		{
			if(c[i-1]!=INT_MAX and ls[i][j]!=INT_MAX and (c[i-1]+ls[i][j]<c[j]))
			{
				c[j]=c[i-1]+ls[i][j];
				p[j]=i;
			}
		}
	}	
	
	printSolution(p,n);
	cout<<endl;
}



int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
	    int l[10001];
	
    	int n;
    	cin>>n;
    		
    	for(int i=0;i<n;i++)
    	{
    		cin>>l[i];
    	}
    	
    	int m;
    	cin>>m;
    
    	solveWordWrap(l,n,m);
	}
    
}
