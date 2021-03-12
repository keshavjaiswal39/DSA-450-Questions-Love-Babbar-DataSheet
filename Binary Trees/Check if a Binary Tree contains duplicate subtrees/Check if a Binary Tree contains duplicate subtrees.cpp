#include<iostream>
#include<string>
#include<unordered_map>

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

unordered_map<string,int> m;

string solve(node *root)
{
	if(root==NULL)
	{
		return "$";
	}
	string s="";
	
	// when the size of subtree is 1 then we just return the string, we do not add it in the map
	if(root->left==NULL and root->right==NULL)
	{
		s=to_string(root->data);
		return s;
	}
	
	s=s+to_string(root->data);
	s=s+solve(root->left);
	s=s+solve(root->right);
		
	m[s]++;
	
	return s;	
}

bool dupSub(node* root)
{
	m.clear();
	solve(root);	
	
	for(auto x:m)
	{
		if(x.second>=2)
			return true;
	}
	
	return false;
}

int main()
{
	node *root=buildTree();
	
	if(dupSub(root))
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
}











