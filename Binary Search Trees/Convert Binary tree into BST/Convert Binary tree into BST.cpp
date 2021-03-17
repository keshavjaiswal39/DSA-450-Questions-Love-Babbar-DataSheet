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

int countNode(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	
	return 1+countNode(root->left)+countNode(root->right);
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

void arrayToBST(int *arr,node *root,int *index)
{
	if(root==NULL)
	{
		return;
	}
	
	arrayToBST(arr,root->left,index);
	
	root->data=arr[*index];
	*index+=1;
	
	arrayToBST(arr,root->right,index);
}

node * binartTreeToBST(node *root)
{
	if(root==NULL)
	{
		return NULL;
	}
	
	int*arr=new int[1000];
	int i=0;
	
	getInArray(root,arr,&i);
	
	sort(arr,arr+i);
	
	i=0;
	arrayToBST(arr,root,&i);
	
	delete[] arr;
	
	return root;
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
	
	node *temp=binartTreeToBST(root);
	
	inorder(temp);
	
}
