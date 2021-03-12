#include<iostream>
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

void DiagonalTraversal(node *root)
{
	queue<node *> q;
	
	if(root==NULL)
	{
		return;
	}
	
	q.push(root);
	
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		
		while(temp)
		{
			if(temp->left)
			{
				q.push(temp->left);
			}
			
			cout<<temp->data<<" ";
			
			temp=temp->right;
		}
	}
}

int main()
{
	node *root=buildTree();
	
	DiagonalTraversal(root);
}










