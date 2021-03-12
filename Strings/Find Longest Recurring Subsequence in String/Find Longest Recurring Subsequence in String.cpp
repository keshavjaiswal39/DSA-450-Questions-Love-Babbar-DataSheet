class Solution {
	public:
	    
	    int Helper(string a,string b)
	    {
	        int dp[a.size()+1][b.size()+1];
	        
	        for(int i=0;i<a.size()+1;i++)
	        {
	            for(int j=0;j<b.size()+1;j++)
	            {
	                if(i==0 || j==0)
    	                dp[i][j]=0;
	            }
	        }
	        
	        for(int i=1;i<a.size()+1;i++)
	        {
	            for(int j=1;j<b.size()+1;j++)
	            {
	                if(a[i-1]==b[j-1] and i!=j)
	                {
	                    dp[i][j]=dp[i-1][j-1]+1;
	                }
	                else
	                {
	                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	                }
	            }
	        }
	        
	        return dp[a.size()][b.size()];
	        
	    }
	
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    string s1=str;
		    string s2=str;
		    
		    return Helper(s1,s2);
		    
		}

};
