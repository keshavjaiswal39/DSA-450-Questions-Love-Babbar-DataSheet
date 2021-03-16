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

int minValue(node *root)
{
	if(root==NULL)
	{
		return -1;
	}
	
	node *current=root;
	
	while(current->left!=NULL)
	{
		current=current->left;
	}
	
	return current->data;
}

int maxValue(node *root)
{
	if(root==NULL)
	{
		return -1;
	}
	
	node *current=root;
	
	while(current->right!=NULL)
	{
		current=current->right;
	}
	
	return current->data;
}

int main()
{
	node *root=buildTree();
	
	cout<<minValue;
	cout<<endl;
	cout<<maxValue;
	
}
