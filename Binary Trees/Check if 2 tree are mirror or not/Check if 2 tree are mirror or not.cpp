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

bool isMirror(node* root1,node *root2)
{
 	// code here
 	if(root1==root2)
 	{
 	    return true;
 	}
 	
 	if(root1==NULL or root2==NULL)
 	{
 		return false;
	}
	
	return ((root1->data==root2->data) and isMirror(root1->left,root2->right) and isMirror(root1->right,root2->left)); 
}

int main()
{
	node *root1=buildTree();
	node *root2=buildTree();
	
	if(isMirror(root1,root2))
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	

}


