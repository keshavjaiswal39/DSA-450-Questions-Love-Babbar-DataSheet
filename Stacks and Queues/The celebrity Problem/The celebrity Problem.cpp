class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    bool knows(int a, int b, vector<vector<int> >& M)
    {
        return M[a][b];
    }
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here
        stack<int> s;
        
        // celebrity
        int C;
        
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }
        
        // Ecxtract top 2
        
        // Find the potential celebrity
        while(s.size()>1)
        {
            int A = s.top();
            s.pop();
            
            int B = s.top();
            s.pop();
            
            if(knows(A, B, M))
            {
                s.push(B);
            }
            else
            {
                s.push(A);
            }
        }
        
        // If there are only two people 
        // and there is no
        // potential candicate
        if(s.empty())
        {
            return -1;
        }
        
        // Potential Candidate or not?
        C = s.top();
        s.pop();
        
        // check if C is actually a celebrity or not
        for(int i = 0; i<n;i++)
        {
            if( (i!=C) and ( knows(C,i,M) or !knows(i,C,M) ) )
            {
                return -1;
            }
        }
        
        return C;
    }
};
