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
			left=NULL;
			right=NULL;
		}
};

node *buildInBST(node *root,int data)
{
	if(root==NULL)
	{
		return new node(data);
	}
	
	if(data<=root->data)
	{
		root->left=buildInBST(root->left,data);
	}
	else
	{
		root->right=buildInBST(root->right,data);
	}
	
	return root;
}

node *buildTree()
{
	int d;
	cin>>d;
	
	node *root=NULL;
	
	while(d!=-1)
	{
		root=buildInBST(root,d);
		cin>>d;
	}
	
	return root;
}

void Inorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	Inorder(root->left);
	cout<<root->data<<" -> ";
	Inorder(root->right);
}

void findPreSuc(node *root,node *&pre,node *&suc,int key)
{
	if(root==NULL)
	{
		return;
	}
	
	if(root->data==key)
	{
		if(root->left!=NULL)
		{
			node *temp=root->left;
			
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			pre=temp;
		}
		
		if(root->right!=NULL)
		{
			node *temp=root->right;
			
			while(temp->left!=NULL)
			{
				temp=temp->left;
			}
			suc=temp;
		}

		return ;
	}
	
	// if the key is smaller than go to the left subtree
	if(key<root->data)
	{
		suc=root;
		findPreSuc(root->left,pre,suc,key);
	}
	// else go to the right sub tree
	else
	{
		pre=root;
		findPreSuc(root->right,pre,suc,key);
	}
}

int main()
{
	node *root=buildTree();
	
	node *pre=NULL,*suc=NULL;
	int key;
	cin>>key;
	
	findPreSuc(root,pre,suc,key);
	
	if(pre!=NULL)
	{
		cout<<"Predecessor is: "<<pre->data<<endl;
	}
	else
	{
		cout<<"No predecessor"<<endl;
	}
	
	if(suc!=NULL)
	{
		cout<<"Successor is: "<<suc->data<<endl;
	}
	else
	{
		cout<<"No successor"<<endl;
	}
	
	
}
