#include<iostream>
#include<list>
#include<climits>

using namespace std;

class Graph{
	int v;
	list<int> *adj;
	
	bool isCyclic(int v,bool visited[],int parent)
	{
		visited[v]=true;
		
		for(auto i=adj[v].begin();i!=adj[v].end();i++)
		{
			if(!visited[*i])
			{
				if(isCyclic(*i,visited,v))
				{
					return true;
				}
			}
			else if(*i!=parent)
			{
				return true;
			}
		}
		return false;
	}
	
	public:
		Graph(int V)
		{
			this->v=v;
			adj=new list<int> [v];
		}
		
		void addEdge(int v,int w)
		{
			adj[v].push_back(w);  // add w to the v's list
			adj[w].push_back(v);  // add v to the w's list
		}
		
		bool isTree()
		{
			bool *visited=new bool[v];
			
			for(int i=0;i<v;i++)
			{
				visited[i]=false;
			}
			
			if(isCyclic(0,visited,-1))
			{
				return false;
			}
			
			for(int u=0;u<v;u++)
			{
				if(!visited[u])
				{
					return false;
				}
			}
			
			return true;
		}
};

int main()
{
	Graph g1(5);
	g1.addEdge(1,0);
	g1.addEdge(0,2);
	g1.addEdge(0,3);
	g1.addEdge(3,4);
	
	g1.isTree()?cout<<"Its a tree\n":cout<<"Its not a tree\n";
}












