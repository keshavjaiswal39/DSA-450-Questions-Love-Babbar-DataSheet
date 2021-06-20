//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    stack<char> s;
    char* ans;
    ans = new char[len];
    for(int i=0;i<len;i++)
    {
        s.push(S[i]);
    }
    
    int i = 0;
    
    while(!s.empty())
    {
        ans[i] = s.top();
        i++;
        s.pop();
    }
    ans[i] = '\0';
    
    return ans;
}
