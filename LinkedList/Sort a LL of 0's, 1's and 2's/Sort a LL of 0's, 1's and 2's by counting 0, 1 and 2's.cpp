//Traverse the list and count the number of 0s, 1s, and 2s. Let the counts be n1, n2, and n3 respectively.
//Traverse the list again, fill the first n1 nodes with 0, then n2 nodes with 1, and finally n3 nodes with 2.

void sortList(Node *head)
{
    int count[3] = {0, 0, 0}; // Initialize count of '0', '1' and '2' as 0
    Node *ptr = head;
 
    /* count total number of '0', '1' and '2'
    * count[0] will store total number of '0's
    * count[1] will store total number of '1's
    * count[2] will store total number of '2's */
    while (ptr != NULL)
    {
        count[ptr->data] += 1;
        ptr = ptr->next;
    }
 
    int i = 0;
    ptr = head;
 
    /* Let say count[0] = n1, count[1] = n2 and count[2] = n3
    * now start traversing list from head node,
    * 1) fill the list with 0, till n1 > 0
    * 2) fill the list with 1, till n2 > 0
    * 3) fill the list with 2, till n3 > 0 */
    while (ptr != NULL)
    {
        if (count[i] == 0)
            ++i;
        else
        {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
}
