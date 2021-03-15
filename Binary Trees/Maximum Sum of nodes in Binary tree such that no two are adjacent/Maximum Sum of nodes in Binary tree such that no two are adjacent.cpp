#include<bits/stdc++.h>
#include<unordered_map>

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

unordered_map<node*,int> dp;

int maxSum(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	
	if(dp[root])
	{
		return dp[root];   // Memoization
	}
	
	int inc=root->data;
	
	if(root->left)
	{
		inc+=maxSum(root->left->left);
		inc+=maxSum(root->left->right);
	}
	if(root->right)
	{
		inc+=maxSum(root->right->right);
		inc+=maxSum(root->right->left);
	}
	
	int exc=maxSum(root->left)+maxSum(root->right);
	
	dp[root]=max(inc,exc);
	
	return dp[root];
}


int main()
{
	node *root=buildTree();
	
	cout<<maxSum(root);
}










