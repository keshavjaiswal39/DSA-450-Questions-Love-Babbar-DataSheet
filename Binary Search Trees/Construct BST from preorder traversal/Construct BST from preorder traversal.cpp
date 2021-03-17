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

node *buildBST(int pre[],int *preIndex,int key,int min,int max,int size)
{
	if(*preIndex>=size)
	{
		return NULL;
	}
	
	node *root=NULL;
	
	if (key > min && key < max) 
    {
    	root=new node(key);
		*preIndex=*preIndex+1;
	
		if(pre[*preIndex]>min and pre[*preIndex]<root->data)
		{
			root->left=buildBST(pre,preIndex,pre[*preIndex],min,key,size);
		}
		if(pre[*preIndex]<max and pre[*preIndex]>root->data)
		{
			root->right=buildBST(pre,preIndex,pre[*preIndex],key,max,size);
		}
	}
	
	return root;
}

node *buildTreeFromPreorder(int pre[],int n)
{
	int preIndex=0;
	
	return buildBST(pre,&preIndex,pre[0],INT_MIN,INT_MAX,n);
}

void Inorder(node* root)
{
    if (root == NULL)
    {
        return;
	}
	
	Inorder(root->left);
	cout << root->data << " ";
    Inorder(root->right);
}

int main()
{
	int n;
	cin>>n;
	int pre[10001];
	
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	
	node *root=buildTreeFromPreorder(pre,n);
	
	Inorder(root);
	
}
