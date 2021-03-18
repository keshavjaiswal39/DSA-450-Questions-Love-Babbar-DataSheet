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

int countUsingMorrisTraversal(node *root)
{
	// *current---> is the root node initially and *pre---> will be inorder predecessor for the current node
	node *current,*pre;
	int count=0;
	
	if(root==NULL)
	{
		return count;
	}
	
	current=root;
	
	while(current!=NULL)
	{
		if(current->left==NULL)
		{
			count++;
			current=current->right;
		}
		else
		{
			pre=current->left;
			
			while(pre->right!=NULL and pre->right!=current)
			{
				pre=pre->right;
			}
			
			if(pre->right==NULL)
			{
				pre->right=current;
				current=current->left;
			}
			else
			{
				pre->right=NULL;
				count++;
				current=current->right;
			}
		}
	}
	
	return count;
}

int findMedianInBST(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	
	int count=countUsingMorrisTraversal(root);
	int currentCount=0;
	
	node *current=root,*pre,*prev;
	
	while(current!=NULL)
	{
		if(current->left==NULL)
		{
			currentCount++;
			
			if(count%2!=0 and currentCount==(count+1)/2)
			{
				return prev->data;
			}
			else if(count%2==0 and currentCount==(count/2)+1)
			{
				return (prev->data+current->data)/2;
			}
			prev=current;
			current=current->right;
		}
		else
		{
			pre = current->left; 
			
            while (pre->right != NULL && pre->right != current) 
            {
            	pre = pre->right; 
			}
  
            if (pre->right == NULL) 
            { 
                pre->right = current; 
                current = current->left; 
            } 
  
            else
            { 
                pre->right = NULL; 
  
                prev = pre; 
  
                currentCount++; 

                if (count % 2 != 0 && currentCount == (count+1)/2 ) 
                {
                	return current->data; 
				}
  
                else if (count%2==0 && currentCount == (count/2)+1) 
                {
                	return (prev->data+current->data)/2; 
				}
  
                prev = current; 
                current = current->right;
			}
		}
	}
}

int main()
{
	node *root=buildTree();
	
	cout<<findMedianInBST(root);
}
