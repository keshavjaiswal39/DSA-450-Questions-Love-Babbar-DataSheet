typedef pair<int,pair<int,int> > node;

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> v;
        priority_queue<node, vector<node>, greater<node> > p;
        
        for(int i=0;i<K;i++)
        {
            p.push({arr[i][0],{i,0}});
        }
        
        while(p.size()!=0)
        {
            node current=p.top();
            p.pop();
            
            int element=current.first;
            int x=current.second.first;
            int y=current.second.second;
            
            v.push_back(element);
            
            if(y+1<K)
            {
                p.push({arr[x][y+1],{x,y+1}});
            }
        }
        
        return v;
    }
};
