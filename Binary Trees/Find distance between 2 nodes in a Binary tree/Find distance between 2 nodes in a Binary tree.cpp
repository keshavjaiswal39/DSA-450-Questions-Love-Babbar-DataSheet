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
	
	node *leftans=LCA(root->left,a,b);
	node *rightans=LCA(root->right,a,b);
	
	if(leftans!=NULL and rightans!=NULL)
	{
		return root;
	}
	
	if(leftans!=NULL)
	{
		return leftans;
	}
	else
	{
		return rightans;
	}
}

int search(node *root,int target,int level)
{
	if(root==NULL)
	{
		return -1;
	}
	
	if(root->data==target)
	{
		return level;
	}
	
	int left = search(root->left,target,level+1);
	
	if(left!=-1)
	{
		return left;
	}
	
	return search(root->right,target,level+1);
}

int shortestDist(node *root,int a,int b)
{
	node *lca_node=LCA(root,a,b);
	
	int l1=search(lca_node,a,0);
	int l2=search(lca_node,b,0);
	
	return l1+l2;
}


int main()
{
	node *root=buildTree();
	
	int a,b;
	cin>>a>>b;
	
	cout<<shortestDist(root,a,b);
	
}













