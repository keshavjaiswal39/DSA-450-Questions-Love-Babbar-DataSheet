#include<bits/stdc++.h>
#include<vector>
#include<queue>

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

void leftTree(node *root,vector<int> &ans)
{
	if(root==NULL)
	{
		return;
	}
	
	if(root->left)
	{
		ans.push_back(root->data);
		leftTree(root->left,ans);
	}
	
	else if(root->right)
	{
		ans.push_back(root->data);
		leftTree(root->right,ans);
	}
}

void leafNode(node *root,vector<int> &ans)
{
	if(root==NULL)
	{
		return;
	}
	
	leafNode(root->left,ans);
	
	if(root->left==NULL and root->right==NULL)
	{
		ans.push_back(root->data);
	}
	
	leafNode(root->right,ans);
}

void rightTree(node *root,vector<int> &ans)
{
	if(root==NULL)
	{
		return;
	}
	
	// we have to print the right node of the tree in reverse order
	// sp we first called the function and then pushed it into the vector
	
	if(root->right)
	{
		rightTree(root->right,ans);
		ans.push_back(root->data);
	}
	
	else if(root->left)
	{
		rightTree(root->left,ans);
		ans.push_back(root->data);
	}
}

vector<int> printBoundary(node *root)
{
	vector<int> ans;
	ans.push_back(root->data);
	
	leftTree(root->left,ans);
	leafNode(root,ans);
	rightTree(root->right,ans);
	
	return ans;
}

int main()
{
	node *root=buildTree();
	
	vector<int> ans=printBoundary(root);
	
	for(auto x:ans)
	{
		cout<<x<<" ";
	}
}







