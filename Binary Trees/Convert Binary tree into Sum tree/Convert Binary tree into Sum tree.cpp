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

int replaceSum(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	
	// means that its a leaf node so do nothing instead just return the root->data
	if(root->left==NULL and root->right==NULL)
	{
		return root->data;
	}
	
	int leftsum=replaceSum(root->left);
	int rightsum=replaceSum(root->right);
	
	// we store the root->data for that paricular node so that we have the intitial value of the root
	int temp=root->data;
	// now the new data for that root will be the sum of all the nodes below it	
	root->data=leftsum+rightsum;
	
	// we will return the sum by adding the initial value of that root too, which we stored in the temp initially
	return temp+root->data;
}

void bfs(node *root)
{
	queue<node*> q;
	
	q.push(root);
	q.push(NULL);
	
	while(!q.empty())
	{
		node *f=q.front();
		
		if(f==NULL)
		{
			cout<<endl;
			q.pop();
			
			if(!q.empty())
			{
				q.push(NULL);
			}
		}
		
		else
		{
			cout<<f->data<<" ";
			q.pop();
			
			if(f->left)
			{
				q.push(f->left);
			}
			
			if(f->right)
			{
				q.push(f->right);
			}
		}
	}
}

int main()
{
	node *root=buildTree();

	bfs(root);

	replaceSum(root);

	bfs(root);
}
