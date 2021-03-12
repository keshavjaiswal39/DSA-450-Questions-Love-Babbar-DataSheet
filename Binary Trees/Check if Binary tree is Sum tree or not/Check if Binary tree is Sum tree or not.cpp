#include<bits/stdc++.h>
using namespace std;

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

node * buildTree()
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

int sum(node* root)
{
    if(root==NULL)
    {
    	return 0;
	}
	
	return sum(root->left)+sum(root->right)+root->data;
}

bool isSumTree(node *root)
{
	int ls,rs;
	
	// in case of leaf node and a tree with one node
	if(root==NULL or (root->left==NULL and root->right==NULL) )
	{
		return 1;
	}
	
	// Get the sum of nodes in left and right sub trees
	ls=sum(root->left);
	rs=sum(root->right);
	
	if((root->data==ls+rs) and isSumTree(root->left) and isSumTree(root->right))
	{
		return 1;
	}
	
	return 0;
}

int main()
{
	node *root=buildTree();
	
	if(isSumTree(root))
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
}
