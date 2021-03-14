#include<bits/stdc++.h>
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

int findLargestSubtreeSumHelper(node *root,int &ans)
{
	// if current node is null then return 0 to the parent node
	if(root==NULL)
	{
		return 0;
	}
	
	// subtree sum rooted at current node
	int currentSum=root->data + findLargestSubtreeSumHelper(root->left,ans) + findLargestSubtreeSumHelper(root->right,ans);
	
	// update the ans if sum is greater than answer so far
	ans=max(ans,currentSum);
	
	// return the current subtree sum to its parent node
	return currentSum;
}

int findLargestSubtreeSum(node *root)
{
	if(root==NULL)
	{
		return -1;
	}
	
	int ans=INT_MIN;
	
	findLargestSubtreeSumHelper(root,ans);
	
	return ans;
}

int main()
{
	node *root=buildTree();
	
	cout<<findLargestSubtreeSum(root);
	
	return 0;
}







