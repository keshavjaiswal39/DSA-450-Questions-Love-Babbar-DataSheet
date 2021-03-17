#include<iostream>
#include<stack>
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

node *buildInBST(node *root,int key)
{
	if(root==NULL)
	{
		return new node(key);
	}
	
	if(key<=root->data)
	{
		root->left=buildInBST(root->left,key);
	}
	else
	{
		root->right=buildInBST(root->right,key);
	}
	
	return root;
}

node *buildTree()
{
	int d;
	cin>>d;
	
	node *root=NULL;
	
	while(d!=-1)
	{
		root=buildInBST(root,d);
		cin>>d;
	}
	
	return root;
}

int countPairs(node *root1,node *root2,int k)
{
	if(root1==NULL or root2==NULL)
	{
		return 0;
	}
	
	stack<node*> st1,st2;
	node *top1,*top2;
	
	int count=0;
	
	while(1)
	{
		// push the root->left in the stack so that we get the smallest node at the top
		while(root1!=NULL)
		{
			st1.push(root1);
			root1=root1->left;
		}

		// push the root->right in the stack so that we get the greatest node at the top		
		while(root2!=NULL)
		{
			st2.push(root2);
			root2=root2->right;
		}
		
		if(st1.empty() or st2.empty())
		{
			break;
		}
		
		top1=st1.top();
		top2=st2.top();
		
		if((top1->data+top2->data)==k)
		{
			count++;
			
			st1.pop();
			st2.pop();
			
			// so that we now go to its right node in the tree 1
			root1=top1->right;
			// so that we now go to its left node in the tree 2
			root2=top2->left;
		}
		
		else if((top1->data+top2->data)<k)
		{
			st1.pop();
			root1=top1->right;
		}
		else
		{
			st2.pop();
			root2=top2->left;
		}
	}
	return count;
}


int main()
{
	node *root1=buildTree();
	node *root2=buildTree();
	
	int k;
	cin>>k;
	
	cout<<countPairs(root1,root2,k);
}



