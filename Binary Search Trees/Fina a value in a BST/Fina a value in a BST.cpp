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

bool search(node *root,int data)
{
	if(root==NULL)
	{
		return false;
	}
	if(data==root->data)
	{
		return true;
	}
	
	if(data<=root->data)
	{
		return search(root->left,data);
	}
	else
	{
		return search(root->right,data);
	}
	
	return false;
}

int main()
{
	node *root=buildTree();
	
	int data;
	cin>>data;
	
	if(search(root,data))
	{
		cout<<"Element found";
	}
	else
	{
		cout<<"Element not found";
	}
}
