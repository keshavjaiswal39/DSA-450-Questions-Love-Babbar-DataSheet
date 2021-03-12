#include<iostream>
#include<vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{   
    int start=matrix[0].size()-1;
    int i=0;
    int row=matrix.size(); 
    
    while(i<=row-1 and start>=0)
    {
        if(matrix[i][start]==target)
        {
            return 1;
            break;
        }
        
        if(target>matrix[i][start])
        {
            i++;
        }
        
        else if(target<matrix[i][start])
        {
            start--;
        }
    }
    return 0;
}

int main()
{
	int row,col;
	cin>>row>>col;
	
	vector<vector<int> > v;
	
	for(int i=0;i<row;i++)
	{
		vector<int> v1;
		for(int j=0;j<col;j++)
		{
			int x;
			cin>>x;
			v1.push_back(x);
		}
		v.push_back(v1);
	}
	
	int key;
	cin>>key;
	
	if(searchMatrix(v,key))
	{
		cout<<"True";
	}
	else
	{
		cout<<"False";
	}
	
	return 0;
}




