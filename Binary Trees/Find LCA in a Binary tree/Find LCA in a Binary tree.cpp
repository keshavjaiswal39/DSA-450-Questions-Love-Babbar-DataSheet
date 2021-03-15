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

node *LCA(node *root,int a,int b)
{
	if(root==NULL)
	{
		return NULL;
	}
	
	if(root->data==a or root->data==b)
	{
		return root;
	}
	
	// search in the left and rght subtrees
	node *leftans=LCA(root->left,a,b);
	node *rightans=LCA(root->right,a,b);
	
	if(leftans!=NULL and rightans!=NULL)
	{
		// it means we return the root
		return root;
	}
	
	if(leftans!=NULL)
	{
		// means the right sub tree returned NULL, so we return the left ans to the root
		return leftans;
	}
	else
	{
		// means the left sub tree returned NULL, so we return the right ans to the root
		return rightans;
	}
}





int main()
{
	node *root=buildTree();
	
	int a,b;
	cin>>a>>b;
	
	node *result=LCA(root,a,b);
	
	cout<<result->data;
}





