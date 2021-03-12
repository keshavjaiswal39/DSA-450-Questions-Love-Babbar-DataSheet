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

void printKthLevel(node *root,int k)
{
	if(root==NULL)
	{
		return;
	}
	
	if(k==1)
	{
		cout<<root->data<<" ";
	}
	
	printKthLevel(root->left,k-1);
	printKthLevel(root->right,k-1);
}

void printAllKLevel(node *root)
{
	int k=height(root);
	
	for(int i=k;i>=1;i--)
	{
		printKthLevel(root,i);
		cout<<endl;
	}
}

int main()
{
	node *root=buildTree();
	
	printAllKLevel(root);
}
