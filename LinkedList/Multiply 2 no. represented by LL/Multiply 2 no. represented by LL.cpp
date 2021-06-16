#define mod 1000000007
long long  multiplyTwoLists (Node* first, Node* second)
{
    long long num1 = 0, num2 = 0;
    while (first || second)
    {
        if(first){
            num1 = ((num1*10)%mod + (first->data)%mod)%mod;
            first = first->next;
        }
        if(second)
        {
            num2 = ((num2*10)%mod + second->data%mod)%mod;
            second = second->next;
        }
    }
 
 
    return (num1%mod*num2%mod)%mod;
}
