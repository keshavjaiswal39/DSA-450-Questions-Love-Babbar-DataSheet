#include<iostream>
#include<map>
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

void topView(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	queue<pair<node*,int> > q;
	map<int,int> m;  // distance and root->data
	
	int dist=0;  // initial horizontal distance
	
	q.push(make_pair(root,0));   // initially we push the root node and its distance as 0
	
	while(!q.empty())
	{
		dist=q.front().second;   // jo bhi node queue ke front mein hai usme se hume second element chaiye jo ki distance hai
		
		// bottom view kiliye sab logic same hga bas yaha map mein pehle se height pe kya element mapped hai, ucse apne koi matlab nai hai as har bar map data ko update karta hai
		// toh jo bhi data last mein store hua hga apne map mein woh hi map mein maintained rahega baaki saaara overwrite hojayega		
		m[dist]=root->data;
		
		if(root->left)
		{
			q.push(make_pair(root->left,dist-1));
		}
		
		if(root->right)
		{
			q.push(make_pair(root->right,dist+1));
		}
		
		q.pop();
		
		root=q.front().first;
	}
	
	for(auto i:m)
	{
		cout<<i.second<<" ";
	}
}

int main()
{
	node *root=buildTree();
	
	topView(root);
	
	return 0;
}




