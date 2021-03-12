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

class Pair{
	public:
		int height;
		int diameter;
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

Pair fastDiameter(node *root)
{
	Pair p;
	
	if(root==NULL)
	{
		p.height=p.diameter=0;
		return p;
	}
	
	Pair left=fastDiameter(root->left);
	Pair right=fastDiameter(root->right);
	
	p.height=max(left.height,right.height)+1;
	
	p.diameter=max((left.height+right.height),max(left.diameter,right.diameter));
	
	return p;
}

int main()
{
	node *root=buildTree();
	
	Pair p=fastDiameter(root);
	
	cout<<"The max diameter of the binary tree is: "<<p.diameter<<" and height of the binary tree is "<<p.height<<endl;
}
