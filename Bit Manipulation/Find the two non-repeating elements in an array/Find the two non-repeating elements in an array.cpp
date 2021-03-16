vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int> v;
        int xor_=0;
        
        for(int i=0;i<nums.size();i++)
        {
            xor_=xor_^nums[i];
        }
        
        int temp=xor_;
        int pos=0;
        
        while((temp&1)!=1)
        {
            pos++;
            temp=temp>>1;
        }
        int x=0;
        int y=0;
        
        int mask=1<<pos;
        
        for(int i=0;i<nums.size();i++)
	    {
		    if((nums[i]&mask)>0)
	    	{
		    	x=x^nums[i];
		    }
    	}
	    y=xor_^x;
	    
	    v.push_back(min(x,y));
	    v.push_back(max(x,y));
	    
	    return v;
    }
