#include<bits/stdc++.h>
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

vector<int> levelOrderBfs(node *root)
{
	vector<int> ans;
	int level=1;
	
	queue<node *> q;
	q.push(root);
	
	if(root==NULL)
	{
		return ans;
	}
	
	while(!q.empty())
	{
		vector<int> temp;
		int size=q.size();
		
		while(size--)
		{
			node *f=q.front();
			temp.push_back(f->data);
			q.pop();
			
			if(f->left)
				q.push(f->left);
		
			if(f->right)
				q.push(f->right);			
		}
		
		if(level%2==0)
		{
			reverse(temp.begin(),temp.end());
		}
		
		for(int i=0;i<temp.size();i++)
		{
			ans.push_back(temp[i]);
		}
		
		level=!level;
	}
	
	return ans;	
}


int main()
{
	node *root=buildTree();
	
	vector<int> ans=levelOrderBfs(root);
	
	for(auto x:ans)
	{
		cout<<x<<" ";
	}
}

