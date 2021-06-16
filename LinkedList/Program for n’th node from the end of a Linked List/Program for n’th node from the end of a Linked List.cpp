#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
		
		// Constructor
		node(int d)
		{
			data=d;
			next=NULL;
		}
};

void insertAtTail(node *&head,int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	node *tail=head;
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	tail->next=new node(data);
	return;
}

void Display(node *head)
{
	if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    Display(head->next);
}

node *kthpoint(node *head,int k)
{
	if(head==NULL or head->next==NULL)
	{
		return head;
	}
	node *slow=head;
	node *fast=head;
	
	while(--k)
	{
		fast=fast->next;
	}
	
	while(fast->next!=NULL)
	{
		fast=fast->next;
		slow=slow->next;
	}
	return slow;
}

int main()
{
	int n;
	cin>>n;
	
	node *head=NULL;
	
	while(n!=-1)
	{
		insertAtTail(head,n);
		cin>>n;
	}
	
	int k;
	cin>>k;

	node *kth=kthpoint(head,k);
	cout<<kth->data;
	
}


