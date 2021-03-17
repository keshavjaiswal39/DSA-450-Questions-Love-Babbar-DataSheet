#include<bits/stdc++.h>
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

void getInArray(node *root,int inorder[],int *index)
{
	if(root==NULL)
	{
		return;
	}
	
	getInArray(root->left,inorder,index);
	
	inorder[*index]=root->data;
	*index+=1;
	
	getInArray(root->right,inorder,index);
}

node *buildTreeHelper(int *arr,int l,int h)
{
	if(l>h)
	{
		return NULL;
	}
	
	int mid=(l+h)/2;
	node *root=new node(arr[mid]);
	
	root->left=buildTreeHelper(arr,l,mid-1);
	root->right=buildTreeHelper(arr,mid+1,h);
	
	return root;
}

node * BSTtoBalancedBST(node *root)
{
	if(root==NULL)
	{
		return NULL;
	}
	
	int*arr=new int[1000];
	int i=0;
	
	getInArray(root,arr,&i);
	
	int n=i;
	
	return buildTreeHelper(arr,0,n-1);
	
}

void inorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main()
{
	node *root=buildTree();
	
	inorder(root);
	cout<<endl;
	
	node *temp=BSTtoBalancedBST(root);
	
	inorder(temp);
	
}
