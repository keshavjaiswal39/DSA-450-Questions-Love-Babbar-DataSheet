#include<bits/stdc++.h>
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

void buildDLL(node *root,node * &head, node * &prev,int &f)
{
	if(root==NULL)
	{
		return;
	}
	
	buildDLL(root->left,head,prev,f);
	
	if(f==0)
	{
		f=1;
		head=root;
		prev=root;
	}
	else
	{
		prev->right=root;
		prev->right->left=prev;
		prev=prev->right;
	}
	
	buildDLL(root->right,head,prev,f);
}

node *bTreeToDLL(node *root)
{
	node *head=NULL;
	node *prev=NULL;
	
	int f=0;
	
	buildDLL(root,head,prev,f);
	
	return head;
}

void Display(node *head)
{
	if(head==NULL)
	{
		return;
	}
	
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->right;
	}
}


int main()
{
	node *root=buildTree();
	
	node *head=bTreeToDLL(root);
	
	Display(head);
}




