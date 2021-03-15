#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to
left child and a pointer to right child */
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
 
string inorder(node* root, unordered_map<string, int>& m)
{
    if (!root)
        return "";
 
    string str = "(";
    str += inorder(root->left, m);
    str += to_string(root->data);
    str += inorder(root->right, m);
    str += ")";
 
    // Subtree already present (Note that we use
    // unordered_map instead of unordered_set
    // because we want to print multiple duplicates
    // only once, consider example of 4 in above
    // subtree, it should be printed only once.
    if (m[str] == 1)
        cout << root->data << " ";
 
    m[str]++;
 
    return str;
}
 
// Wrapper over inorder()
void printAllDups(node* root)
{
    unordered_map<string, int> m;
    inorder(root, m);
}
 
// Driver code
int main()
{
    node *root=buildTree();
    
    printAllDups(root);
    
}
