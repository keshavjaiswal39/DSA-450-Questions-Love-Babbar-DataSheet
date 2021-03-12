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

int height(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	
	return max(height(root->left),height(root->right))+1;
}

int diameter(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	
	int left_height=height(root->left);
	int right_height=height(root->right);
	
	int op1=left_height+right_height+1;
	int op2=diameter(root->left);
	int op3=diameter(root->right);
	
	return max(op1,max(op2,op2))+1;
}

int main()
{
	node *root=buildTree();
	
	cout<<diameter(root);
}
