void populateNextRecur(struct node* p, struct node **next_ref)
{
    if (p)
    {
      
        populateNextRecur(p->right, next_ref);
 
        p->next = *next_ref;
 
        *next_ref = p;
 
        populateNextRecur(p->left, next_ref);
    }
}

void populateNext(struct node *root)
{
    
    struct node *next = NULL;
 
    populateNextRecur(root, &next);
}
