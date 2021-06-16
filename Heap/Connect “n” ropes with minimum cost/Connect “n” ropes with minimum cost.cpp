class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
        long long minCost(long long arr[], long long n) 
        {
            // Your code here
            priority_queue<long long, vector<long long>, greater<long long> > pq(arr,arr+n);
        	
        	long long cost=0;
        	
        	while(pq.size() > 1)
        	{
        		long long A=pq.top();
        		pq.pop();
        		
        		long long B=pq.top();
        		pq.pop();
        		
        		long long new_cost=A+B;
        		cost+=new_cost;
        		pq.push(new_cost);
        	}
        	
        	return cost;
        }
};
