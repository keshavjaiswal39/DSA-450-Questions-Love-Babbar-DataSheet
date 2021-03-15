#include <bits/stdc++.h>
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
 
bool isIsomorphic(node *root1,node *root2)
{
	if(root1==NULL and root2==NULL)
	{
		return true;
	}
	if(root1==NULL or root2==NULL)
	{
		return false;
	}
	if(root1->data!=root2->data)
	{
		return false;
	}
	
	bool a=isIsomorphic(root1->left,root2->left) and isIsomorphic(root1->right,root2->right);
	bool b=isIsomorphic(root1->left,root2->right) and isIsomorphic(root1->right,root2->left);
	
	return a or b;
}


int main()
{
    node *root1=buildTree();
    node *root2=buildTree();
   
    if(isIsomorphic(root1,root2))
    {
    	cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
}
