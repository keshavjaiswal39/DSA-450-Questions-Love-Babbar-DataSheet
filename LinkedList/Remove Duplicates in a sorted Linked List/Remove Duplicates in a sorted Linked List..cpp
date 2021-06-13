Node *removeDuplicates(Node *head)
{
 // your code goes here
    Node *first = head;
    Node *second = head->next;
    
    while(second!=NULL)
    {
        if(first->data != second->data)
        {
            first = second;
            second = second->next;
        }
        else
        {
            first->next = second->next;
            delete second;
            second = first->next;
        }
    }
    return head;
}
