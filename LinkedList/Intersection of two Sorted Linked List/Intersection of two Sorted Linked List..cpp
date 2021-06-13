Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *res = NULL;
    Node *temp;
    Node *curr =NULL;
    
    Node *first = head1;
    Node *second = head2;
    
    while(first!=NULL and second!=NULL)
    {
        if(first->data == second->data)
        {
            temp = new Node(first->data);
            
            if(res == NULL)
            {
                res = temp;
            }
            else
            {
                curr->next = temp;
            }
            
            curr = temp;
            
            first = first->next;
            second = second->next;
        }
        
        else if(first->data < second->data)
        {
            first = first->next;  
        }
        
        else
        {
            second = second->next;
        }
    }
    
    return res;
}
