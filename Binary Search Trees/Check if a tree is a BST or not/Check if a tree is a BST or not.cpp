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

// Accepts the old root node and returns the new root node
node *insertInBST(node *root,int data)
{
	// base case
	if(root==NULL)
	{
		return new node(data);
	}
	
	if(data<=root->data)
	{
		root->left=insertInBST(root->left,data);
	}
	else
	{
		root->right=insertInBST(root->right,data);
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
		root=insertInBST(root,d);
		cin>>d;
	}
	
	return root;
}

bool isBST(node *root,int minV=INT_MIN,int maxV=INT_MAX)
{
	if(root==NULL)
	{
		return true;
	}
	
	// as we need all the node of the BST to be unique so we will check for both the sub tree that is for the left sub tree and right sub tree
	// and root->data-1 for the left sub tree and root->data+1 in the right sub tree
	
	if(root->data>=minV and root->data<=maxV and isBST(root->left,minV,root->data-1) and isBST(root->right,root->data+1,maxV))
	{
		return true;
	}
	
	return false;
}

void displayInorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	displayInorder(root->left);
	cout<<root->data<<" ";
	displayInorder(root->right);
}

int main()
{
	node *root=buildTree();
	
	displayInorder(root);
	cout<<endl;
	
	if(isBST(root))
	{
		cout<<"The tree is a BST";
	}
	else
	{
		cout<<"The tree is not a BST";
	}
	
}




