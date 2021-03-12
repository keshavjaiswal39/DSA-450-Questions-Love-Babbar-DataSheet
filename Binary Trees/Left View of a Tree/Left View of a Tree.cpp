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

void printTreeLeftView(node *root,int level,int &maxlevel)
{
	if(root==NULL)
	{
		return;
	}
	
	if(maxlevel<level)
	{
		cout<<root->data<<" ";
		maxlevel=level;
	}
	
	printTreeLeftView(root->left,level+1,maxlevel);
	printTreeLeftView(root->right,level+1,maxlevel);
}

int main()
{
	node *root=buildTree();
	
	int maxlevel=-1;
	
	printTreeLeftView(root,0,maxlevel);
}
