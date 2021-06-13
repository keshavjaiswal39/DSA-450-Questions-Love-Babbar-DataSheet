int idx=0;
unordered_map<int,int> m;

Node *solve(int pre[],int in[],int l,int h)
{
	if(l>h)
	{
		return NULL;
	}
	
	Node *root=new Node(pre[idx++]);
	
	if(l==h)
	{
		return root;
	}
	
	int index=m[root->data];
	
	root->left=solve(pre,in,l,index-1);
	root->right=solve(pre,in,index+1,h);
	
	return root;
}

Node *buildTree(int in[],int pre[],int n)
{
	idx=0;
	m.clear();
	
	for(int i=0;i<n;i++)
	{
		m[in[i]]=i;
	}
	
	Node *root=solve(pre,in,0,n-1);
	
	return root;
}
