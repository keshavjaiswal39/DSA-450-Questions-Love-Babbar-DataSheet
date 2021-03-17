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

void ReverseInorder(node *root,int k,int &count)
{
	if(root==NULL or count>=k)
	{
		return;
	}
	
	ReverseInorder(root->right,k,count);
	count++;
	
	if(count==k)
	{
		cout<<root->data<<" ";
		return;
	}
	
	ReverseInorder(root->left,k,count);
}

int kthMaxElement(node *root,int k)
{	
	int count=0;
	
	ReverseInorder(root,k,count);
}

int main()
{
	node *root=buildTree();
	
	int k;
	cin>>k;
	
	kthMaxElement(root,k);
}



