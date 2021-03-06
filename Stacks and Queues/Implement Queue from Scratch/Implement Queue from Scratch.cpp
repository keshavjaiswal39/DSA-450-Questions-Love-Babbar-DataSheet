#include<bits/stdc++.h>
using namespace std;

class Queue 
{
	private:
		int *arr;
		int front, rear, current_size, max_size;
		
	public:
		Queue(int size)
		{
			arr = new int[size];
			current_size = 0;
			max_size = size;
			front = 0;
			rear = max_size-1;
		}
		
		bool full()
		{
			return current_size == max_size;
		}
		
		bool empty()
		{
			return current_size == 0;
		}
		
		void push(int data)
		{
			if(!full())
			{
				rear = (rear+1)%max_size;
				arr[rear] = data;
				current_size++;
			}
		}
		
		void pop()
		{
			if(!empty())
			{
				front = (front+1)%max_size;
				current_size--;
			}
		}
		
		int Front()
		{
			return arr[front];
		}
		
		~Queue()
		{
			if(arr!=NULL)
			{
				delete[] arr;
				arr = NULL;
			}
		}
	
};

int main()
{
	Queue q(6);
	
	for(int i=1;i<6;i++)
	{
		q.push(i);
	}
	
	q.pop();
	q.pop();
	
	q.push(7);
	
	while(!q.empty())
	{
		cout<<q.Front()<<" ";
		q.pop();
	}
	
}



