class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        // we will first reverse k nodes and then call recursively for the remaining node
        int n = k;
        
        node* curr = head;
        node* prev = NULL;
        
        node* next;
        
        while(curr!=NULL and n>0)
        {
            n--;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Till here my first k nodes are reversed, now after reversing my head becomes the last node so head->next = reverse(remaining node,k) where remaining node will have prev as its head node
        
        if(next!=NULL)
        {
            head->next = reverse(next,k);
        }
        
        return prev;
        
    }
};
