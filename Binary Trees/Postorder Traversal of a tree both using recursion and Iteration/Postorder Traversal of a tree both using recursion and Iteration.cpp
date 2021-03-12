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

void PostorderIterative(node *root)
{
	stack<node*> s1;
	stack<node*> s2;
	
	s1.push(root);
	node *curr=root;
	
	while(s1.empty()==false)
	{
		curr=s1.top();
		s1.pop();
		
		s2.push(curr);
				
		if(curr->left)
		{
			s1.push(curr->left);
		}
		
		if(curr->right)
		{
			s1.push(curr->right);
		}
	}
	
	while(s2.empty()==false)
	{
		curr=s2.top();
		s2.pop();
		cout<<curr->data<<" ";
	}
	
}


int main()
{
	node *root=buildTree();
	
	PostorderIterative(root);
}





