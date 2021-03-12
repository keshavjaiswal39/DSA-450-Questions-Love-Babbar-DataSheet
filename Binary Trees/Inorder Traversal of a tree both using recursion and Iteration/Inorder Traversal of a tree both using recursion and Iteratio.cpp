#include<bits/stdc++.h>
#include<stack>
using namespace std;

class node{
	public:		
		int data;
		node *left=NULL;
		node *right=NULL;
		
		node (int d)
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

void InorderIterative(node *root)
{
	stack<node*> s;
	node *curr=root;
	
	while(root!=NULL or s.empty()==false)
	{
		// reach the left most node of the current node
		while(curr!=NULL)
		{
			s.push(curr);
			curr=curr->left;
		}
		
		// Current must be NULL at this point
		curr=s.top();
		s.pop();
		
		cout<<curr->data<<" ";
		
		// we have visited the node and its left subtree. Now its right subtree's turn
		curr=curr->right;
	}
}


int main()
{
	node *root=buildTree();
	
	InorderIterative(root);
}





