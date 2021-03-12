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

void Inorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

node * mirrorTree(node *root)
{
	if(root==NULL)
	{
		return NULL;
	}
	
	node *temp;
	
	mirrorTree(root->left);
	mirrorTree(root->right);
	
	temp=root->left;
	root->left=root->right;
	root->right=temp;
	
	return root;
}

int main()
{
	node *root=buildTree();
	Inorder(root);
	
	cout<<endl;
	
	mirrorTree(root);
	Inorder(root);
}





