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
	*index++;
	
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
	*index++;
	
	arrayToBST(arr,root->right,index);
}

void binartTreeToBST(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	int n=countNode(root);
	
	int*arr=new int[n];
	int i=0;
	
	getInArray(root,arr,&i);
	
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	i=0;
	arrayToBST(arr,root,&i);
	
	delete[] arr;
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
	
	binartTreeToBST(root);
	
	inorder(root);
	
}
