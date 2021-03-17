void getArr(int arr[],int *index,Node *root)
{
    if(root==NULL)
        return ;
    getArr(arr,index,root->left);
    arr[*index]=root->data;
    *index+=1;
    getArr(arr,index,root->right);
}


void convert(Node *root,int arr[],int *index)
{
    if(root==NULL)
        return ;

    convert(root->left,arr,index);
    root->data=arr[*index];
    *index+=1;
    convert(root->right,arr,index);
}

Node *  binaryTreeToBST (Node *root)
{
    if(root==NULL)
        return NULL ;
    int *arr=new int[1000];
    int index=0;
    getArr(arr,&index,root);
    sort(arr,arr+index);
    index=0;
    convert(root,arr,&index);
    return root;
}
