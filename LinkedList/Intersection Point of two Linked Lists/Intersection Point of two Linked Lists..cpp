int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node* ptr1 = head1;
    Node* ptr2 = head2;
  
    // If any one of head is NULL i.e
    // no Intersection Point
    if (ptr1 == NULL || ptr2 == NULL) {
  
        return -1;
    }
  
    // Traverse through the lists until they
    // reach Intersection node
    while (ptr1 != ptr2) {
  
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
  
        // If at any node ptr1 meets ptr2, then it is
        // intersection node.Return intersection node.
  
        if (ptr1 == ptr2) {
  
            return ptr1->data;
        }
        /* Once both of them go through reassigning,
        they will be equidistant from the collision point.*/
  
        // When ptr1 reaches the end of a list, then
        // reassign it to the head2.
        if (ptr1 == NULL) {
  
            ptr1 = head2;
        }
        // When ptr2 reaches the end of a list, then
        // redirect it to the head1.
        if (ptr2 == NULL) {
  
            ptr2 = head1;
        }
    }
  
    return ptr1->data;
}
