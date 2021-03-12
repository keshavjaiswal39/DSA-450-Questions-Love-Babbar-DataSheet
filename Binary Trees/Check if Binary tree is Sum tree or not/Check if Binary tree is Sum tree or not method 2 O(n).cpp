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

bool isLeafNode(node* root)
{
	if(root==NULL)
	{
		return 0;
	}
    if(root->left==NULL and root->right==NULL)
    {
    	return 1;
	}
    
	return 0;
}

bool isSumTree(node *root)
{
	int ls,rs;
	
	// in case of leaf node and a tree with one node
	if(root==NULL or (isLeafNode(root)))
	{
		return 1;
	}

	if(isSumTree(root->left) and isSumTree(root->right))
	{
		// Get the sum of nodes in the left subtree
		if(root->left==NULL)
		{
			ls=0;
		}
		else if(isLeafNode(root->left))
		{
			ls=root->left->data;
		}
		else
		{
			ls=2*root->left->data;
		}
		
		// Get the sum of nodes in the right subtree
		if(root->right==NULL)
		{
			ls=0;
		}
		else if(isLeafNode(root->right))
		{
			ls=root->right->data;
		}
		else
		{
			ls=2*root->right->data;
		}
		
		// If root's data==sum of both the sub tree
		return (root->data==ls+rs);	
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
