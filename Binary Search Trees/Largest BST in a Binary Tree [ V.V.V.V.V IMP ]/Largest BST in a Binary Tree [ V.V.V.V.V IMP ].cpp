#include<iostream>
#include<climits>
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

bool isBST(node *root,int minV,int maxV)
{
	if(root==NULL)
	{
		return true;
	}
	
	// as we need all the node of the BST to be unique so we will check for both the sub tree that is for the left sub tree and right sub tree
	// and root->data-1 for the left sub tree and root->data+1 in the right sub tree
	
	if(root->data>minV and root->data<maxV and isBST(root->left,minV,root->data) and isBST(root->right,root->data,maxV))
	{
		return true;
	}
	
	return false;
}

int size(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	
	return size(root->left) + 1 + size(root->right); 
}

int largestBST(node *root)
{
	if(isBST(root,INT_MIN,INT_MAX))
	{
		return size(root);
	}
	
	return max(largestBST(root->left),largestBST(root->right));
}

int main()
{
	node *root=buildTree();

	cout<<largestBST(root)<<endl;
	
	return 0;
}




