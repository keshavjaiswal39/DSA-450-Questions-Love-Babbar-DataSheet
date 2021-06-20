class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string str)
    {
        // Your code here
        stack<char> s;
        char x;
        
        for(int i=0;i<str.size();i++)
        {
            if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            {
                s.push(str[i]);
            }
            
            if(s.empty())
            {
                return false;
            }
            
            switch(str[i])
            {
                case ')':
                    x = s.top();
                    s.pop();
                    
                    if(x == '{' || x== '[')
                    {
                        return false;
                    }
                    break;
                
                case '}':
                    x = s.top();
                    s.pop();
                    
                    if(x == '(' || x== '[')
                    {
                        return false;
                    }
                    break;
                    
                case ']':
                    x = s.top();
                    s.pop();
                    
                    if(x == '(' || x== '{')
                    {
                        return false;
                    }
                    break;
            }
        }
        
        return s.empty();
    }

};
