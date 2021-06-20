void push(stack<int>& s, int a)
{
	s.push(a);
}

bool isFull(stack<int>& s,int n)
{
	if(s.size()==n)
		return true;
	return false;
}

bool isEmpty(stack<int>& s)
{
	if(s.size()==0)
		return true;
	return false;
}

int pop(stack<int>& s)
{
	int a= s.top();
	s.pop();
	return a;
}

int getMin(stack<int>& s)
{
	int m=pop(s);
	while(!isEmpty(s)){
		int n=pop(s);
		if(n<m)
			m=n;
	}
	return m;
}
