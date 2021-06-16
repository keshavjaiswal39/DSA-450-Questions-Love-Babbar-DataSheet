//Algo:

//Take Two Fake_heads to take care of odd and even list.
//Put loop on the given LinkedList.
//If the node is odd add it to odd fake_ head list.
//If the node is Even add it to the even fake_head list.
//At the set connect both of the list together and set head to odd list.

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


node *oddEven(node *head)
{
	node *oddHead=NULL;
	node *evenHead=NULL;
	
	while(head!=NULL)
	{
		if(((head->data)&1)==1)
		{
			insertAtTail(oddHead,head->data);
		}
		else
		{
			insertAtTail(evenHead,head->data);
		}
		head=head->next;
	}
	
	if(oddHead==NULL)
	{
		oddHead=evenHead;
	}
	else
	{
		node *temp=oddHead;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=evenHead;
	}
	
	return oddHead;
}



int main()
{
	long long int n;
	int arr[100005];
	cin>>n;
	
	node *head=NULL;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		insertAtTail(head,arr[i]);
	}
	
    node *newHead=oddEven(head);
	Display(newHead);
	
}


