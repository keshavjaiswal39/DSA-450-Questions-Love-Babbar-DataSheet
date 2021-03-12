#include<iostream>
#include<queue>
#include<map>
using namespace std;

class node{
	public:
		int data;
		int index;
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

void topview(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	// ek queue banao jisme node ko insert karenge, uska map mein check karenge aur fir pop kardenge
	queue<node *> q;
	// map mein him horizontal distance aur uce distance me kaunsa element hai usko daalenge
	map<int,int> m;
	
	// initially humara index = 0 hga,
	// index ka mtlb hi hum horizontal distance bol rhe hai	
	int index=0;   // intitially make the distance 0, we will find the left distance and right distance
	
	// root jaha pe hai uska horizonal distance 0 hai
	root->index=0;
	
	//queue mein root pass karna hai
	q.push(root);
	
	// agar q ka size empty nai hai toh
	while(q.size())
	{
		// humara index ko root->index se update karege
		index=root->index;
		
		// agar uce index ka value pehle se map mein hga toh uska count > 1 hga, agar count 0 hua toh mtlb ki pehle se woh index aur value map mein hai h nai		
		if(m.count(index)==0)
		{
			// map mein nai hai toh update kardenge
			m[index]=root->data;
		}
		
		// abb root ke left child ko call karo and iska jo index hai, woh index-1 hga , left mein distance negative hojayega
		if(root->left)
		{
			root->left->index=index-1;
			// aur fir uce child ko push kardo queue mein
			q.push(root->left);
		}
		
		// idhar distance index+1 hojayega		
		if(root->right)
		{
			root->right->index=index+1;
			// aur fir uce child ko push kardo queue mein
			q.push(root->right);
		}
		
		// jab dono child push kardiya hai toh uske baad pop karna hai
		q.pop();
		
		// pop karne ke baad, humara root queue ka front element hojayega and aise hi har node kiliye karna hai jab tak null na ho
		root=q.front();
	}
	
	for(auto i:m)
	{
		cout<<i.second<<" ";
	}
}

int main()
{
	node *root=buildTree();
	
	topview(root);
	
	return 0;
}











