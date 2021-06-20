class Solution 
{
    public:
    	
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
	            
	            if(M[A][B] == 1)
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
	        // potential candidate
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
	            if(i != C)
	            {
	            	if(M[i][C] == 0 || M[C][i] == 1)
		            {
		                return -1;
		            }
				}
	        }
	        
	        return C;
	    }
};
