/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
   // Your code here
   if(head == NULL)
   {
       return true;
   }
   
   Node *top = head->next;
   
   while(top != NULL and top != head)
   {
       top = top->next;
   }
    
    return top==head;
}

