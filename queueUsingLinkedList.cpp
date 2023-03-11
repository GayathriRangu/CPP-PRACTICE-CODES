#include <bits/stdc++.h>

using namespace std;

class node
{
	public:
	
	int data;
	node* next;
	
	node(int val)
	{
		data = val;
		next = NULL;
	}
};

class queues
{
	node* front;
	node* back;
	
	public:
	
	queues()
	{
		front = NULL;
		back = NULL;
	}
	
	void empty()
	{
		if(front == NULL)
		{
			cout<<"True"<<endl;
			return;
		}
		
		cout<<"False"<<endl;
	}
	
	int peek()
	{
		if(front == NULL)
		{
			cout<<"Queue underflow."<<endl;
			return -1;
		}
		
		return front -> data;
	}
	
	void enqueue(int val)
	{
		node* newnode = new node(val);
		
		if(front == NULL)
		{
			front = newnode;
			back = newnode;
			return;
		}
		
		back -> next = newnode;
		back = back -> next;
	}
	
	void dequeue()
	{
		node* toDelete;
		
		if(front == NULL)
		{
			cout<<"Queue underflow."<<endl;
			return;
		}
		
		toDelete = front;
		
		front = front -> next;
		
		delete toDelete;
	}
};

int main()
{
	queues q;
	
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	
	cout<<q.peek()<<endl;
	q.dequeue();
	
	cout<<q.peek()<<endl;
	q.dequeue();
	
	cout<<q.peek()<<endl;
	q.dequeue();
	
	cout<<q.peek()<<endl;
	q.dequeue();
	
	q.empty();
}
