class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *fast = head;
        Node *slow = head;
        
        while(slow!=NULL and fast!=NULL and fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow)
            {
                break;
            }
        }
        
        // Now we have two cases
        // 1. fast and slow points to head
        // 2. fast and slow points to some other node
        
        // case 1
        if(slow == head)
        {
            while(fast->next != slow)
            {
                fast = fast->next;
            }
            fast->next = NULL;
        }
        
        else if(fast == slow)
        {
            // mode slow pointer to head
            slow = head;
            
            while(slow->next != fast->next)
            {
                fast = fast->next;
                slow = slow->next;
            }
            
            fast->next = NULL;
        }
    }
};
