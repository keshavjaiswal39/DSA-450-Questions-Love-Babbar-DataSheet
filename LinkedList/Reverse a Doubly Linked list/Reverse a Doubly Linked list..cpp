Node* reverseDLL(Node * head)
{
    //Your code here
    if(head == NULL || head->next == NULL)
    return head;
    
    Node *prev = NULL, *curr = head;
    
    while(curr != NULL)
    {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    
    return prev->prev;
}
