void deleteNode(node *&head, int key)
{
	if(head == NULL)
	{
		return;
	}
	
	int x;
	
	// if the list contain only the single node
	if(head->data == key and head->next==head)
	{
		x = head->data;
		delete head;
		return;
	}
	
	node *last = head;
	node *d;
	
	// if the head is to be deleted
	if(head->data == key)
	{
		while(last->next != head)
		{
			last = last->next;		
		}
		
		last->next = head->next;
		x = head->data;
		delete head;
		
		head = last->next;	
	}
	
	// either the node to be deleted is not found or the end of the linkedlist is not reached
	while(last->next!=head and last->next->data!=key)
	{
		last = last->next;
	}
	
	// if the node to be deleted is found
	if(last->next->data = key)
	{
		d = last->next;
		last->next = d->next;
		delete d;
	}
	
	else
	{
		cout<<"No such key found in the list";
	}
}
