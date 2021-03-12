#include<iostream>
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

void printTreeLeftView(node *root)
{
	if (!root) 
        return; 
 
    queue<node*> q; 
    q.push(root); 
 
    while (!q.empty()) 
    {     
        // number of nodes at current level 
        int n = q.size(); 
         
        // Traverse all nodes of current level 
        for(int i = 1; i <= n; i++) 
        { 
            node* temp = q.front(); 
            q.pop(); 
                 
            // Print the left most element 
            // at the level 
            if (i == 1) 
                cout<<temp->data<<" "; 
             
            // Add left node to queue 
            if (temp->left != NULL) 
                q.push(temp->left); 
 
            // Add right node to queue 
            if (temp->right != NULL) 
                q.push(temp->right); 
        } 
    } 
}

int main()
{
	node *root=buildTree();
	
	int maxlevel=-1;
	
	printTreeLeftView(root);
}
