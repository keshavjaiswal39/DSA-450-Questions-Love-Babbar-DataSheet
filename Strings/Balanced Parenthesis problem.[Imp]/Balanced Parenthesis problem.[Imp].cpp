bool ispar(string e)
    {
        // Your code here
        stack<char> s;
        char x;
        
        for(int i=0;i<e.size();i++)
        {
            if(e[i]=='(' || e[i]=='{' || e[i]=='[')
            {
                s.push(e[i]);
                continue;
            }
            
            if(s.empty())
            {
                return false;
            }
            
            if(e[i]==')')
            {
                x=s.top();
                s.pop();
                
                if(x=='{' || x=='[')
                {
                    return false;
                }
            }
            
            if(e[i]=='}')
            {
                x=s.top();
                s.pop();
                
                if(x=='(' || x=='[')
                {
                    return false;
                }
            }
            
            if(e[i]==']')
            {
                x=s.top();
                s.pop();
                
                if(x=='{' || x=='(')
                {
                    return false;
                }
            }
        }
        
        if(s.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};
