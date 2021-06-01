#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
	map<T, list<pair<T,int> > > l;   // here int is distance or weight
	
	public:
		void addEdge(T x, T y,int dist,bool bidirec)
		{
			l[x].push_back(make_pair(y,dist));
			if(bidirec)
			{
				l[y].push_back(make_pair(x,dist));
			}
		}
		
		void print()
		{
			for(auto x:l)
			{
				T city=x.first;
				list<pair<T,int> > nbrs = x.second;
				
				cout<<city<<"-> ";
				for(auto a:nbrs)
				{
					T dest = a.first;
					int dist=a.second;
					
					cout<<"( "<<a.first<<", "<<a.second<<" )";
				}
				cout<<endl;
			}
		}
		
};

int main()
{
	Graph<char> g;
	g.addEdge('0', '1',4, 0);
	g.addEdge('0', '7',8, 0);
	g.addEdge('1', '7',11, 0);
	g.addEdge('1', '2',8, 0);
	g.addEdge('7', '8',7, 0);
	g.addEdge('2', '8',2, 0);
	g.addEdge('8', '6',6, 0);
	g.addEdge('2', '5',4, 0);
	g.addEdge('6', '5',2, 0);
	g.addEdge('2', '3',7, 0);
	g.addEdge('3', '3',14, 0);
	g.addEdge('3', '4',9, 0);
	g.addEdge('5', '4',10, 0);
	g.addEdge('7', '6',1, 0);
	
	g.print();
	
	return 0;
}
