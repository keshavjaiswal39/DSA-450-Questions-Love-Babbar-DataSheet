/*First of all, it is given that it is a BST and nodes are greater than zero, root node can be in the range [1, 8] and if root val is say, val, then left sub-tree can have the value in the range [1, val-1] and right sub-tree the value in range [val+1, 8].
we need to traverse recursively and when the the min and max value of range coincided it means that we cannot add any node further in the tree.
Hence we encounter a dead end.*/


bool deadEnd(Node* root, int min=1, int max=INT_MAX) 
{ 
    // if the root is null or the recursion moves 
    // after leaf node it will return false 
    // i.e no dead end. 
    if (!root) 
        return false; 
  
    // if this occurs means dead end is present. 
    if (min == max) 
        return true; 
  
    // heart of the recursion lies here. 
    return deadEnd(root->left, min, root->data - 1) || 
           deadEnd(root->right, root->data + 1, max); 
} 
  
