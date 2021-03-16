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

void Inorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	Inorder(root->left);
	cout<<root->data<<" -> ";
	Inorder(root->right);
}

node * deleteInBST(node *root,int key)
{
	if(root==NULL)
	{
		return NULL;
	}
	
	else if(key<root->data)
	{
		root->left=deleteInBST(root->left,key);
		return root;
	}
	
	else if(root->data==key)
	{
		if(root->left==NULL and root->right==NULL)
		{
			delete root;
			return NULL;
		}
		
		if(root->left!=NULL and root->right==NULL)
		{
			node *temp=root->left;
			delete root;
			return temp;
		}
		
		if(root->left==NULL and root->right!=NULL)
		{
			node *temp=root->right;
			delete root;
			return temp;
		}
		
		node *replace=root->right;
		
		while(replace->left!=NULL)
		{
			replace=replace->left;
		}
		
		root->data=replace->data;
		
		root->right=deleteInBST(root->right,replace->data);
		return root;
	}
	
	else
	{
		root->right=deleteInBST(root->right,key);
		return root;
	}
}

int main()
{
	node *root=buildTree();
	
	Inorder(root);
	
	int data;
	cin>>data;
	
	root=deleteInBST(root,data);
	
	Inorder(root);
	
}
