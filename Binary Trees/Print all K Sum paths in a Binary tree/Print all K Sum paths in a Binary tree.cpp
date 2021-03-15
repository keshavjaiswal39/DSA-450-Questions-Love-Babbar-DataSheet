#include<bits/stdc++.h>
#include<vector>

using namespace std;

class node{
	public:
		int data;
		node *left;
		node *right;
		
		node(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}
};

node *buildTree()
{
	int d;
	cin>>d;
	
	if(d==-1)
	{
		return NULL;
	}
	
	node *root=new node(d);
	
	root->left=buildTree();
	root->right=buildTree();
	
	return root;
}

void kPathSum(node *root,vector<int> &path,int k)
{
	if(root==NULL)
	{
		return;
	}
	
	path.push_back(root->data);
	
	kPathSum(root->left,path,k);
	kPathSum(root->right,path,k);
	
	int f=0;
	
	for(int j=path.size()-1;j>=0;j--)
	{
		f+=path[j];
		
		if(f==k)
		{
			for(int m=j;m<path.size();m++)
			{
				cout<<path[m]<<" ";
			}
			cout<<endl;
		}
	}
	path.pop_back();
}


int main()
{
	node *root=buildTree();
	vector<int> path;
	
	int k;
	cin>>k;
	
	kPathSum(root,path,k);
}










