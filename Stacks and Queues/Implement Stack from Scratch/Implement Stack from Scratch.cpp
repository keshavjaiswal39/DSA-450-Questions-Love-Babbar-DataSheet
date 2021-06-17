#include<bits/stdc++.h>
using namespace std;

class Stack
{
	private:
		vector<int> v;
	public:
		void push(int d)
		{
			v.push_back(d);
		}	
		
		bool empty()
		{
			return v.size() == 0;
		}
		
		void pop()
		{
			if(!empty())
			{
				v.pop_back();
			}
		}
		
		int top()
		{
			return v[v.size()-1];
		}
};

int main()
{
	Stack s;
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		
		s.push(num);
	}
	
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
	
	return 0;
	
}
