class Solution
{
    public:
    double median;
    
    //using two priority queues.
    priority_queue<int> max; 
	priority_queue<int, vector<int>, greater<int> > min;
		
	//Function to insert heap.
    void insertHeap(int &x)
    {
        //inserting the element.
    	if (max.empty()) 
    		max.push(x);
    	else if (x > max.top()) 
    		min.push(x);
    	else if(min.empty())
    	{
    		min.push(max.top());
    		max.pop();
    		max.push(x);
    	}
    	else
    		max.push(x);
    		
    	//calling function to balance heaps.
    	balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
    	if (abs(max.size() - min.size()) > 1) 
    	{
    	    //if size of max queue is greater than min queue, we pop top 
    	    //element from max queue and push it in min queue.
    		if (max.size() > min.size())
    		{
    			min.push(max.top());
    			max.pop();
    		}
    		//else we pop top element from min queue and push it in max queue.
    		else
    		{
    			max.push(min.top());
    			min.pop();
    		}
    	}
    }
    
    //Function to return Median.
    double getMedian()
    {
        //if total size is even.
    	if ((max.size() + min.size()) % 2 == 0)
    	{
    	    //we store the sum of top elements of both priority
    	    //queues and divide it by 2.
    		median = (max.top() + min.top());
    		median /= 2;
    	}
    	//else the total size is odd.
    	else 
    	{
    	    //if min queue is empty or max queue is bigger than min queue,
    	    //we store top element of max queue in median else we store
    	    //top element of min queue.
    		if (min.empty())
    			median = max.top();
    		else if (min.size() < max.size())
    			median = max.top();
    		else
    			median = min.top();
    	}
    	
    	//returning the median.
    	return median;
    }
};
