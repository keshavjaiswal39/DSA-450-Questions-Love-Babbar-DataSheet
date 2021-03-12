#include<bits/stdc++.h>
#include<stack>

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

// This function will give us the index of the closing parenthesis so that
// we can know the substring for left sub tree and right sub tree
int findIndex(string str,int s,int e)
{
	if(s>e)
	{
		return -1;
	}
	
	stack<char> st;
	
	for(int i=s;i<=e;i++)
	{
		if(str[i]=='(')
		{
			st.push(str[i]);
		}
		
		else if(str[i]==')')
		{
			if(st.top()=='(')
			{
				st.pop();
				
				if(st.empty())
				{
					return i;
				}
			}
		}
	}
	
	return -1;
}

node *buildTreeFromString(string str,int s,int e)
{
	if(s>e)
	{
		return NULL;
	}
	
	node *root=new node(str[s]-'0');
	int index=-1;
	
	// if we encounter an opening bracket then we will find the index for the closing brackets
	if(s+1<=e and str[s+1]=='(')
	{
		index=findIndex(str,s+1,e);
	}
	
	// If the index is found
	if(index!=-1)
	{
		// call for the left sub tree
		root->left=buildTreeFromString(str,s+2,index-1);
		
		// call fot the right sub tree
		root->right=buildTreeFromString(str,index+2,e-1);
	}
	
	return root;
}

void preorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	string s;
	cin>>s;
	
	node *root=buildTreeFromString(s,0,s.size()-1);
	
	preorder(root);
}




