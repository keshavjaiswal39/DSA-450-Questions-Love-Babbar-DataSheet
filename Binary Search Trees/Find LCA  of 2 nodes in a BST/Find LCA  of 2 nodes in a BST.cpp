#include<iostream>
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

node *buildInBST(node *root,int data)
{
	if(root==NULL)
	{
		return new node(data);
	}
	
	if(data<=root->data)
	{
		root->left=buildInBST(root->left,data);
	}
	else
	{
		root->right=buildInBST(root->right,data);
	}
	
	return root;
}

node *buildTree()
{
	int d;
	cin>>d;
	
	node *root=NULL;
	
	while(d!=-1)
	{
		root=buildInBST(root,d);
		cin>>d;
	}
	
	return root;
}

node * lca(node *root,int n1,int n2)
{
	if(root==NULL)
	{
		return NULL;
	}
	
	if(root->data>n1 and root->data>n2)
	{
		return lca(root->left,n1,n2);
	}
	
	if(root->data<n1 and root->data<n2)
	{
		return lca(root->right,n1,n2);
	}
	
	return root;
}

int main()
{
	node *root=buildTree();
	
	int data;
	cin>>data;
	
	int n1,n2;
	cin>>n1,n2;
	
	node *lca_new=lca(root,n1,n2);
	
	cout<<lca_new->data;
}
