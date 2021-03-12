#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *left;
		node *right;
		
		node(int d)
		{
			data=d;
			left==NULL;
			right==NULL;
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

int ans;

void solve(node *root,int h,int &ma)
{
	if(root==NULL)
	{
		return;
	}
	
	if(ans==0)
	{
		return;
	}
	
	if(root->left==NULL and root->right==NULL)
	{
		// Means this is a leaf node
		if(ma==-1)
		{
			// means this is the 1st lead node we got so we cannot compare it with any height instead we will find out the height of this node from root
			ma=h;
		}
		else
		{
			if(h!=ma)
			{
				// Means the height of leaf node is not equal to the previous height
				ans=0;
			}
		}
		return;
	}
	
	solve(root->left,h+1,ma);
	solve(root->right,h+1,ma);
}

bool check(node *root)
{
	int ma=-1;
	int h=0;
	ans=1;
	solve(root,h,ma);
	return ans;
}

int main()
{
	node *root=buildTree();
	
	if(check(root))
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
}











