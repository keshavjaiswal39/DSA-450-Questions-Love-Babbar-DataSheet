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

void flatten(node *root)
{
	if(root == NULL || root->left == NULL and root->right == NULL)
	{
		return;
	}
	
	if(root->left!=NULL)
	{
		flatten(root->left);
		
		node *temp=root->right;
		root->right=root->left;
		root->left=NULL;
		
		node *t=root->right;
		while(t->right!=NULL)
		{
			t=t->right;
		}
		
		t->right=temp;
	}
	
	flatten(root->right);
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
	
	flatten(root);
	displayInorder(root);
	cout<<endl;
	
}







