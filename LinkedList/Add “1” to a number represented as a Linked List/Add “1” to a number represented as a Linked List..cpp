class Solution
{
    public:
    
    Node*  reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        
        Node *next;
        
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    Node* addOne_helper(Node *head)
    {
        // res is head node of the resultant list
        Node* res = head;
        Node *temp, *prev = NULL;
     
        int carry = 1, sum;
     
        while (head != NULL) //while both lists exist
        {
            // Calculate value of next digit in resultant list.
            // The next digit is sum of following things
            // (i) Carry
            // (ii) Next digit of head list (if there is a
            // next digit)
            sum = carry + head->data;
     
            // update carry for next calulation
            carry = (sum >= 10)? 1 : 0;
     
            // update sum if it is greater than 10
            sum = sum % 10;
     
            // Create a new node with sum as data
            head->data = sum;
     
            // Move head and second pointers to next nodes
            temp = head;
            head = head->next;
        }
     
        // if some carry is still there, add a new node to
        // result list.
        if (carry > 0)
            temp->next = new Node(carry);
     
        // return head of the resultant list
        return res;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        
        // first we will reverse the array
        head = reverse(head);
        
        // now add 1 from left node and if its greater then 9 then take carry and starting adding to the next node
        head = addOne_helper(head);
        
        // return the modified linked list
        return reverse(head);
    }
};
