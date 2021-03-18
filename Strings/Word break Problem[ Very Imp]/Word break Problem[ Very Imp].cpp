unordered_map<string,int> dp;

int solve(string s,vector<string> &b)
{
	int len=s.size();
	
	if(len==0)
	{
		return 1;
	}
	
	if(dp[s]!=0)
	{
		return dp[s];
	}
	
	for(int i=1;i<=len;i++)
	{
		int flag=0;
		string search=s.substr(0,i);
		
		for(int j=0;j<b.size();j++)
		{
			if(search.compare(b[j])==0)
			{
				flag=1;
				break;
			}
		}
		
		if(flag==1 and solve(s.substr(i,len-i),b)==1)
		{
			return dp[s]=1;
		}
	}
	return dp[s]=-1;
}

int wordBreak(string A,vector<string> &B)
{
	int x=solve(A,B);
	
	if(x==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}














