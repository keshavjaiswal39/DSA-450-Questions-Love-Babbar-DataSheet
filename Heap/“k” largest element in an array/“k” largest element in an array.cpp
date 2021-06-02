class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    vector<int> v;
	    
	    priority_queue<int, vector<int>, greater<int>> p;
	    
	    for(int i=0;i<n;i++)
	    {
	        p.push(arr[i]);
	        
	        if(p.size()>k)
	        {
	            p.pop();
	        }
	    }
	    
	    while(p.size()>0)
	    {
	        v.push_back(p.top());
	        
	        p.pop();
	    }
	    
	    reverse(v.begin(),v.end());
	    return v;
	}

};
