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

node * buildTreeFromInorderPreorder(int pre[],int in[],int l,int h)
{
	static int i=0;   // index for the preorder 
	
	// base case
	if(l>h)
	{
		return NULL;
	}
	
	node *root=new node(pre[i]);
	
	int index=-1;
	
	for(int j=l;j<=h;j++)
	{
		if(in[j]==pre[i])
		{	
			index=j;
			break;
		}
	}
	
	i++;
	
	root->left=buildTreeFromInorderPreorder(pre,in,l,index-1);
	root->right=buildTreeFromInorderPreorder(pre,in,index+1,h);
	
	return root;	
}

void bfs(node *root)
{
	queue<node *> q;
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
	return;
}

int main()
{
	int n;
	cin>>n;
	
	int pre[1005];
	int in[1005];
	
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	
	node *root=buildTreeFromInorderPreorder(pre,in,0,n-1);
	
	bfs(root);
	
}







