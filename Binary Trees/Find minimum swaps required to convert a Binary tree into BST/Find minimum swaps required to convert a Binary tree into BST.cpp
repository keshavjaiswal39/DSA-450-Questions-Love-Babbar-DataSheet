#include<bits/stdc++.h>
#include<vector>

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

node * buildTree()
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

void getInorder(node *root,vector<int> &v)
{
	if(root==NULL)
	{
		return;
	}
	
	getInorder(root->left,v);
	v.push_back(root->data);
	getInorder(root->right,v);
}

int minSwaps(vector<int> &v)
{
	// vector of pair of value and its index
	vector<pair<int,int> > t(v.size());
	
	for(int i=0;i<v.size();i++)
	{
		t[i].first=v[i];
		t[i].second=i;
	}

	sort(t.begin(),t.end());

	int cnt=0;
	
	for(int i=0;i<t.size();i++)
	{
		if(t[i].second==i)
		{
			continue;
		}
		else
		{
			cnt++;
			swap(t[i],t[t[i].second]);
			i--;
		}
	}
	return cnt;
}

int main()
{
	node *root=buildTree();
	
	vector<int> v;
	
	getInorder(root,v);

	cout<<minSwaps(v);
}






