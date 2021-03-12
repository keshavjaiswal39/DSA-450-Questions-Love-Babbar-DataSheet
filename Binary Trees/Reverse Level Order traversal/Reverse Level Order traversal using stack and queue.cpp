#include<iostream>
#include<queue>
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

void levelOrderBfs(node *root)
{
	queue<node *> q;
	stack<node *> s;
	q.push(root);
	
	if(root==NULL)
	{
		return;
	}
	
	while(!q.empty())
	{
		node *f=q.front();
		s.push(f);
		q.pop();
		
		// in case of reverse level order traversal we first fo to right
		if(f->right)
			q.push(f->right);
		
		if(f->left)
			q.push(f->left);
	}
	
	while(!s.empty())
	{
		root=s.top();
		cout<<root->data<<" ";
		s.pop();
	}
	
	return;	
}


int main()
{
	node *root=buildTree();
	
	levelOrderBfs(root);
}

