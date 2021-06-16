node* sortAKSortedDLL(node* head, int k)
{
    // if list is empty
    if (head == NULL)
        return head;
 
    // priority_queue 'pq' implemented as min heap with the
    // help of 'compare' function
    // Min-Heap
    priority_queue<node*, vector<node*>, compare> pq;
 
    node* newHead = NULL;
	node* last;
 
    // Create a Min Heap of first (k+1) elements from
    // input doubly linked list
    for (int i = 0; head != NULL && i <= k; i++) {
        // push the node on to 'pq'
        pq.push(head);
 
        // move to the next node
        head = head->next;
    }
 
    // loop till there are elements in 'pq'
    while (!pq.empty()) {
 
        // place root or top of 'pq' at the end of the
        // result sorted list so far having the first node
        // pointed to by 'newHead'
        // and adjust the required links
        if (newHead == NULL) 
		{
            newHead = pq.top();
            newHead->prev = NULL;
 
            // 'last' points to the last node
            // of the result sorted list so far
            last = newHead;
        }
 
        else 
		{
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }
 
        // remove element from 'pq'
        pq.pop();
 
        // if there are more nodes left in the input list
        if (head != NULL) {
            // push the node on to 'pq'
            pq.push(head);
 
            // move to the next node
            head = head->next;
        }
    }
 
    // making 'next' of last node point to NULL
    last->next = NULL;
 
    // new head of the required sorted DLL
    return newHead;
}
 
