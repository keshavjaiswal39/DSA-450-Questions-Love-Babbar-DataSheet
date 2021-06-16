Node* reverseByN(Node* head, int k)
{
    if (!head)
    {
    	return NULL;
	}    
        
    head->prev = NULL;
    Node *temp, *curr = head, *newHead;
    
	int count = 0;
	
    while (curr != NULL && count < k) 
	{
        newHead = curr;
      
	    temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
        count++;
    }
    
    // checking if the reversed LinkedList size is
    // equal to K or not
    // if it is not equal to k that means we have reversed
    // the last set of size K and we don't need to call the
    // recursive function
    if (count >= k) 
	{
        head->next = reverseByN(curr, k);
    }
    
    return newHead;
}
