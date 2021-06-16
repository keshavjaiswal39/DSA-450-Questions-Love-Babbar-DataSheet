class Solution
{
    public:
    Node *compute(Node *head)
    {
        // First reversed the linked list
    
        Node *cur = head;
        Node *prev = NULL;
        Node *next;
    
        while(cur!=NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    
        head = prev;
    
        // Link list is reversed till here
    
        // Computing and deleting the nodes which have larger nodes
        // on the left
    
        Node *current = head;
    
        Node *maxNode = head;
        Node *temp;
    
         while (current != NULL && current->next != NULL)
         {
             if(current->next->data < maxNode->data)
             {
                 temp = current->next;
                 current->next = temp->next;
                 free(temp);
             }
             else
             {
                 current = current->next;
                 maxNode= current;
             }
         }
         
         // reversing list again to get required result :-
         
         cur = head;
         prev = NULL;
         next;
         while(cur!=NULL)
         {
             next = cur->next;
             cur->next = prev;
             prev = cur;
             cur = next;
         }
    
         head = prev;
         
         // head of list can be returned now
    
        return head;
    
    }
};
