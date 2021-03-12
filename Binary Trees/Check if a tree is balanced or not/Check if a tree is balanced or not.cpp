#include<bits/stdc++.h>
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

bool isHeightBalancedTree(node *root,int *height)
{
	int lh=0,rh=0;
	
	// base case
	if(root==NULL)
	{
		*height=0;
		return true;
	}
	
	// recursive approach
	int l=0,r=0;
	
	l=isHeightBalancedTree(root->left,&lh);
	r=isHeightBalancedTree(root->right,&rh);
	
	*height=max(lh,rh)+1;
	
	if(abs(lh-rh<=1) and l and r)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}




int main()
{
	node *root=buildTree();
	
	int height=0;
	
	if(isHeightBalancedTree(root,&height))
	{
		cout<<"The tree is balanced";
	}
	else
	{
		cout<<"The tree is not balanced";
	}	 
	return 0;
}






