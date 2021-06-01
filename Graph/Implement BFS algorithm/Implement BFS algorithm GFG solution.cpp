class Solution 
{
    public:
    //Function to return Breadth First Traversal of given graph.
  	vector<int>bfsOfGraph(int V, vector<int> adj[])
  	{
  	    //boolean list to mark all the vertices as not visited.
	  	vector <bool> vis (V, false);
	    int s = 0;
	    
	    //initially we mark first vertex as visited(true).
	    vis[s] = true; 
	    
	    vector <int> res;
	    
	    //creating a queue for BFS and pushing first vertex in queue.
	    queue<int> q;
	    q.push(s);

	    while (!q.empty()) 
	    {
	        //adding front element in output list and popping it from queue.
	        int t = q.front();
	        res.push_back (t);
	        q.pop();

            //traversing over all the connected components of front element.
	        for (int v :adj[t]) 
	        {
	            //if they aren't visited, we mark them visited and add to queue.
	            if (!vis[v]) 
	            { 
	                vis[v] = true;
	                q.push(v);
	            }
	        }
	    }
	    //returning the output list.
	    return res;
  	}
};
