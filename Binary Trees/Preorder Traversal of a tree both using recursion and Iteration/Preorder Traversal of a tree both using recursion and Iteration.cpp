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

void PreorderIterative(node *root)
{
	stack<node*> s;
	node *curr=root;
	
	while(root!=NULL or s.empty()==false)
	{
		// reach the left most node of the current node
		while(curr!=NULL)
		{
			cout<<curr->data<<" ";
			
			if(curr->right)
			{
				s.push(curr->right);
			}
			
			curr=curr->left;
		}
		
		if(s.empty()==false)
		{
			curr=s.top();
			s.pop();
		}
	}
}


int main()
{
	node *root=buildTree();
	
	PreorderIterative(root);
}





