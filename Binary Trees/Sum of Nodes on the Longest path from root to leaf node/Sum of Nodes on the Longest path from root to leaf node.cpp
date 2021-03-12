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
			right==NULL;
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

void helper(node *root,int sum,int len,int &maxLen,int &maxSum)
{
	// means we have come to the leaf node
	if(root==NULL)
	{
		// we assign maxLen to the max length of the subtree
		// which can be of left subtree or right subtree
		if(maxLen<len)
		{
			maxLen=len;
			maxSum=sum;
		}
		
		// if the length is same then we check if the sum obtained so far is 
		// smaller then the sum of other subtree of same height or not
		else if(maxLen==len and maxSum<sum)
		{
			maxSum=sum;
		}
		
		return;
	}
	
	helper(root->left,sum+root->data,len+1,maxLen,maxSum);
	helper(root->right,sum+root->data,len+1,maxLen,maxSum);
	
}

int sumOfLongRootToLeafPath(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	
	int maxSum=INT_MIN;
	int maxLen=0;
	
	helper(root,0,0,maxLen,maxSum);
	
	return maxSum;
}


int main()
{
	node *root=buildTree();
	
	cout<<sumOfLongRootToLeafPath(root);
}












