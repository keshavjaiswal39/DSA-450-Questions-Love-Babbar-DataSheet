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

node *buildInBST(node *root,int key)
{
	if(root==NULL)
	{
		return new node(key);
	}
	
	if(key<=root->data)
	{
		root->left=buildInBST(root->left,key);
	}
	else
	{
		root->right=buildInBST(root->right,key);
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

void Inorder(node *root,int k,int &count)
{
	if(root==NULL or count>=k)
	{
		return;
	}
	
	Inorder(root->left,k,count);
	count++;
	
	if(count==k)
	{
		cout<<root->data<<" ";
		return;
	}
	Inorder(root->right,k,count);
	
}

int kthMinElement(node *root,int k)
{	
	int count=0;
	
	Inorder(root,k,count);
}

int main()
{
	node *root=buildTree();
	
	int k;
	cin>>k;
	
	kthMinElement(root,k);
}



