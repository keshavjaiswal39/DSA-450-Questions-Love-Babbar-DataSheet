void storeNodes(Node * root, unordered_set<int> &all_nodes,
                          unordered_set<int> &leaf_nodes)
{
    if (root == NULL)
        return ;
 
    // store all node of binary search tree
    all_nodes.insert(root->data);
 
    // store leaf node in leaf_hash
    if (root->left==NULL && root->right==NULL)
    {
        leaf_nodes.insert(root->data);
        return ;
    }
 
    // recur call rest tree
    storeNodes(root-> left, all_nodes, leaf_nodes);
    storeNodes(root->right, all_nodes, leaf_nodes);
}
 
// Returns true if there is a dead end in tree,
// else false.
bool isDeadEnd(Node *root)
{
    // Base case
    if (root == NULL)
        return false ;
 
    // create two empty hash sets that store all
    // BST elements and leaf nodes respectively.
    unordered_set<int> all_nodes, leaf_nodes;
 
    // insert 0 in 'all_nodes' for handle case
    // if bst contain value 1
    all_nodes.insert(0);
 
    // Call storeNodes function to store all BST Node
    storeNodes(root, all_nodes, leaf_nodes);
 
    // Traversal leaf node and check Tree contain
    // continuous sequence of
    // size tree or Not
    for (auto i = leaf_nodes.begin() ; i != leaf_nodes.end(); i++)
    {
        int x = (*i);
 
        // Here we check first and last element of
        // continuous sequence that are x-1 & x+1
        if (all_nodes.find(x+1) != all_nodes.end() &&
            all_nodes.find(x-1) != all_nodes.end())
            return true;
    }
 
    return false ;
}
