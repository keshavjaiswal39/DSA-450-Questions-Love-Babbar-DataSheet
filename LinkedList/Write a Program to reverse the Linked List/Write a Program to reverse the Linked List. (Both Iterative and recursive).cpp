class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(head == NULL)
        {
            return NULL;
        }
        
        Node *temp = NULL;
        Node *p = head;
        
        while(head!=NULL)
        {
            p = head->next;
            head->next = temp;
            temp = head;
            head = p;
        }
        
        return head = temp;
    }
    
};
