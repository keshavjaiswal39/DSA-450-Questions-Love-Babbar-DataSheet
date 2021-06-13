class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(head->next == NULL or head == NULL)
        {
            return head;
        }
        
        // call recursive function for the remaining linked List that is head->next
        Node *shead = reverseList(head->next);
        
        Node *temp = head->next;
        head->next = NULL;
        temp->next = head;
        
        return shead;
    }
    
};
